#include "meadSong.h"

void writeSong(void) {
    for (int i = 99; i > 1; i--) {
        std::cout << i << " bottles of mead on the wall, " << i << " bottles of mead." << std::endl;
        std::cout << "Take one down and pass it around, " << i - 1 << " bottles of mead on the wall.\n" << std::endl;
    }
    std::cout << "1 bottle of mead on the wall, 1 bottle of mead." << std::endl;
    std::cout << "Take it down and pass it around, no more bottles of mead on the wall.\n" << std::endl;
    std::cout << "No more bottles of mead on the wall, no more bottles of mead." << std::endl;
    std::cout << "Go to the store and buy some more, 99 bottles of mead on the wall." << std::endl;
}
