#include <iostream>
#include <string>
#include <array>
#include <vector>

#include "CBLVector.h"
#include "algorithmUtils.h"

template <typename T>
void compareVector(std::vector<T>& a, CBL::Vector<T>& b) {
    bool sizeEq = false;
    bool capacityEq = false;
    bool vars = true;

    if (a.size() == b.size())
        sizeEq = true;
    if (a.capacity() == b.capacity())
        capacityEq = true;

    // Check variables
    for (size_t i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] != b[i]) {
            vars = false;
            break;
        }
    }

    // DEBUG
    // std::cout << " == DEBUG ==" << std::endl;
    // std::cout << "sizeEq: " << (sizeEq ? "true" : "false") << std::endl;
    // std::cout << "capacityEq: " << (capacityEq ? "true" : "false") << std::endl;
    // std::cout << "vars: " << (vars ? "true" : "false") << std::endl;
    // std::cout << "A: " << std::endl;
    // for (auto x : a)
    //     std::cout << x << " ";
    // std::cout << std::endl;
    // std::cout << "B: " << std::endl;
    // for (auto x : b)
    //     std::cout << x << " ";
    // std::cout << std::endl;
    // std::cout << " == == == ==" << std::endl;

    std::cout << "A ?= B : ";
    if (sizeEq && capacityEq && vars)
        std::cout << "TRUE" << std::endl << std::endl;
    else
        std::cout << "FALSE" << std::endl << std::endl;
}

