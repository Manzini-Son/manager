#include "mainwindow.h"

#include <slint.h>

#include <array>
#include <cerrno>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <signal.h>
#include <string>
#include <string_view>
#include <system_error>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef MANAGER_PATH
#define MANAGER_PATH "./manager_cli"
#endif

namespace {

std::string managerPath()
{
    std::array<char, 4096> executablePath{};
    const auto pathLength = readlink("/proc/self/exe", executablePath.data(),
                                     executablePath.size() - 1);
    if (pathLength > 0) {
        const auto localCli = std::filesystem::path(
                                  std::string(executablePath.data(), pathLength))
                                  .parent_path() /
                              "manager_cli";
        if (access(localCli.c_str(), X_OK) == 0) {
            return localCli.string();
        }
    }
    return MANAGER_PATH;
}

class ManagerProcess
{
public:
    ManagerProcess() = default;
    ManagerProcess(const ManagerProcess &) = delete;
    ManagerProcess &operator=(const ManagerProcess &) = delete;

    ~ManagerProcess()
    {
        if (inputFd_ >= 0) {
            close(inputFd_);
        }
        if (outputFd_ >= 0) {
            close(outputFd_);
        }
        if (pid_ > 0) {
            kill(pid_, SIGTERM);
            waitpid(pid_, nullptr, 0);
        }
    }

    void start(const std::string &path)
    {
        int inputPipe[2];
        int outputPipe[2];
        if (pipe(inputPipe) != 0) {
            throw std::system_error(errno, std::generic_category(), "create manager input pipe");
        }
        if (pipe(outputPipe) != 0) {
            const int error = errno;
            close(inputPipe[0]);
            close(inputPipe[1]);
            throw std::system_error(error, std::generic_category(), "create manager output pipe");
        }

        pid_ = fork();
        if (pid_ < 0) {
            const int error = errno;
            close(inputPipe[0]);
            close(inputPipe[1]);
            close(outputPipe[0]);
            close(outputPipe[1]);
            throw std::system_error(error, std::generic_category(), "start manager process");
        }

        if (pid_ == 0) {
            dup2(inputPipe[0], STDIN_FILENO);
            dup2(outputPipe[1], STDOUT_FILENO);
            dup2(outputPipe[1], STDERR_FILENO);
            close(inputPipe[0]);
            close(inputPipe[1]);
            close(outputPipe[0]);
            close(outputPipe[1]);
            execlp("stdbuf", "stdbuf", "-oL", "-eL", path.c_str(),
                   static_cast<char *>(nullptr));
            execl(path.c_str(), path.c_str(), static_cast<char *>(nullptr));
            _exit(127);
        }

        close(inputPipe[0]);
        close(outputPipe[1]);
        inputFd_ = inputPipe[1];
        outputFd_ = outputPipe[0];
        const int flags = fcntl(outputFd_, F_GETFL, 0);
        if (flags < 0 || fcntl(outputFd_, F_SETFL, flags | O_NONBLOCK) < 0) {
            const int error = errno;
            throw std::system_error(error, std::generic_category(),
                                    "configure manager output pipe");
        }
    }

    bool send(const std::string &text)
    {
        if (inputFd_ < 0) {
            return false;
        }
        const std::string line = text + '\n';
        std::size_t written = 0;
        while (written < line.size()) {
            const auto result = write(inputFd_, line.data() + written, line.size() - written);
            if (result < 0 && errno == EINTR) {
                continue;
            }
            if (result <= 0) {
                close(inputFd_);
                inputFd_ = -1;
                return false;
            }
            written += static_cast<std::size_t>(result);
        }
        return true;
    }

    std::string readAvailable()
    {
        std::string output;
        std::array<char, 4096> buffer{};
        while (outputFd_ >= 0) {
            const auto count = read(outputFd_, buffer.data(), buffer.size());
            if (count > 0) {
                output.append(buffer.data(), static_cast<std::size_t>(count));
            } else if (count == 0) {
                close(outputFd_);
                outputFd_ = -1;
            } else if (errno == EINTR) {
                continue;
            } else if (errno != EAGAIN && errno != EWOULDBLOCK) {
                const int error = errno;
                close(outputFd_);
                outputFd_ = -1;
                throw std::system_error(error, std::generic_category(),
                                        "read manager output");
            } else {
                break;
            }
        }
        return removeTerminalControls(output);
    }

