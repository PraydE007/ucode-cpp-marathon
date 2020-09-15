#include "inventory.h"

bool checkItemType(char item) {
    if (item == 'w')
        return true;
    else if (item == 'f')
        return true;
    else if (item == 'a')
        return true;
    else if (item == 'p')
        return true;
    return false;
}

void splitCommandLine(std::vector<std::string>& vec, std::string cmdline) {
    std::stringstream ss(cmdline);
    std::string token;
    int i = 0;

    while (std::getline(ss, token, ' ')) {
        vec.push_back(token);
        i++;
    }
}

void help(void) {
    std::cout << "Available commands:" << std::endl;
    std::cout << "1. insert <itemType>" << std::endl;
    std::cout << "2. remove <itemType>" << std::endl;
    std::cout << "3. show" << std::endl;
    std::cout << "4. help" << std::endl;
    std::cout << "5. exit" << std::endl;
}

void show(std::vector<char>& inventory) {
    int itemsCount = inventory.size();

    std::cout << "Inventory { ";
    for (int i = 0; i < 12; i++) {
        if (i < itemsCount) {
            std::cout << inventory[i] << " ";
        }
        else
            std::cout << "- ";
    }
    std::cout << "}" << std::endl;
}

void insert(std::vector<char>& inventory, char item) {
    if (inventory.size() < 12) {
        inventory.push_back(item);
        std::cout << item << EV_INS << std::endl;
    }
    else
        std::cerr << ERR_FULL << std::endl;
}

void remove(std::vector<char>& inventory, char item) {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == item) {
            inventory.erase(inventory.begin() + i);
            std::cout << item << EV_REM << std::endl;
            return;
        }
    }
    std::cout << ERR_ITEM << std::endl;
}
