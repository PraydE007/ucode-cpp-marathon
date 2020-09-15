#include "src/stringCompare.h"

int main(int argc, char *argv[]) {
    std::vector<std::string> arr;

    if (argc < 2) {
        std::cerr << USAGE << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        if (findSubstr(argv[i], "mercer"))
        arr.push_back(argv[i]);
        else if (findSubstr(argv[i], "emer"))
        arr.push_back(argv[i]);
        else if (findSubstr(argv[i], "jim"))
        arr.push_back(argv[i]);
    }
    for (std::string str : arr)
        std::cout << str << ", move along!" << std::endl;
    return 0;
}
