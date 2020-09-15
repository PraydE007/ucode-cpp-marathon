#pragma once

#include <iostream>
#include <map>
#include <regex>

#define INV_INPUT "invalid input"
#define INV_OPER1 "invalid operand1"
#define INV_OPER2 "invalid operand2"
#define OUTR_OPER1 "operand1 is out of range"
#define OUTR_OPER2 "operand2 is out of range"
#define DIV_ZERO "division by zero"

#define RGX_CALC "\\s*([-+]?[0-9A-Za-z]{1,})\\s*([+*\\-\\/])\\s*([-+]?[0-9A-Za-z]{1,})\\s*"
#define RGX_CREAT "\\s*([-+]?[0-9A-Za-z]{1,})\\s*([+*\\-\\/])\\s*([-+]?[0-9A-Za-z]{1,})\\s*=\\s*([A-Za-z]{1,})\\s*"

class Calculator final {
public:
    static bool validateInput(std::string input);
    static void calculate(void);

private:
    static bool checkNumbers(std::string n1, std::string n2);
    static bool isVariable1(std::string n);
    static bool isVariable2(std::string n);

    static std::map<std::string, int> m_vars;
    static std::string m_operation;
    static std::string m_xar;
    static int m_op1;
    static int m_op2;
};
