#ifndef STDALGO_H_
#define STDALGO_H_

#include <iostream>
#include <algorithm>
#include <forward_list>
#include <fstream>

#define USAGE "usage: ./stdAlgoV1 [file_name]"
#define ERROR "error"

struct Data {
    unsigned int size;
    bool rich;
    bool fift;
    bool vel;
    unsigned int mel;
};

Data* createDB(void);
void readStats(Data*& db, std::string line);
bool findVel(std::string src, std::string substr);
bool findSubstr(std::string src, std::string substr);

#endif // STDALGO_H_
