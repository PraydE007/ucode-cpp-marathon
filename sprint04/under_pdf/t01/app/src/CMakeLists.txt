cmake_minimum_required(VERSION 3.16.3)

set(CPPS
    Axe.cpp
    ImperialSoldier.cpp
    StormcloakSoldier.cpp
    Sword.cpp
)

add_library(soldiers STATIC ${CPPS})
