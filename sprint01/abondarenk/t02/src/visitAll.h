#ifndef VISITALL_SRC_VISITALL_H_
#define VISITALL_SRC_VISITALL_H_

#include <iostream>
#include <deque>
#include <string>

#define USAGE "usage: ./visitAll [[name,stamina,distance] ...]"

#define ARGV1 "Argument "
#define ARGV2 " is not valid"

#define M_IMPO "Mission: Impossible"

struct Town {
    int id;
    std::string name;
    int stamina;
    int distance;
};

bool validate(int argc, char *argv[], std::deque<Town*>& lst);

void moveFront(std::deque<Town*>& lst);
void deleteTowns(std::deque<Town*>& lst);
bool tryToRotate(int startId, std::deque<Town*>& lst);
Town* createTown(int id, std::string name, int stamina, int distance);

#endif // VISITALL_SRC_VISITALL_H_