int main() {
    std::cout << "TEST: Vector()" << std::endl;
    std::vector<int> a1;
    CBL::Vector<int> b1;
    compareVector(a1, b1);

    std::cout << "TEST: explicit Vector(size_t size)" << std::endl;
    std::vector<int> a2(5);
    CBL::Vector<int> b2(5);
    compareVector(a2, b2);

    std::cout << "TEST: Vector(size_t size, const T& value)" << std::endl;
    std::vector<int> a3(5, -1);
    CBL::Vector<int> b3(5, -1);
    compareVector(a3, b3);

    std::cout << "TEST: Vector(iterator first, iterator last)" << std::endl;
    std::vector<int> a4(a3.begin(), a3.end());
    CBL::Vector<int> b4(b3.begin(), b3.end());
    compareVector(a4, b4);

    std::array<int, 8> arr = {0, 1, 2, 3, 4, 5, 6, 7};
    std::cout << "TEST: Vector(const std::initializer_list<T>& lst)" << std::endl;
    std::vector<int> a5(arr.begin(), arr.end());
    CBL::Vector<int> b5(arr.begin(), arr.end());
    compareVector(a5, b5);

    std::cout << "TEST: Vector(const Vector<T>& other)" << std::endl;
    std::vector<int> a6(a5);
    CBL::Vector<int> b6(b5);
    compareVector(a6, b6);

    std::cout << "TEST: Operators" << std::endl;
    std::vector<int> a7{1, 2, 3};
    std::vector<int> stdsmaller1{1, 2};
    std::vector<int> stdsmaller2{1, 2, 2};
    std::vector<int> stdequale{1, 2, 3};
    std::vector<int> stdbigger1{1, 2, 4};
    std::vector<int> stdbigger2{1, 2, 3, 4};
    // -- -- -- -- -- -- -- -- -- -- -- --
    CBL::Vector<int> b7{1, 2, 3};
    CBL::Vector<int> cblsmaller1{1, 2};
    CBL::Vector<int> cblsmaller2{1, 2, 2};
    CBL::Vector<int> cblequale{1, 2, 3};
    CBL::Vector<int> cblbigger1{1, 2, 4};
    CBL::Vector<int> cblbigger2{1, 2, 3, 4};
    compareVector(a7, b7);

    if (a7 == stdsmaller1)
        std::cout << "std {1, 2, 3} ?= {1, 2} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?= {1, 2} : FALSE" << std::endl;
    if (b7 == cblsmaller1)
        std::cout << "cbl {1, 2, 3} ?= {1, 2} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?= {1, 2} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 == stdsmaller2)
        std::cout << "std {1, 2, 3} ?= {1, 2, 2} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?= {1, 2, 2} : FALSE" << std::endl;
    if (b7 == cblsmaller2)
        std::cout << "cbl {1, 2, 3} ?= {1, 2, 2} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?= {1, 2, 2} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 == stdequale)
        std::cout << "std {1, 2, 3} ?= {1, 2, 3} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?= {1, 2, 3} : FALSE" << std::endl;
    if (b7 == cblequale)
        std::cout << "cbl {1, 2, 3} ?= {1, 2, 3} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?= {1, 2, 3} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 == stdbigger1)
        std::cout << "std {1, 2, 3} ?= {1, 2, 4} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?= {1, 2, 4} : FALSE" << std::endl;
    if (b7 == cblbigger1)
        std::cout << "cbl {1, 2, 3} ?= {1, 2, 4} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?= {1, 2, 4} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 == stdbigger2)
        std::cout << "std {1, 2, 3} ?= {1, 2, 3, 4} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?= {1, 2, 3, 4} : FALSE" << std::endl;
    if (b7 == cblbigger2)
        std::cout << "cbl {1, 2, 3} ?= {1, 2, 3, 4} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?= {1, 2, 3, 4} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 < stdsmaller1)
        std::cout << "std {1, 2, 3} ?< {1, 2} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?< {1, 2} : FALSE" << std::endl;
    if (b7 < cblsmaller1)
        std::cout << "cbl {1, 2, 3} ?< {1, 2} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?< {1, 2} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 < stdsmaller2)
        std::cout << "std {1, 2, 3} ?< {1, 2, 2} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?< {1, 2, 2} : FALSE" << std::endl;
    if (b7 < cblsmaller2)
        std::cout << "cbl {1, 2, 3} ?< {1, 2, 2} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?< {1, 2, 2} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 < stdequale)
        std::cout << "std {1, 2, 3} ?< {1, 2, 3} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?< {1, 2, 3} : FALSE" << std::endl;
    if (b7 < cblequale)
        std::cout << "cbl {1, 2, 3} ?< {1, 2, 3} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?< {1, 2, 3} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 < stdbigger1)
        std::cout << "std {1, 2, 3} ?< {1, 2, 4} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?< {1, 2, 4} : FALSE" << std::endl;
    if (b7 < cblbigger1)
        std::cout << "cbl {1, 2, 3} ?< {1, 2, 4} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?< {1, 2, 4} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 < stdbigger2)
        std::cout << "std {1, 2, 3} ?< {1, 2, 3, 4} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?< {1, 2, 3, 4} : FALSE" << std::endl;
    if (b7 < cblbigger2)
        std::cout << "cbl {1, 2, 3} ?< {1, 2, 3, 4} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?< {1, 2, 3, 4} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 <= stdsmaller1)
        std::cout << "std {1, 2, 3} ?<= {1, 2} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?<= {1, 2} : FALSE" << std::endl;
    if (b7 <= cblsmaller1)
        std::cout << "cbl {1, 2, 3} ?<= {1, 2} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?<= {1, 2} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 <= stdsmaller2)
        std::cout << "std {1, 2, 3} ?<= {1, 2, 2} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?<= {1, 2, 2} : FALSE" << std::endl;
    if (b7 <= cblsmaller2)
        std::cout << "cbl {1, 2, 3} ?<= {1, 2, 2} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?<= {1, 2, 2} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 <= stdequale)
        std::cout << "std {1, 2, 3} ?<= {1, 2, 3} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?<= {1, 2, 3} : FALSE" << std::endl;
    if (b7 <= cblequale)
        std::cout << "cbl {1, 2, 3} ?<= {1, 2, 3} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?<= {1, 2, 3} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 <= stdbigger1)
        std::cout << "std {1, 2, 3} ?<= {1, 2, 4} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?<= {1, 2, 4} : FALSE" << std::endl;
    if (b7 <= cblbigger1)
        std::cout << "cbl {1, 2, 3} ?<= {1, 2, 4} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?<= {1, 2, 4} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 <= stdbigger2)
        std::cout << "std {1, 2, 3} ?<= {1, 2, 3, 4} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?<= {1, 2, 3, 4} : FALSE" << std::endl;
    if (b7 <= cblbigger2)
        std::cout << "cbl {1, 2, 3} ?<= {1, 2, 3, 4} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?<= {1, 2, 3, 4} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 >= stdsmaller1)
        std::cout << "std {1, 2, 3} ?>= {1, 2} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?>= {1, 2} : FALSE" << std::endl;
    if (b7 >= cblsmaller1)
        std::cout << "cbl {1, 2, 3} ?>= {1, 2} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?>= {1, 2} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 >= stdsmaller2)
        std::cout << "std {1, 2, 3} ?>= {1, 2, 2} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?>= {1, 2, 2} : FALSE" << std::endl;
    if (b7 >= cblsmaller2)
        std::cout << "cbl {1, 2, 3} ?>= {1, 2, 2} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?>= {1, 2, 2} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 >= stdequale)
        std::cout << "std {1, 2, 3} ?>= {1, 2, 3} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?>= {1, 2, 3} : FALSE" << std::endl;
    if (b7 >= cblequale)
        std::cout << "cbl {1, 2, 3} ?>= {1, 2, 3} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?>= {1, 2, 3} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 >= stdbigger1)
        std::cout << "std {1, 2, 3} ?>= {1, 2, 4} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?>= {1, 2, 4} : FALSE" << std::endl;
    if (b7 >= cblbigger1)
        std::cout << "cbl {1, 2, 3} ?>= {1, 2, 4} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?>= {1, 2, 4} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 >= stdbigger2)
        std::cout << "std {1, 2, 3} ?>= {1, 2, 3, 4} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?>= {1, 2, 3, 4} : FALSE" << std::endl;
    if (b7 >= cblbigger2)
        std::cout << "cbl {1, 2, 3} ?>= {1, 2, 3, 4} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?>= {1, 2, 3, 4} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 > stdsmaller1)
        std::cout << "std {1, 2, 3} ?> {1, 2} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?> {1, 2} : FALSE" << std::endl;
    if (b7 > cblsmaller1)
        std::cout << "cbl {1, 2, 3} ?> {1, 2} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?> {1, 2} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 > stdsmaller2)
        std::cout << "std {1, 2, 3} ?> {1, 2, 2} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?> {1, 2, 2} : FALSE" << std::endl;
    if (b7 > cblsmaller2)
        std::cout << "cbl {1, 2, 3} ?> {1, 2, 2} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?> {1, 2, 2} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 > stdequale)
        std::cout << "std {1, 2, 3} ?> {1, 2, 3} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?> {1, 2, 3} : FALSE" << std::endl;
    if (b7 > cblequale)
        std::cout << "cbl {1, 2, 3} ?> {1, 2, 3} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?> {1, 2, 3} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 > stdbigger1)
        std::cout << "std {1, 2, 3} ?> {1, 2, 4} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?> {1, 2, 4} : FALSE" << std::endl;
    if (b7 > cblbigger1)
        std::cout << "cbl {1, 2, 3} ?> {1, 2, 4} : TRUE" << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?> {1, 2, 4} : FALSE" << std::endl;
    // -- -- -- -- -- -- -- -- -- -- -- --
    if (a7 > stdbigger2)
        std::cout << "std {1, 2, 3} ?> {1, 2, 3, 4} : TRUE" << std::endl;
    else
        std::cout << "std {1, 2, 3} ?> {1, 2, 3, 4} : FALSE" << std::endl;
    if (b7 > cblbigger2)
        std::cout << "cbl {1, 2, 3} ?> {1, 2, 3, 4} : TRUE" << std::endl << std::endl;
    else
        std::cout << "cbl {1, 2, 3} ?> {1, 2, 3, 4} : FALSE" << std::endl << std::endl;

    std::cout << "TEST: isEmpty()" << std::endl;
    std::vector<int> a8;
    CBL::Vector<int> b8;
    compareVector(a8, b8);
    if (a8.empty())
        std::cout << "a ? empty : TRUE" << std::endl;
    else
        std::cout << "a ? empty : FALSE" << std::endl;
    if (b8.isEmpty())
        std::cout << "b ? empty : TRUE" << std::endl << std::endl;
    else
        std::cout << "b ? empty : FALSE" << std::endl << std::endl;

    std::cout << "TEST: resize(size_t size, const T& value = T())" << std::endl;
    std::vector<int> a9{1, 2, 3};
    CBL::Vector<int> b9{1, 2, 3};
    a9.resize(8, 5);
    b9.resize(8, 5);
    compareVector(a9, b9);

    std::cout << "TEST: reserve(size_t size)" << std::endl;
    std::vector<int> a10{1, 2, 3, 4};
    CBL::Vector<int> b10{1, 2, 3, 4};
    a10.reserve(7);
    b10.reserve(7);
    compareVector(a10, b10);

    std::cout << "TEST: push_back(const T& value)" << std::endl;
    std::vector<int> a11{1, 2, 3, 4};
    CBL::Vector<int> b11{1, 2, 3, 4};
    a11.push_back(5);
    b11.push_back(5);
    compareVector(a11, b11);
    std::cout << "TEST: push_back(const T& value)" << std::endl;
    a11.pop_back();
    b11.pop_back();
    compareVector(a11, b11);

    std::cout << "TEST: insert(iterator pos, const T& value)" << std::endl;
    std::vector<int> a12{1, 2, 3, 4};
    CBL::Vector<int> b12{1, 2, 3, 4};
    a12.insert(a12.begin() + 2, -1);
    b12.insert(b12.begin() + 2, -1);
    compareVector(a12, b12);

    std::cout << "TEST: erase(iterator pos)" << std::endl;
    std::vector<int> a13{1, 2, 3, 4};
    CBL::Vector<int> b13{1, 2, 3, 4};
    a13.erase(a13.begin() + 2);
    b13.erase(b13.begin() + 2);
    compareVector(a13, b13);

    std::cout << "TEST: erase(iterator first, iterator last)" << std::endl;
    std::vector<int> a14{1, 2, 3, 4};
    CBL::Vector<int> b14{1, 2, 3, 4};
    a14.erase(a14.begin() + 1, a14.begin() + 2);
    b14.erase(b14.begin() + 1, b14.begin() + 2);
    compareVector(a14, b14);

    return 0;
}
