#include "dragonborn.h"

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

int main(int argc, char *argv[]) {
    std::map<std::string, Dragonborn::Actions> mapActions = {
        {"magic", Dragonborn::Actions::Magic},
        {"shout", Dragonborn::Actions::Shout},
        {"weapon", Dragonborn::Actions::Weapon}
    };

    Dragonborn a;

    if (argc != 2)
        cexit(USAGE);
    try {
        a.executeAction(mapActions[argv[1]]);
    }
    catch (...) {
        cexit(INV_ACTION);
    }
    return 0;
}
