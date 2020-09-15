#include "ClassWithAtomic.h"
#include <algorithm>

void ClassWithAtomic::addToInt(int addValue) {
    for (auto i = 0; i < addValue; i++)
        m_int++;
}

void ClassWithAtomic::subtractFromInt(int subtractValue) {
    for (auto i = 0; i < subtractValue; i++)
        m_int--;
}

void ClassWithAtomic::pushToVector(int value) {
    m_vecMutex.lock();
    m_vector.push_back(value);
    m_vecMutex.unlock();
}

void ClassWithAtomic::eraseFromVector(int value) {
    m_vecMutex.lock();
    for (size_t i = 0; i < m_vector.size(); i++) {
        if (m_vector[i] == value) {
            m_vector.erase(m_vector.begin() + i);
            i--;
        }
    }
    m_vecMutex.unlock();
}

int ClassWithAtomic::getInt() const {
    return m_int;
}

std::vector<int> ClassWithAtomic::getVector() const {
    return m_vector;
}
