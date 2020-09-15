#include "dragonborn.h"

void Dragonborn::executeAction(const Actions action) {
    std::map<Actions, void (Dragonborn::*)(void) const> tableComand = {
        {Dragonborn::Actions::Magic, &Dragonborn::attackWithMagic},
        {Dragonborn::Actions::Shout, &Dragonborn::shoutThuum},
        {Dragonborn::Actions::Weapon, &Dragonborn::attackWithWeapon}
    };
    try {
        std::invoke(tableComand[action], this);
    }
    catch(...) {
        std::cerr << INV_ACTION << std::endl;
        exit(1);
    }
}

void Dragonborn::shoutThuum() const {
    std::cout << "Yol Toor Shul" << std::endl;
}

void Dragonborn::attackWithMagic() const {
    std::cout << "*attacks with magic spell*" << std::endl;
}

void Dragonborn::attackWithWeapon() const {
    std::cout << "*attacks with weapon*" << std::endl;
}
