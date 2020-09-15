cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(BIN "inventory")
set(SRCS "main.cpp")
set(SUBDIR "src")

project(${BIN})
include_directories(${SUBDIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

add_executable(${BIN} ${SRCS})
add_subdirectory(${SUBDIR})
target_link_libraries(${BIN} ${SUBDIR})
