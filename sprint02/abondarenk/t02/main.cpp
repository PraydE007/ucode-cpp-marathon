#include "src/books.h"

int main(void) {
    std::string cmdline;
    std::map<std::string, std::string> lib;

    while (true) {
        std::cout << PROMPT;
        std::getline(std::cin, cmdline);
        std::vector<std::string> cmd;

        splitCommandLine(cmd, cmdline);
        if (cmd.size() == 0)
            continue;
        else if (cmd.size() == 1) {
            if (cmd[0] == "quit")
                break;
            else if (cmd[0] == "list")
                list(lib);
            else
                std::cerr << ERR_CMD << std::endl;
        }
        else if (cmd.size() == 2) {
            if (cmd[0] == "add")
                add(lib, cmd[1]);
            else if (cmd[0] == "delete")
                deleteBook(lib, cmd[1]);
            else if (cmd[0] == "read")
                read(lib, cmd[1]);
            else
                std::cerr << ERR_CMD << std::endl;
        }
        else
            std::cerr << ERR_CMD << std::endl;
    }
    std::cout << EXT << std::endl;
    return 0;
}
