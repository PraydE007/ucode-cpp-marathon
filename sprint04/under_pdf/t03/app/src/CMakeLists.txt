cmake_minimum_required(VERSION 3.16.3)

set(CPPS
    calculator.cpp
)

add_library(calculator STATIC ${CPPS})
