cmake_minimum_required(VERSION 3.16.3)

add_compile_options(
    -std=c++17
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)

set(CPPS
    calculator.cpp
)

add_library(calculator STATIC ${CPPS})
