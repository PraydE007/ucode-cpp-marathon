#include "calculator.h"

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

int main(void) {
    std::string cmd_line;
    // Calculator calc;

    while (true) {
        std::cout << ":>";
        std::getline(std::cin, cmd_line, '\n');
        if (Calculator::validateInput(cmd_line))
            Calculator::calculate();
    }
    return 0;
}
