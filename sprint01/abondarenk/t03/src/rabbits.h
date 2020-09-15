#ifndef RABBITS_SRC_RABBITS_H_
#define RABBITS_SRC_RABBITS_H_

#include <iostream>
#include <list>
#include <cstdlib>

// for sleep
#include <chrono>
#include <thread>

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};

void outputStats(std::list<Rabbit>& lst);
void addAge(std::list<Rabbit>& lst);
void spawnRabbit(std::list<Rabbit>& lst);
void vampiresAttack(std::list<Rabbit>& lst);
void reproduction(std::list<Rabbit>& lst);
void deathSystem(std::list<Rabbit>& lst);

#endif // RABBITS_SRC_RABBITS_H_
