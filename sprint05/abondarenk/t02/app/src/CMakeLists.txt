cmake_minimum_required(VERSION 3.16.3)

set(CPPS
    draugr.cpp
)

add_library(lib STATIC ${CPPS})
