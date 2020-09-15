#ifndef SQUARE_H_
#define SQUARE_H_

#include <iostream>
#include <iterator>

template <class Container>
void squareValue(Container& container) {
    for (auto it = container.begin(); it != container.end(); it++)
        *it *= *it;
}

#endif // SQUARE_H_
