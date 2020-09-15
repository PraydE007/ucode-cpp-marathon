#include "ImperialSoldier.h"

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

int checkDamage(std::string arg) {
    int dmg;

    if (arg.size() < 1)
        cexit(USAGE);
    std::istringstream(arg) >> dmg;
    if (dmg >= 10 && dmg <= 20)
        return dmg;
    cexit(DAMAGE);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3)
        cexit(USAGE);

    Sword* sword = new Sword(checkDamage(argv[1]));
    Axe* axe = new Axe(checkDamage(argv[2]));
    ImperialSoldier is;
    StormcloakSoldier ss;

    is.setWeapon(sword);
    ss.setWeapon(axe);

    while (is.getHealth() && ss.getHealth()) {
        if (is.getHealth() > 0)
            is.attack(ss);
        if (ss.getHealth() > 0)
            ss.attack(is);
        std::cout << SPLIT << std::endl;
    }
    if (is.getHealth())
        std::cout << "Imperial has won!" << std::endl;
    else
        std::cout << "Stormcloak has won!" << std::endl;
    return 0;
}
