#include "stringCompare.h"

bool find_str(std::string src, std::string substr) {
  auto it = std::search(
    src.begin(), src.end(),
    substr.begin(), substr.end(),
    [](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); }
  );
  return it != src.end();
}
