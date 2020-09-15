#ifndef LIBBOOK_H_
#define LIBBOOK_H_

#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <fstream>

#define PROMPT "enter command:> "
#define EV_ADD " added"
#define EV_DEL " deleted"
#define ERR_CMD "invalid command"
#define ERR_BOOK "invalid book"
#define EXT "bye"

void list(std::map<std::string, std::string>& lib);
void splitCommandLine(std::vector<std::string>& vec, std::string cmdline);
void add(std::map<std::string, std::string>& lib, std::string key);
void deleteBook(std::map<std::string, std::string>& lib, std::string key);
void read(std::map<std::string, std::string>& lib, std::string key);

#endif // LIBBOOK_H_
