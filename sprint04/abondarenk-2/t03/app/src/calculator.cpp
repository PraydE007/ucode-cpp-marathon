#include "calculator.h"

auto Calculator::m_vars = std::map<std::string, int>{};
auto Calculator::m_operation = std::string{0};
auto Calculator::m_xar = std::string{0};
auto Calculator::m_op1 = 0;
auto Calculator::m_op2 = 0;

bool Calculator::validateInput(std::string input) {
    std::regex rgx1(RGX_CALC);
    std::regex rgx2(RGX_CREAT);
    std::smatch result;

    m_xar = {0};
    if (input == "quit")
        std::exit(0);
    if (std::regex_match(input, result, rgx1)) {
        m_operation = result[2];
        if (!checkNumbers(result[1], result[3]))
            return false;
    }
    else if (std::regex_match(input, result, rgx2)) {
        m_xar = result[4];
        m_operation = result[2];
        if (!checkNumbers(result[1], result[3]))
            return false;
    }
    else {
        std::cerr << INV_INPUT << std::endl;
        return false;
    }
    return true;
}

bool Calculator::checkNumbers(std::string n1, std::string n2) {
    m_op1 = 0;
    m_op2 = 0;

    if (!isVariable1(n1))
        return false;
    if (!isVariable2(n2))
        return false;
    return true;
}

bool Calculator::isVariable1(std::string n) {
    std::string zs = n;
    bool l = false;
    bool d = false;
    int z = 1;

    for (char c : n) {
        if (c >= 48 && c <= 57)
            d = true;
        if (c >= 65 && c <= 122)
            l = true;
    }
    if (d && l) {
        std::cerr << INV_OPER1 << std::endl;
        return false;
    }
    if (l) {
        if (n[0] == '+' || n[0] == '-') {
            z = n[0] == '-' ? -1 : 1;
            zs = std::string(++n.begin(), n.end());
        }
        if (m_vars.find(zs) == m_vars.end()) {
            std::cerr << INV_OPER1 << std::endl;
            return false;
        }
        else {
            m_op1 = m_vars[zs] * z;
        }
        return true;
    }
    try {
        m_op1 = std::stoi(n);
    } catch (std::out_of_range const&) {
        std::cerr << OUTR_OPER1 << std::endl;
        return false;
    }
    return true;
}

bool Calculator::isVariable2(std::string n) {
    std::string zs = n;
    bool l = false;
    bool d = false;
    int z = 1;

    for (char c : n) {
        if (c >= 48 && c <= 57)
            d = true;
        if (c >= 65 && c <= 122)
            l = true;
    }
    if (d && l) {
        std::cerr << INV_OPER2 << std::endl;
        return false;
    }
    if (l) {
        if (n[0] == '+' || n[0] == '-') {
            z = n[0] == '-' ? -1 : 1;
            zs = std::string(++n.begin(), n.end());
        }
        if (m_vars.find(zs) == m_vars.end()) {
            std::cerr << INV_OPER2 << std::endl;
            return false;
        }
        else {
            m_op2 = m_vars[zs] * z;
        }
        return true;
    }
    try {
        m_op2 = std::stoi(n);
    } catch (std::out_of_range const&) {
        std::cerr << OUTR_OPER2 << std::endl;
        return false;
    }
    return true;
}

void Calculator::calculate(void) {
    long res = 0;

    if (m_operation == "+") {
        res = long(m_op1) + long(m_op2);
        std::cout << res << std::endl;
        if (m_xar.size() > 0)
            m_vars[m_xar] = res;
    }
    else if (m_operation == "-") {
        res = long(m_op1) - long(m_op2);
        std::cout << res << std::endl;
        if (m_xar.size() > 0)
            m_vars[m_xar] = res;
    }
    else if (m_operation == "*") {
        res = long(m_op1) * long(m_op2);
        std::cout << res << std::endl;
        if (m_xar.size() > 0)
            m_vars[m_xar] = res;
    }
    else {
        if (m_op1 == 0 || m_op2 == 0) {
            std::cerr << DIV_ZERO << std::endl;
            return;
        }
        res = long(m_op1) / long(m_op2);
        std::cout << res << std::endl;
        if (m_xar.size() > 0)
            m_vars[m_xar] = res;
    }
}
