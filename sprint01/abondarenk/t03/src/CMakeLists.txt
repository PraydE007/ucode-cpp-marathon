cmake_minimum_required(VERSION 3.16.3)

add_compile_options(
    -std=c++17
    -Werror
    -Wall
    -Wextra
    -Wpedantic
)

set(SRCS "rabbits.cpp")

project(src)

add_library(src STATIC ${SRCS})
