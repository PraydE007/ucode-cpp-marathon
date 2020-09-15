cmake_minimum_required(VERSION 3.16.3)

set(CPPS
    Creature.cpp
    Werewolf.cpp
)

add_library(src STATIC ${CPPS})
