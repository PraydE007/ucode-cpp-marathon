#pragma once

#include <iostream>
#include <map>
#include <regex>

#define INV_INPUT "invalid input"
#define INV_OPER1 "invalid operand1"
#define INV_OPER2 "invalid operand2"
#define OUTR_OPER1 "operand1 out of range"
#define OUTR_OPER2 "operand2 out of range"
#define DIV_ZERO "division by zero"

#define RGX_CALC "\\s*([\\w*)\\s*([.+.-]{0,2})\\s*([\\w*)\\s*"
#define RGX_CREAT "empty"

class Calculator final {
public:
    static bool validateInput(std::string input);
    static bool checkNumbers(std::string n1, std::string n2);
    static void calculate(std::string operation);

private:
    static int m_op1;
    static int m_op2;
};
