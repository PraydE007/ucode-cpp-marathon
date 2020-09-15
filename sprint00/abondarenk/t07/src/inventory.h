#ifndef INVENTORY_SRC_INVENTORY_H_
#define INVENTORY_SRC_INVENTORY_H_

#include <iostream>
#include <sstream>
#include <vector>

#define PROMPT "Enter command:> "
#define EV_INS " was inserted."
#define EV_REM " was removed."
#define ERR_COMMAND "Invalid command."
#define ERR_ITEM "Invalid item."
#define ERR_FULL "Inventory is full."
#define EXT "Bye."

void help(void);
bool checkItemType(char item);
void show(std::vector<char>& inventory);
void remove(std::vector<char>& inventory, char item);
void insert(std::vector<char>& inventory, char item);
void splitCommandLine(std::vector<std::string>& vec, std::string cmdline);

#endif // INVENTORY_SRC_INVENTORY_H_
