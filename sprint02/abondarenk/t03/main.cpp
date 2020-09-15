#include "src/booksLibrary.h"

int main(int argc, char *argv[]) {
    std::multimap<std::string, std::string> lst;

    if (argc != 2)
        cexit(USAGE);
    read(lst, argv[1]);
    logLst(lst);
    return 0;
}
