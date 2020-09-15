#include "stdAlgo.h"

bool findSubstr(std::string src, std::string substr) {
    auto it = std::search(
        src.begin(), src.end(),
        substr.begin(), substr.end(),
        [](char ch1, char ch2) { return ch1 == ch2; }
    );
    return it != src.end();
}

bool hasDuplicate(std::forward_list<std::string>& lst, std::string str) {
    for (auto& x : lst) {
        if (x == str)
            return true;
    }
    return false;
}

void redit(std::forward_list<std::string>& flst) {
    flst.remove_if([](auto s) { return findSubstr(s, "c"); });
    flst.remove_if([](auto s) { return findSubstr(s, "b"); });
    flst.remove_if([](auto s) { return findSubstr(s, "l"); });

    for (auto& str : flst) {
        if (str.size() > 10)
            str = "Long one";
        else if (str.size() < 4)
            str = "Short one";
    }

    flst.sort();
    flst.unique();
    flst.reverse();
}
