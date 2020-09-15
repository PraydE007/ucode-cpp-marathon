cmake_minimum_required(VERSION 3.18.2)

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

include_directories("src")
add_executable(${PROJECT_NAME} ${CPPS})
add_subdirectory("src")
target_link_libraries(${PROJECT_NAME} "libLockpicking")
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../..)
