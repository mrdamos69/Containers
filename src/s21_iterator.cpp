#include "s21_iterator.h"

template<typename T>
s21::iterator<T>& s21::iterator<T>::operator = (const iterator& other) {
    if (this != &other) {
        current = other.current;
    }
    return *this;
}

template<typename T>
s21::iterator<T>& s21::iterator<T>::operator ++() {
    ++current;
    return *this;
}

template<typename T>
s21::iterator<T> s21::iterator<T>::operator ++(int i) {
    iterator tmp(current);
    ++current;
    return tmp;
}