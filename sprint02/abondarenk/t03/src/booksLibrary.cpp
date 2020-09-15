#include "booksLibrary.h"

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

void read(std::multimap<std::string, std::string>& lst, std::string fn) {
    std::ifstream rst;
    std::string line;
    std::regex rg(".*\"(.*)\"\\s*:\\s*\"(.*)\".*");
    std::smatch result;
    int size = 0;

    rst.open(fn);
    if (!rst.is_open())
        cexit(ERROR);
    while (getline(rst, line)) {
        if (std::regex_match(line, result, rg)) {
            lst.insert({result[1], result[2]});
            size++;
        }
        else {
            std::cerr << "Line " << size + 1 << " is invalid" << std::endl;
            std::exit(1);
        }
    }
    rst.close();
    if (size == 0)
        cexit(ERROR);
}

void logLst(std::multimap<std::string, std::string>& lst) {
    std::string name;
    int i = 1;

    for (auto& e : lst) {
        if (e.first == name)
            std::cout << " " << i << ": " << e.second << std::endl;
        else {
            i = 1;
            name = e.first;
            std::cout << name << ":" << std::endl;
            std::cout << " " << i << ": " << e.second << std::endl;
        }
        i++;
    }
}

