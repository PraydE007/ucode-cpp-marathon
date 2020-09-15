cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SRCS "inventory.cpp")

project(src)

add_library(src STATIC ${SRCS})
