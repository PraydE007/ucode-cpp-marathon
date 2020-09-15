#include "uniqueWords.h"

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

std::string getModeName(std::string fn) {
    int d = 0;

    for (d = fn.size(); d > 0 && fn[d] != '.'; d--);
    if (d == 0)
        fn += "_mod";
    else
        fn.insert(d, "_mod");
    return fn;
}

void read(std::set<std::string>& lst, std::string fn) {
    std::ifstream rst;
    std::string line;
    std::regex rg("([\\w'-]+)");
    std::cmatch result;
    int size = 0;

    rst.open(fn);
    if (!rst.is_open())
        cexit(ERROR);
    while (getline(rst, line)) {
        while (std::regex_search(line.c_str(), result, rg)) {
            lst.insert(result[0]);
            line = result.suffix();
        }
        size++;
    }
    rst.close();
    if (size == 0)
        cexit(ERROR);
}

void write(std::set<std::string>& lst, std::string fn) {
    std::ofstream wst;

    wst.open(getModeName(fn));
    for (auto x : lst)
        wst << x << std::endl;
    wst.close();
}
