#include "draugr.h"

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

int main(int argc, char *argv[]) {
    std::regex rgx("([A-Za-z]{1,}),([A-Za-z]{1,})");
    std::cmatch result;

    if (argc < 4 || argc > 5)
        cexit("./draugr [shoutNumber] [name1,name2] [health] [frostResist]");
    try {
        if (argc == 4) {
            if (std::regex_match(argv[2], result, rgx)) {
                Draugr dr1(std::stod(argv[3]), 50);
                dr1.setName(std::move(result[1]));
                dr1.shoutPhrase(std::stoi(argv[1]));
                Draugr dr2(dr1);
                dr2.setName(std::move(result[2]));
                dr2.shoutPhrase(std::stoi(argv[1]));
            }
            else
                cexit("Invalid names");
        }
        else {
            if (std::regex_match(argv[2], result, rgx)) {
                Draugr dr1(std::stod(argv[3]), std::stoi(argv[4]));
                dr1.setName(std::move(result[1]));
                dr1.shoutPhrase(std::stoi(argv[1]));
                Draugr dr2(std::move(dr1));
                dr2.setName(std::move(result[2]));
                dr2.shoutPhrase(std::stoi(argv[1]));
            }
            else
                cexit("Invalid names");
        }
    }
    catch (...) {
        std::cerr << "ERROR" << std::endl;
    }
    return 0;
}
