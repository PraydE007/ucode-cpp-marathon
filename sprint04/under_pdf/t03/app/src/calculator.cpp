#include "calculator.h"

bool Calculator::validateInput(std::string input) {
    std::regex rgx(RGX_CALC);
    std::smatch result;

    if (std::regex_match(input, result, rgx)) {
        if (checkNumbers(result[0], result[2]))
            
    }
    else {
        // ANOTHER REGEX
    }
    return false;
}

bool Calculator::checkNumbers(std::string n1, std::string n2) {
    m_op1 = 0;
    m_op2 = 0;

    try {
        m_op1 = std::stoi(n1);
    } catch (std::out_of_range const&) {
        std::cerr << OUTR_OPER1 << std::endl;
        return false;
    }
    try {
        m_op2 = std::stoi(n2);
    } catch (std::out_of_range const&) {
        std::cerr << OUTR_OPER2 << std::endl;
        return false;
    }
    return true;
}

void calculate(std::string operation) {

}
