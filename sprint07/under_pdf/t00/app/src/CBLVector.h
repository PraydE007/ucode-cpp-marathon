#pragma once

#include <iostream>

namespace CBL {

template <class T>
class Vector {
public:
    using iterator = T*;

    Vector() : Vector(0) {}

    explicit Vector(size_t size) : m_size(size), m_capacity(size) {
        m_buffer = new T[m_capacity];
    }

    Vector(size_t size, const T& value) : Vector(size) {
        for (size_t i = 0; i < size; i++)
            m_buffer[i] = value;
    }

    Vector(iterator first, iterator last) : Vector(std::distance(first, last)) {
        int i = 0;

        for (auto it = first; it != last; it++) {
            m_buffer[i] = *it;
            i++;
        }
    }

    Vector(const std::initializer_list<T>& lst) : Vector(lst.size()) {
        int i = 0;

        for (auto it = std::begin(lst); it != std::end(lst); it++) {
            m_buffer[i] = *it;
            i++;
        }
    };

    Vector(const Vector<T>& other): Vector(other.size()) {
        int i = 0;

        for (auto it = other.begin(); it != other.end(); it++) {
            m_buffer[i] = *it;
            i++;
        }
    }

    ~Vector() {
        delete[] m_buffer;
    }

    Vector<T>& operator=(const Vector<T>& other) {
        m_size = 0;
        m_capacity = other.capacity();
        delete[] m_buffer;
        for (auto it = other.begin(); it != other.end(); it++)
            push_back(*it);
    }

    bool operator==(const Vector<T>& other) const {
        if (m_size != other.size())
            return false;
        for (size_t i = 0; i < m_size; i++) {
            if (m_buffer[i] != other[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Vector<T>& other) const {
        return !(*this == other);
    }

    bool operator<(const Vector<T>& other) const {
        for (size_t i = 0; i < m_size && i < other.size(); i++) {
            if (m_buffer[i] < other[i])
                return true;
            else if (m_buffer[i] > other[i])
                return false;
        }
        if (m_size < other.size())
            return true;
        return false;
    }

    bool operator>(const Vector<T>& other) const {
        return !(*this < other) && (*this != other);
    }

    bool operator<=(const Vector<T>& other) const {
        return !(*this > other);
    }

    bool operator>=(const Vector<T>& other) const {
        return !(*this < other);
    }

    // iterators
    iterator begin() const {
        return &m_buffer[0];
    }

    iterator end() const {
        return &m_buffer[m_size];
    }

    // capacity
    size_t size() const {
        return m_size;
    }

    size_t capacity() const {
        return m_capacity;
    }

    bool isEmpty() const {
        return (begin() == end());
    }

    void resize(size_t size, const T& value = T()) {
        if (size != m_capacity) {
            auto buf = new T[size];
            for (size_t i = 0; i < size; i++) {
                if (i < m_size)
                    buf[i] = m_buffer[i];
                else
                    buf[i] = value;
            }
            delete[] m_buffer;
            m_buffer = buf;
            m_size = size;
            if (size > m_capacity)
                m_capacity = size;
        }
    }

    void reserve(size_t size) {
        if (size > m_capacity) {
            auto buf = new T[size];
            for (size_t i = 0; i < m_size; i++)
                buf[i] = m_buffer[i];
            delete[] m_buffer;
            m_buffer = buf;
            m_capacity = size;
        }
    }

    // element access
    T& operator[](size_t index) const {
        return m_buffer[index];
    }

    T& at(size_t index) const {
        if (index >= m_size)
            throw std::out_of_range("");
    }

    T* data() const {
        return &m_buffer[0];
    }

    // modifiers
    void push_back(const T& value) {
        if (m_capacity == m_size) {
            if (m_capacity == 0)
                m_capacity = 1;
            m_capacity *= 2;
            auto buf = new T[m_capacity];
            for (size_t i = 0; i < m_size; i++)
                buf[i] = m_buffer[i];
            delete[] m_buffer;
            m_buffer = buf;
        }
        m_buffer[m_size] = value;
        m_size++;
    }

    void pop_back() {
        if (m_size > 0)
            m_size--;
    }

    iterator insert(iterator pos, const T& value) {
        size_t offset = std::distance(begin(), pos);

        if (m_capacity == m_size) {
            if (m_capacity == 0)
                m_capacity = 1;
            m_capacity *= 2;
            auto buf = new T[m_capacity];
            for (size_t i = 0; i < m_size; i++)
                buf[i] = m_buffer[i];
            delete[] m_buffer;
            m_buffer = buf;
        }
        m_size++;
        for (size_t i = m_size - 1; i > offset; --i)
            m_buffer[i] = m_buffer[i - 1];
        m_buffer[offset] = value;
        return &m_buffer[offset];
    }

    iterator erase(iterator pos) {
        size_t offset = std::distance(begin(), pos);

        for (size_t i = offset; i < m_size - 1; i++)
            m_buffer[i] = m_buffer[i + 1];
        m_size--;
        if (m_size == 0)
            return nullptr;
        return static_cast<iterator>(&m_buffer[offset]);
    }

    iterator erase(iterator first, iterator last) {
        size_t offset1 = std::distance(begin(), first);
        size_t offset2 = std::distance(first, last);

        for (size_t i = offset1; i <= offset1 + offset2; i++)
            m_buffer[i] = m_buffer[i + offset2];
        m_size -= offset2;
        if (m_size == 0)
            return nullptr;
        return &m_buffer[offset1];
    }

    void clear() {
        m_size = 0;
    }

private:
    size_t m_size{0};
    size_t m_capacity{0};
    T* m_buffer{nullptr};
};

} // end namespace CBL
