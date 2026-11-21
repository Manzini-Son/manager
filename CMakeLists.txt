cmake_minimum_required(VERSION 3.21)
project(manager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Slint REQUIRED)

add_executable(manager_cli main.cpp)

add_executable(manager src/mainwindow.cpp)
slint_target_sources(manager ui/mainwindow.slint)
target_link_libraries(manager PRIVATE Slint::Slint)
target_compile_definitions(manager PRIVATE "MANAGER_PATH=\"$<TARGET_FILE:manager_cli>\"")
add_dependencies(manager manager_cli)

