#include "draugr.h"

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

int main(int argc, char *argv[]) {
    Draugr a;

    if (argc != 2)
        cexit("usage: ./draugr [shoutNumber]");
    try {
        a.shoutPhrase(std::stoi(argv[1]));
    }
    catch (...) {
        std::cerr << "Invalid shoutNumber" << std::endl;
    }
    return 0;
}
