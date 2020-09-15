#include "src/simpleSort.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cerr << USAGE << std::endl;
        return 1;
    }

    std::array<std::string, 5> arr = {argv[1], argv[2], argv[3], argv[4], argv[5]};
    std::sort(arr.begin(), arr.end());

    std::cout << arr[0];
    for (int i = 1; i < arr.size(); i++)
        std::cout << " " << arr[i];
    std::cout << std::endl;
    return 0;
}
