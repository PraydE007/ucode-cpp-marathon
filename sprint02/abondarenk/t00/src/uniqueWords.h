#ifndef UNIQWORDS_H_
#define UNIQWORDS_H_

#include <iostream>
#include <algorithm>
#include <set>
#include <regex>
#include <fstream>

#define USAGE "usage: ./uniqueWords [file_name]"
#define ERROR "error"

void cexit(std::string msg);
std::string getModeName(char *filename);
void read(std::set<std::string>& lst, std::string fn);
void write(std::set<std::string>& lst, std::string fn);

#endif // UNIQWORDS_H_
