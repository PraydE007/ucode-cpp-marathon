#ifndef SUMFILEDATA_H_
#define SUMFILEDATA_H_

#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>

template <class T>
T sumFileData(const std::string& fileName) {
    std::ifstream fin(fileName);
    std::istream_iterator<T> itr(fin);
    std::istream_iterator<T> eos;
    T res{0};

    while (itr != eos) {
        res += *itr;
        itr++;
    }
    return res;
}

#endif // SUMFILEDATA_H_
