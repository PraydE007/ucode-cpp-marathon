#ifndef ARGSVA_H_
#define ARGSVA_H_

#include <cstdarg>
#include <iostream>

template <class T>
T sumOfArguments(T t) {
    return t;
}

template <class T, class ...Ts>
T sumOfArguments(T t, Ts... args) {
    return t + sumOfArguments(args...);
}

#endif // ARGSVA_H_
