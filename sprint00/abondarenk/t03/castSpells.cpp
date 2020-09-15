#include "castSpells.h"

int castFloatToInt(float number) {
    return int(number);
}

int* castToNonConstIntPtr(const int* ptr) {
    return const_cast<int*>(ptr);
}
