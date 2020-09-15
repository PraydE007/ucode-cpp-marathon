cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

add_compile_options(
    -std=c++17
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)

set(CPPS
    main.cpp
)

add_executable(${PROJECT_NAME} ${CPPS})

add_subdirectory(src)
include_directories(src)
target_link_libraries(${PROJECT_NAME} dragon)
