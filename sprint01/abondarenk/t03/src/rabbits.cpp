#include "rabbits.h"

void outputStats(std::list<Rabbit>& lst) {
    int m = 0;
    int f = 0;
    int v = 0;

    std::list<Rabbit> :: iterator it; 
    for (it = lst.begin(); it != lst.end(); it++) {
        if (int(it->gender) == 0)
            m++;
        else
            f++;
        if (it->isVampire)
            v++;
    }

    std::cout << "Males: " << m << std::endl;
    std::cout << "Females: " << f << std::endl;
    std::cout << "Vampires: " << v << std::endl;
}

void spawnRabbit(std::list<Rabbit>& lst) {
    Rabbit rab;

    rab.age = 0;
    rab.gender = Gender(std::rand() % 2);
    rab.isVampire = !(std::rand() % 100);
    lst.push_back(rab);
}

void vampiresAttack(std::list<Rabbit>& lst) {
    int vampires = 0;

    std::list<Rabbit> :: iterator it;
    for (it = lst.begin(); it != lst.end(); it++) {
        if (it->isVampire)
            vampires++;
    }
    for (it = lst.begin(); it != lst.end() && vampires > 0; it++) {
        if (!it->isVampire) {
            it->isVampire = true;
            vampires--;
        }
    }
}

void reproduction(std::list<Rabbit>& lst) {
    int m = 0;
    int f = 0;
    int nts = 0;

    std::list<Rabbit> :: iterator it; 
    for (it = lst.begin(); it != lst.end(); it++) {
        if (!it->isVampire) {
            if (int(it->gender) == 0)
                m++;
            else
                f++;
        }
    }
    nts = std::min(f, m);
    for (int i = 0; i < nts; i++)
        spawnRabbit(lst);
}

void addAge(std::list<Rabbit>& lst) {
    std::list<Rabbit> :: iterator it; 
    for (it = lst.begin(); it != lst.end(); it++)
        it->age += 1;
}

void deathSystem(std::list<Rabbit>& lst) {
    std::list<Rabbit> :: iterator it; 
    for (it = lst.begin(); it != lst.end(); it++) {
        // Rabbits death
        if (it->isVampire && it->age > 7)
            lst.erase(it);
        if (!it->isVampire && it->age > 2)
            lst.erase(it);
    }
}
