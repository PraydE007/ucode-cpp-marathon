#ifndef OUTANY_H_
#define OUTANY_H_

#include <iostream>

template <class Container>
void outputAny(const Container& c) {
    for (auto it = c.begin(); it != c.end(); it++)
        std::cout << *it << std::endl;
}

#endif // OUTANY_H_
