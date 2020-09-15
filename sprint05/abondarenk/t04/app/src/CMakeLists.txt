cmake_minimum_required(VERSION 3.16.3)

set(CPPS
    Soldier.cpp
    ImperialSoldier.cpp
    StormcloakSoldier.cpp
    Weapon.cpp
    Axe.cpp
    Sword.cpp
)

add_library(src STATIC ${CPPS})
