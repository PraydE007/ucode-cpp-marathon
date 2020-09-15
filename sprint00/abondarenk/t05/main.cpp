#include <iostream>

static auto validate(int& argc, char**& argv) {
    for (auto y = 2; y < argc; y++) {
        auto count = 0;

        for (auto x = 0; x < std::string(argv[y]).size(); x++) {
            if (argv[y][x] == '+' || argv[y][x] == '-')
                count++;
        }
        if (count > 1) {
            std::cerr << "Invalid argument: " << argv[y] << std::endl;
            return 1;
        }
    }
    for (auto y = 3; y < argc; y++) {
        auto period = false;

        for (auto x = 0; x < std::string(argv[y]).size(); x++) {
            if ((argv[y][x] >= 48 && argv[y][x] <= 57)
                || argv[y][x] == '-' || argv[y][x] == '+')
                continue;
            else if (argv[y][x] == '.' && !period) {
                period = true;
            }
            else {
                std::cerr << "Invalid argument: " << argv[y] << std::endl;
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cerr << "usage:./automaton [name] [level] [health] [stamina]" << std::endl;
        return 0;
    }
    if (validate(argc, argv) == 1)
        return 1;
    std::cout << "Name = " << std::string(argv[1]) << std::endl;
    std::cout << "Level = " << std::stoi(argv[2]) << std::endl;
    std::cout << "Health = " << std::stof(argv[3]) << std::endl;
    std::cout << "Stamina = " << std::stod(argv[4]) << std::endl;
    return 0;
}
