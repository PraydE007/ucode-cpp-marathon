#include "src/stringCompare.h"

int main(int argc, char *argv[]) {
  std::vector<std::string> arr;

  for (int i = 1; i < argc; i++) {
    if (find_str(argv[i], "mercer"))
      arr.push_back(argv[i]);
    else if (find_str(argv[i], "emer"))
      arr.push_back(argv[i]);
    else if (find_str(argv[i], "jim"))
      arr.push_back(argv[i]);
  }
  for (std::string str : arr)
    std::cout << str << ", move along!" << std::endl;
  return 0;
}
