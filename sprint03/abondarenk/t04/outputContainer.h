#ifndef OUTPUTONCE_H_
#define OUTPUTONCE_H_

#include <iostream>
#include <iterator>
#include <fstream>

template <typename Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<typename Container::value_type> out(std::cout, "\n");
    std::copy(container.begin(), container.end(), out);
}

#endif // OUTPUTONCE_H_
