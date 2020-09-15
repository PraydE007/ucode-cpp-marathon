cmake_minimum_required(VERSION 3.16.3...3.18.2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

add_compile_options(
    -std=c++17
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    -pthread
)

set(CPPS
    main.cpp
)

find_package(Threads)
add_executable(${PROJECT_NAME} ${CPPS})
include_directories(src)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
