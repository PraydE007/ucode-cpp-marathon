#include "DefinesHeader.h"
#include "ImperialSoldier.h"
#include "StormcloakSoldier.h"
#include "Sword.h"
#include "Axe.h"

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

int main(int argc, char *argv[]) {
    int dmg1 = 0;
    int dmg2 = 0;

    if (argc != 3)
        cexit(USAGE);
    dmg1 = std::stoi(argv[1]);
    dmg2 = std::stoi(argv[2]);
    if (dmg1 < 10 || dmg1 > 20
        || dmg2 < 10 || dmg2 > 20)
        cexit(DAMAGE);
    Sword* sword = new Sword(dmg1);
    Axe* axe = new Axe(dmg2);
    ImperialSoldier is;
    StormcloakSoldier ss;
    is.setWeapon(sword);
    ss.setWeapon(axe);
    std::cout << "\n***The battle has begun!***\n" << std::endl;
    while (is.getHealth() > 0 && ss.getHealth() > 0) {
        ss.attack(is);
        is.attack(ss);
        std::cout << SPLIT << std::endl;
    }
    if (is.getHealth() > 0)
        std::cout << "Imperial has won!\n" << std::endl;
    else
        std::cout << "Stormcloak has won!\n" << std::endl;
    return 0;
}
