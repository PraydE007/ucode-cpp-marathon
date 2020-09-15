cmake_minimum_required(VERSION 3.16.3)

add_compile_options(
    -std=c++17
    -Werror
    -Wall
    -Wextra
    -Wpedantic
)

set(BIN "tesLibrary")
set(SRCS "main.cpp")
set(SUBDIR "src")

project(${BIN})
include_directories(${SUBDIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

add_executable(${BIN} ${SRCS})
add_subdirectory(${SUBDIR})
target_link_libraries(${BIN} ${SUBDIR})
