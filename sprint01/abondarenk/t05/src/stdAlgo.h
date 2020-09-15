#ifndef STDALGO_H_
#define STDALGO_H_

#include <iostream>
#include <algorithm>
#include <forward_list>
#include <fstream>

#define USAGE "usage: ./stdAlgoV1 [file_name]"
#define ERROR "error"

void redit(std::forward_list<std::string>& flst);
bool findSubstr(std::string src, std::string substr);
void redit(std::forward_list<std::string>& flst);
bool hasDuplicate(std::forward_list<std::string>& lst, std::string str);

#endif // STDALGO_H_