    int exitCode()
    {
        if (pid_ <= 0) {
            return -1;
        }
        int status = 0;
        const auto result = waitpid(pid_, &status, WNOHANG);
        if (result == 0 || (result < 0 && errno == EINTR)) {
            return -1;
        }
        if (result < 0) {
            throw std::system_error(errno, std::generic_category(), "wait for manager process");
        }
        pid_ = -1;
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
        if (WIFSIGNALED(status)) {
            return 128 + WTERMSIG(status);
        }
        return -1;
    }

    void closeInput()
    {
        if (inputFd_ >= 0) {
            close(inputFd_);
            inputFd_ = -1;
        }
    }

private:
    std::string removeTerminalControls(const std::string &text)
    {
        std::string clean;
        clean.reserve(text.size());
        for (const unsigned char character : text) {
            if (ansiState_ == 1) {
                ansiState_ = character == '[' ? 2 : 0;
                continue;
            }
            if (ansiState_ == 2) {
                if (character >= 0x40 && character <= 0x7e) {
                    ansiState_ = 0;
                }
                continue;
            }
            if (character == 0x1b) {
                ansiState_ = 1;
            } else if (character == '\n' || character == '\r' ||
                       character == '\t' || character >= 0x20) {
                clean.push_back(static_cast<char>(character));
            }
        }
        return clean;
    }

    pid_t pid_ = -1;
    int inputFd_ = -1;
    int outputFd_ = -1;
    int ansiState_ = 0;
};

void appendOutput(const MainWindow &window, const std::string &text)
{
    const auto current = window.get_output_text();
    std::string combined(current.data(), current.size());
    combined += text;
    window.set_output_text(slint::SharedString(std::string_view(combined)));
}

} // namespace

int main()
{
    signal(SIGPIPE, SIG_IGN);
    auto window = MainWindow::create();
    ManagerProcess process;
    bool processRunning = false;

    try {
        process.start(managerPath());
        processRunning = true;
    } catch (const std::system_error &error) {
        const std::string message = "Could not start the Manager application console process: ";
        appendOutput(*window, message + error.what() + '\n');
        std::cerr << message << error.what() << '\n';
        window->set_input_enabled(false);
    }

    window->on_submit([&window, &process](slint::SharedString input) {
        const std::string text(input.data(), input.size());
        if (process.send(text)) {
            appendOutput(*window, text + '\n');
        } else {
            appendOutput(*window, "Could not send input to the Manager process.\n");
            window->set_input_enabled(false);
        }
        window->set_input_text("");
    });

    slint::Timer processTimer;
    if (processRunning) {
        processTimer.start(slint::TimerMode::Repeated, std::chrono::milliseconds(40),
                           [&window, &process, &processRunning, &processTimer] {
                               try {
                                   appendOutput(*window, process.readAvailable());
                                   if (processRunning) {
                                       const int exitCode = process.exitCode();
                                       if (exitCode >= 0) {
                                           appendOutput(*window, "\n[Manager process ended with code " +
                                                                     std::to_string(exitCode) + "]\n");
                                           window->set_input_enabled(false);
                                           process.closeInput();
                                           processRunning = false;
                                           processTimer.stop();
                                       }
                                   }
                               } catch (const std::system_error &error) {
                                   appendOutput(*window, "\n[Manager process I/O error: " +
                                                             std::string(error.what()) + "]\n");
                                   std::cerr << "Manager process I/O error: " << error.what() << '\n';
                                   window->set_input_enabled(false);
                                   process.closeInput();
                                   processRunning = false;
                                   processTimer.stop();
                               }
                           });
    }

    window->run();
    return 0;
}
