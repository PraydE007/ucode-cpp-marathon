#include "src/inventory.h"

int main(void) {
    std::string cmdline;
    std::vector<char> inventory;

    while (true) {
        std::cout << PROMPT;
        std::getline(std::cin, cmdline);
        std::vector<std::string> cmd;

        splitCommandLine(cmd, cmdline);
        if (cmd.size() == 0)
            continue;
        else if (cmd.size() == 1) {
            if (cmd[0] == "exit")
                break;
            else if (cmd[0] == "help")
                help();
            else if (cmd[0] == "show")
                show(inventory);
            else
                std::cerr << ERR_COMMAND << std::endl;
        }
        else if (cmd.size() == 2) {
            if (cmd[1].size() != 1 || !checkItemType(cmd[1][0])) {
                std::cerr << ERR_ITEM << std::endl;
                continue;
            }
            if (cmd[0] == "insert")
                insert(inventory, cmd[1][0]);
            else if (cmd[0] == "remove")
                remove(inventory, cmd[1][0]);
            else
                std::cerr << ERR_COMMAND << std::endl;
        }
        else
            std::cerr << ERR_COMMAND << std::endl;
    }
    std::cout << EXT << std::endl;
    return 0;
}
