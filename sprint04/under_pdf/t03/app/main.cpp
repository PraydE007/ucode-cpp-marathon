#include "calculator.h"

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

int main(void) {
    std::string cmd_line;

    while (true) {
        std::cout << ":>";
        std::getline(std::cin, cmd_line, '\n');
        Calculator::validateInput(cmd_line);
    }
    return 0;
}
