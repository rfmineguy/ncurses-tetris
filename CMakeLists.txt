cmake_minimum_required(VERSION 3.10)

project(curses-demo)

set(CMAKE_CXX_STANDARDREQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

find_package(Curses REQUIRED)

set (SOURCES
    src/main.cpp
    src/game.cpp
    src/menu.cpp
    src/tetriminos/tetrimino.cpp
    src/tetriminos/L.cpp
    src/tetriminos/I.cpp
    src/tetriminos/T.cpp
    src/tetriminos/square.cpp
    )

include_directories(curses-demo ${CURSES_INCLUDE_DIRS})

add_executable(curses-demo ${SOURCES})

target_link_libraries(curses-demo ${CURSES_LIBRARIES})
