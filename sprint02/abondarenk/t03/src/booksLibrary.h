#ifndef MAPLIB_H_
#define MAPLIB_H_

#include <iostream>
#include <algorithm>
#include <map>
#include <regex>
#include <fstream>

#define USAGE "usage: ./tesLibrary [file_name]"
#define ERROR "error"

void cexit(std::string msg);
void read(std::multimap<std::string, std::string>& lst, std::string fn);
void logLst(std::multimap<std::string, std::string>& lst);

#endif // MAPLIB_H_
