#include "src/rabbits.h"

// Spawn first 10 rabbits
static void onStartEvent(std::list<Rabbit>& lst) {
    spawnRabbit(lst); // 1
    spawnRabbit(lst); // 2
    spawnRabbit(lst); // 3
    spawnRabbit(lst); // 4
    spawnRabbit(lst); // 5
    spawnRabbit(lst); // 6
    spawnRabbit(lst); // 7
    spawnRabbit(lst); // 8
    spawnRabbit(lst); // 9
    spawnRabbit(lst); // 10
}

int main(void) {
    std::list<Rabbit> lst;

    std::srand(std::time(nullptr));
    onStartEvent(lst);
    outputStats(lst);
    while (lst.size() < 1000 && lst.size() > 0) {
        addAge(lst);
        vampiresAttack(lst);
        reproduction(lst);
        deathSystem(lst);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        outputStats(lst);
    }
    return 0;
}
