cmake_minimum_required(VERSION 3.18.2)

set(CONTAINERS_SRCS
    "Containers/Barrel.cpp"
    "Containers/Chest.cpp"
    "Containers/Container.cpp"
    "Containers/Safe.cpp"
)

set(PLAYER_SRCS
    "Player/Player.cpp"
)

set(CPPS
    ${CONTAINERS_SRCS}
    ${PLAYER_SRCS}
)

include_directories(".")
project("libLockpicking" VERSION 0.1 LANGUAGES CXX)
add_library("libLockpicking" ${CPPS})
target_include_directories("libLockpicking" PUBLIC ${PROJECT_BINARY_DIR})
