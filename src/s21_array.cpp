#include "s21_array.h"
using namespace s21;

template <typename T, size_t SIZE>
s21_array<T, SIZE>::s21_array() : m_size(SIZE) {
    arr = new value_type[SIZE];
}

template <typename T, size_t SIZE>
s21_array<T, SIZE>::s21_array(const s21_array &v) : m_size(v.m_size), arr(nullptr) {
    if (arr)
        delete [] arr;
    arr = new T[m_size];
    for (size_t i = 0; i < m_size; i++) {
        arr[i] = v.arr[i];
    }
}

template <typename T, size_t SIZE>
s21_array<T, SIZE>::s21_array(std::initializer_list<value_type> const &items) {
    arr = new value_type[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        this->arr[i] = 0; 
    int i = 0;
    for (auto it = items.begin(); it != items.end(); it++) {
        arr[i] = *it;
        i++;
    }
    m_size = SIZE;
}

template <typename T, size_t SIZE>
s21_array<T, SIZE>& s21_array<T, SIZE>::operator = (s21_array<T, SIZE> &v) {
    for (size_t i = 0; i <= v.m_size; i++) {
        this->arr[i] = v.arr[i];
    }
    return *this;
}

template <typename T, size_t SIZE>
T& s21_array<T, SIZE>::operator[](size_type pos) {
    return pos > 0 ? this->arr[pos] : this->arr[0];
}

template <typename T, size_t SIZE>
bool s21_array<T, SIZE>::operator == (s21_array<T, SIZE> &v) {
    if (this->m_size != v.m_size){return false;}
    for (size_t i = 0; i < this->m_size; i++)
        if (this->arr[i] != v.arr[i]) {return false;}
    return true;
}

template <typename T, size_t SIZE>
T& s21_array<T, SIZE>::at(size_type pos) {
    return arr[pos];
}

template <typename T, size_t SIZE>
const T& s21_array<T, SIZE>::front() {
    return this->arr[0];
}

template <typename T, size_t SIZE>
const T& s21_array<T, SIZE>::back() {
    return this->arr[this->m_size - 1];
}

template <typename T, size_t SIZE>
T* s21_array<T, SIZE>::data() {
    T* current = new value_type[m_size];
    for (size_t i = 0; i < m_size; i++) {
        current[i] = this->arr[i];
    }
    arr = current;
    return arr;
}

template <typename T, size_t SIZE>
bool s21_array<T, SIZE>::empty() {
    return !(this->m_size > 0);
}

template <typename T, size_t SIZE>
size_t s21_array<T, SIZE>::get_size() {
    return this->m_size;
}

template <typename T, size_t SIZE>
size_t s21_array<T, SIZE>::max_size() {
    return m_size;
}

template <typename T, size_t SIZE>
void s21_array<T, SIZE>::swap(s21_array& other) {
    s21_array<T, SIZE> temp(*this);
    *this = other;
    other = temp;
}

template <typename T, size_t SIZE>
void s21_array<T, SIZE>::fill(const_reference value) {
    for (auto &&i : *this)
        i = value;
}
