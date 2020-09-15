#include "src/visitAll.h"

static void output(std::deque<Town*>& lst) {
    int start = lst[0]->id;

    do {
        std::cout << lst[0]->id << ". " << lst[0]->name << std::endl;
        moveFront(lst);
    }
    while (lst[0]->id != start);
}

int main(int argc, char *argv[]) {
    std::deque<Town*> lst;
    bool f = false;

    if (argc < 2) {
        std::cerr << USAGE << std::endl;
        return 1;
    }
    if (!validate(argc, argv, lst))
        return 1;
    if (argc == 2) {
        std::cerr << M_IMPO << std::endl;
        return 1;
    }
    for (int i = 0; i < lst.size(); i++) {
        if (tryToRotate(i, lst)) {
            output(lst);
            f = true;
            break;
        }
        moveFront(lst);
    }
    if (!f)
        std::cerr << M_IMPO << std::endl;
    deleteTowns(lst);
    return 0;
}
