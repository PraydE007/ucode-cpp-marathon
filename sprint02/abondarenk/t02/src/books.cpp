#include "books.h"

void splitCommandLine(std::vector<std::string>& vec, std::string cmdline) {
    std::stringstream ss(cmdline);
    std::string token;

    while (std::getline(ss, token, ' '))
        if (token.size() > 0)
            vec.push_back(token);
}

void list(std::map<std::string, std::string>& lib) {
    for (const auto& [key, value] : lib)
        std::cout << key << std::endl;
}

void add(std::map<std::string, std::string>& lib, std::string key) {
    std::ifstream rst;
    std::string line;
    std::stringstream ss;

    rst.open("library/" + key);
    if (!rst.is_open()) {
        std::cerr << ERR_BOOK << std::endl;
        return;
    }
    getline(rst, line, '\0');
    if (line.size() > 0)
        ss << line;
    lib[key] = ss.str();
    std::cout << key << EV_ADD << std::endl;
    rst.close();
}

void read(std::map<std::string, std::string>& lib, std::string key) {
    if (lib.count(key) < 1) {
        std::cerr << ERR_BOOK << std::endl;
        return;
    }
    std::cout << lib[key] << std::endl;
}

void deleteBook(std::map<std::string, std::string>& lib, std::string key) {
    if (!lib.erase(key)) {
        std::cerr << ERR_BOOK << std::endl;
        return;
    }
    std::cout << key << EV_DEL << std::endl;
}
