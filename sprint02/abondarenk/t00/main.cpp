#include "src/uniqueWords.h"

int main(int argc, char *argv[]) {
    std::set<std::string> lst;

    if (argc != 2)
        cexit(USAGE);
    read(lst, argv[1]);
    write(lst, argv[1]);
    return 0;
}
