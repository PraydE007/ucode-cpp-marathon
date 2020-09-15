cmake_minimum_required(VERSION 3.16.3...3.18.2)

add_compile_options(
    -std=c++17
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    -pthread
)

set(CPPS
    Worker.cpp
    Log.cpp
    LoggerWorker.cpp
)

find_package(Threads)
add_library(lib ${CPPS})
target_link_libraries(lib ${CMAKE_THREAD_LIBS_INIT})
