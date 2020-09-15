#include "MultithreadedClass.h"

int MultithreadedClass::getInt() const {
    return m_int;
}

void MultithreadedClass::add(int addValue) {
    m_mutex.lock();
    m_int += addValue;
    m_mutex.unlock();
}

void MultithreadedClass::subtract(int subtractValue) {
    std::lock_guard<std::mutex> guard(m_mutex);
    m_int -= subtractValue;
}
