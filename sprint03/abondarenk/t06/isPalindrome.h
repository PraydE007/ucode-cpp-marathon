#ifndef YOUFINDASECRET_H_
#define YOUFINDASECRET_H_

#include <iterator>

template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    BidirectionalIterator it1 = begin;
    BidirectionalIterator it2 = --end;

    for (; it1 != it2 && it1 != end && it2 != begin; it1++, it2--) {
        if (*it1 != *it2)
            return false;
    }
    return true;
}

#endif // YOUFINDASECRET_H_

