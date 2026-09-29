cmake_minimum_required(VERSION 3.16)
project(manager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(manager_cli main.cpp)

add_executable(manager src/mainwindow.cpp)
target_link_libraries(manager PRIVATE Qt6::Widgets)
target_compile_definitions(manager PRIVATE "MANAGER_PATH=\"$<TARGET_FILE:manager_cli>\"")
add_dependencies(manager manager_cli)

