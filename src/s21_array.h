#pragma once
#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include <iostream>
#include <initializer_list>
#include <utility>

// #define MAX_SIZE_ARRAY 2305843009213693951

namespace s21 {
    template <typename T, size_t SIZE>
    class s21_array {
        private:
            size_t m_size;
            T *arr;

        public:
            using value_type = T;
            using reference = T &;
            using const_reference = const T &;
            using iterator = T*;
            using const_iterator = const T*;
            using size_type = size_t;
        public:
            s21_array();
            s21_array(std::initializer_list<value_type> const &items);

            s21_array(const s21_array &v);

            s21_array(s21_array &&v) : m_size(v.m_size), arr(v.arr) {
                v.arr = nullptr;
                v.m_size = 0;
            }
            ~s21_array() { delete[] arr; }

            s21_array<T, SIZE>& operator = (s21_array<T, SIZE> &v);  // Перегрузка оператора присваивания для движущегося объекта

            reference at(size_type pos);  // доступ к указанному элементу с проверкой границ
            reference operator[](size_type pos);  // доступ к указанному элементу
            bool operator == (s21_array<T, SIZE> &v);

            const_reference front();  // получить доступ к первому элементу
            const_reference back();  // получить доступ к последнему элементу
            iterator data();  // прямой доступ к базовому массиву

            iterator begin() {return this->arr;} // возвращает итератор в начало
            iterator end() {return this->arr + (m_size);}  // возвращает итератор в конец

            bool empty();  // проверяет, пуст ли контейнер
            size_type get_size();  // возвращает количество элементов
            size_t max_size();  // возвращает максимально возможное количество элементов

            /**/void clear();  // очищает содержимое
            void swap(s21_array& other);  // меняет содержимое
            void fill(const_reference value);  // присваивает заданное значение value всем элементам в контейнере
    };
}

#endif  // S21_ARRAY_H
