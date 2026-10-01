#include <QApplication>
#include <QDateTime>
#include <QFile>
#include <QFontDatabase>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPainter>
#include <QProcess>
#include <QPushButton>
#include <QRadialGradient>
#include <QRegularExpression>
#include <QStandardPaths>
#include <QTextCursor>
#include <QTextEdit>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <cmath>

#ifndef MANAGER_PATH
#define MANAGER_PATH "./manager"
#endif

class AuroraBackground final : public QWidget {
public:
    explicit AuroraBackground(QWidget *parent = nullptr) : QWidget(parent) {
        auto *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, [this] {
            phase_ += 0.012;
            update();
        });
        timer->start(40);
    }

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        painter.fillRect(rect(), QColor("#071724"));

        const qreal w = width();
        const qreal h = height();
        const QPointF centers[] = {
            {w * (0.25 + 0.05 * std::sin(phase_)), h * 0.25},
            {w * (0.73 + 0.06 * std::cos(phase_ * 0.8)), h * 0.42},
            {w * 0.48, h * (0.82 + 0.04 * std::sin(phase_ * 0.6))}
        };
        const QColor colors[] = {
            QColor(25, 190, 160, 95),
            QColor(45, 115, 190, 105),
            QColor(70, 205, 145, 65)
        };

        for (int i = 0; i < 3; ++i) {
            QRadialGradient glow(centers[i], qMax(w, h) * 0.52);
            glow.setColorAt(0.0, colors[i]);
            glow.setColorAt(1.0, QColor(colors[i].red(), colors[i].green(),
                                        colors[i].blue(), 0));
            painter.fillRect(rect(), glow);
        }
    }

private:
    qreal phase_ = 0.0;
};

class managerWindow final : public QMainWindow {
public:
    managerWindow() {
        setWindowTitle("Manager v1.0.0");
        resize(900, 650);

        auto *background = new AuroraBackground;
        auto *layout = new QVBoxLayout(background);
        layout->setContentsMargins(38, 32, 38, 32);
        layout->setSpacing(14);

        auto *title = new QLabel("Manager v1.0.0", background);
        title->setStyleSheet(
            "color: #e8fff8; font-size: 28px; font-weight: 700;"
            " letter-spacing: 4px; background: transparent;");
        layout->addWidget(title);

        output_ = new QTextEdit(background);
        output_->setReadOnly(true);
        output_->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
        output_->setStyleSheet(
            "QTextEdit { color: #d7f5ec; background: rgba(5, 18, 29, 190);"
            " border: 1px solid rgba(142, 235, 210, 90); border-radius: 14px;"
            " padding: 18px; selection-background-color: #268b7b; }");
        layout->addWidget(output_, 1);

        auto *bottom = new QWidget(background);
        auto *bottomLayout = new QHBoxLayout(bottom);
        bottomLayout->setContentsMargins(0, 0, 0, 0);

        input_ = new QLineEdit(bottom);
        input_->setPlaceholderText("Type here...");
        input_->setStyleSheet(
            "QLineEdit { color: #effffb; background: rgba(5, 18, 29, 210);"
            " border: 1px solid rgba(142, 235, 210, 110); border-radius: 10px;"
            " padding: 12px; font-size: 15px; }");

        auto *send = new QPushButton("Enter", bottom);
        send->setStyleSheet(
            "QPushButton { color: #06221e; background: #7de2c4;"
            " border: 0; border-radius: 10px; padding: 12px 22px;"
            " font-weight: 700; }"
            "QPushButton:hover { background: #a3f3d9; }");

        bottomLayout->addWidget(input_, 1);
        bottomLayout->addWidget(send);
        layout->addWidget(bottom);

        setCentralWidget(background);

        process_.setProcessChannelMode(QProcess::MergedChannels);
        connect(&process_, &QProcess::readyRead, this, [this] {
            appendOutput(QString::fromLocal8Bit(process_.readAll()));
        });
        connect(input_, &QLineEdit::returnPressed, this, [this] { sendInput(); });
        connect(send, &QPushButton::clicked, this, [this] { sendInput(); });
        connect(&process_, &QProcess::finished, this, [this](int exitCode, QProcess::ExitStatus) {
            appendOutput(QString("\n[Manager process ended with code %1]\n").arg(exitCode));
            input_->setEnabled(false);
        });

        QString cliPath = QString::fromUtf8(MANAGER_PATH);
        const QString localCli = QApplication::applicationDirPath() + "/manager_cli";
        if (QFile::exists(localCli)) {
            cliPath = localCli;
        }

        const QString stdbuf = QStandardPaths::findExecutable("stdbuf");
        if (!stdbuf.isEmpty()) {
            process_.start(stdbuf, {"-oL", "-eL", cliPath});
        } else {
            process_.start(cliPath);
        }

        if (!process_.waitForStarted()) {
            appendOutput(QString("Could not start the Manager application console process at: %1\n").arg(cliPath));
            input_->setEnabled(false);
        }
    }

private:
    void sendInput() {
        const QString inputText = input_->text();
        const QByteArray text = inputText.toLocal8Bit() + '\n';
        if (process_.state() == QProcess::Running) {
            process_.write(text);
        }
        appendOutput(inputText + '\n');
        input_->clear();
    }

    void appendOutput(const QString &text) {
        static const QRegularExpression ansi("\x1b\\[[0-9;]*[A-Za-z]");
        QString clean = QString(text).remove(ansi);
        // Also remove any rogue bell or control chars if present
        clean.remove('\1');
        output_->moveCursor(QTextCursor::End);
        output_->insertPlainText(clean);
        output_->ensureCursorVisible();
    }

    QTextEdit *output_ = nullptr;
    QLineEdit *input_ = nullptr;
    QProcess process_;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    managerWindow window;
    window.show();
    return app.exec();
}
