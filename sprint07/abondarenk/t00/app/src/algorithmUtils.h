#ifndef ALGORITHMUTILS_H_
#define ALGORITHMUTILS_H_

#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>

namespace Utils {

template <typename T>
bool IsInRange(const T& val, const T& from, const T& to) {
    return (val >= from && val <= to);
}

template <typename T>
bool IsInRange(const T& val, const std::pair<const T&, const T&>& minmax) {
    return (val >= minmax.first && val <= minmax.second);
}

// (from, to)
template <typename T>
bool IsInsideRange(const T& val, const T& from, const T& to) {
    return (val > from && val < to);
}

template <typename T>
bool IsInsideRange(const T& val, const std::pair<const T&, const T&>& minmax) {
    return (val > minmax.first && val < minmax.second);
}

// change the object if necessary
// and return the corresponding value of the operation success
template <class T, class U = T>
bool Modify(T& obj, U&& new_value) {
    if (obj == new_value)
        return false;
    obj = new_value;
    return true;
}

// fully remove the specified elements from the collection
template <class Collection, class T>
void RemoveAll(Collection& c, const T& value) {
    auto new_end = std::remove(c.begin(), c.end(), value);

    Collection new_c(c.begin(), new_end);
    c = new_c;
}

// fully remove the specified elements from the collection
template <class Collection, class Pred>
void RemoveAllIf(Collection& c, Pred&& predicate) {
    auto new_end = std::remove(c.begin(), c.end(), predicate);

    Collection new_c(std::begin(c), new_end);
    c = new_c;
}

template <class Collection, class T>
auto Find(Collection& c, const T& value) {
    return std::find(c.begin(), c.end(), value);
}

template <class Collection, class Pred>
auto FindIf(Collection& c, Pred&& predicate) {
    return std::find(c.begin(), c.end(), predicate);
}

template <class Collection, class T>
bool Contains(const Collection& c, const T& value) {
    if (c.end() != Find(c, value))
        return true;
    return false;
}

template <class Collection, class Pred>
bool ContainsIf(const Collection& c, Pred&& predicate) {
    if (c.end() != Find(c, predicate))
        return true;
    return false;
}

template <class Collection, class Pred>
int CountIf(const Collection& c, Pred&& predicate) {
    return std::count_if(c.begin(), c.end(), predicate);
}

template <class T>
const auto& Min(const T& arg) {
    return arg;
}

template <class T, class... Args>
const auto& Min(const T& arg, const Args&... args) {
    return arg < Min(args...) ? arg : Min(args...);
}

template <class T>
const auto& Max(const T& arg) {
    return arg;
}

template <class T, class... Args>
const auto& Max(const T& arg, const Args&... args) {
    return arg > Max(args...) ? arg : Max(args...);
}

template <class Collection>
auto MaxElement(const Collection& c) {
    return std::max_element(c.begin(), c.end());
}

template <class Collection>
auto MinElement(const Collection& c) {
    return std::min_element(c.begin(), c.end());
}

template <class Collection, class Comp>
auto MaxElement(const Collection& c, Comp&& comparator) {
    return std::max_element(c.begin(), c.end(), comparator);
}

template <class Collection, class Comp>
auto MinElement(const Collection& c, Comp&& comparator) {
    return std::min_element(c.begin(), c.end(), comparator);
}

template <class Collection>
void Sort(Collection& c) {
    std::sort(c.begin(), c.end());
}

template <class Collection, class Comp>
void Sort(Collection& c, Comp&& comparator) {
    std::sort(c.begin(), c.end(), comparator);
}

// remove all non-unique elements in the collection
template <class Collection>
void Unique(Collection& c) {
    std::unique(c.begin(), c.end());
}

template <class Collection, class Pred>
void Unique(Collection& c, Pred&& predicate) {
    std::unique(c.begin(), c.end(), predicate);
}

template <class Collection, class Pred>
void ForEach(Collection& c, Pred&& predicate) {
    std::for_each(std::begin(c), std::end(c), predicate);
}

template <class Collection, class T>
int IndexOf(const Collection& c, const T& value) {
    auto it = std::find(c.begin(), c.end(), value);

    if (it != c.end())
        return std::distance(c.begin(), c.end());
    return -1;
}

template <class Collection, class Pred>
int IndexOfIf(const Collection& c, Pred&& predicate) {
    auto it = std::find(c.begin(), c.end(), predicate);

    if (it != c.end())
        return std::distance(c.begin(), c.end());
    return -1;
}

}

#endif // ALGORITHMUTILS_H_
