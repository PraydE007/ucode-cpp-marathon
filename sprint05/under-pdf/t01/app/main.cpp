#include "draugr.h"

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

void validate_frass(char *num) {
    int shoutNumber;

    try {
        shoutNumber = std::stoi(num);
    }
    catch (...) {
        cexit("ERROR");
    }
    if (shoutNumber < 0 || shoutNumber > 8)
        cexit("Invalid shoutNumber");
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 4)
        cexit("usage: ./draugr [shoutNumber] [health] [frostResist]");
    validate_frass(argv[1]);
    try {
        if (argc == 2) {
            Draugr a;
            a.shoutPhrase(std::stoi(argv[1]));
        }
        else if (argc == 3) {
            Draugr b(std::stod(argv[2]), 50);
            b.shoutPhrase(std::stoi(argv[1]));
            Draugr c(100, std::stod(argv[2]));
            c.shoutPhrase(std::stoi(argv[1]));
        }
        else {
            Draugr d(std::stod(argv[2]), std::stoi(argv[3]));
            d.shoutPhrase(std::stoi(argv[1]));
        }
    }
    catch (...) {
        std::cerr << "ERROR" << std::endl;
    }
    return 0;
}
