cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SRCS "visitAll.cpp")

project(src)

add_library(src STATIC ${SRCS})
