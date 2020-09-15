#ifndef SORTVAL_H_
#define SORTVAL_H_

#include <iterator>
#include <algorithm>

template <class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end) {
    // LAZY BUBBLE SORT ))
    for (auto x = begin; x != end; x++) {
        for (auto y = begin; y != end; y++) {
            if (*x > *y)
                std::swap(*y, *x);
        }
    }
    return begin;
}

#endif // SORTVAL_H_
