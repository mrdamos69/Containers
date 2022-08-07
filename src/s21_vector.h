#pragma once
#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <iostream>
#include <initializer_list>
#include <utility>

#define MAX_SIZE_VECTOR 2305843009213693951

namespace s21 {
    template <typename T>
    class s21_vector {
        private:
            size_t m_size;
            size_t m_capacity;
            T *arr;

        public:
            using value_type = T;
            using reference = T &;
            using const_reference = const T &;
            using iterator = T*;
            using const_iterator = const T*;
            using size_type = size_t;

        private:
            void reserve_more_capacity(size_type size);

        public:
            s21_vector() : m_size(0U), m_capacity(0U), arr(nullptr) {}
            explicit s21_vector(size_type n) : m_size(n), m_capacity(n), arr(n ? new T[n] : nullptr) {
                for (auto &&i : *this)
                    i = 0;
            }
            s21_vector(std::initializer_list<value_type> const &items);
            s21_vector(const s21_vector &v) : m_size(v.m_size), m_capacity(v.m_capacity), arr(v.arr) {};
            s21_vector(s21_vector &&v) : m_size(v.m_size), m_capacity(v.m_capacity), arr(v.arr) {
                v.arr = nullptr;
                v.m_size = 0;
            }
            ~s21_vector() { delete[] arr; }

            s21_vector<T>& operator = (s21_vector &v);  // Перегрузка оператора присваивания для движущегося объекта

            reference at(size_type pos);  // доступ к указанному элементу с проверкой границ
            reference operator[](size_type pos);  // доступ к указанному элементу
            bool operator == (s21_vector<T> &v);

            const_reference front();  // получить доступ к первому элементу
            const_reference back();  // получить доступ к последнему элементу
            iterator data();  // прямой доступ к базовому массиву

            iterator begin() {return this->arr;} // возвращает итератор в начало
            iterator end() {return this->arr + m_size;}  // возвращает итератор в конец

            bool empty();  // проверяет, пуст ли контейнер
            size_type get_size();  // возвращает количество элементов
            size_t max_size();  // возвращает максимально возможное количество элементов
            void reserve(size_type m_size);  // выделяет хранилище элементов размера и копирует текущие элементы массива в новый выделенный массив
            size_type get_capacity();  // возвращает количество элементов, которые могут храниться в выделенной в данный момент памяти
            void shrink_to_fit();  // уменьшает использование памяти, освобождая неиспользуемую память

            void clear();  // очищает содержимое
            iterator insert(iterator pos, const_reference value);  /* const_reference value)
            вставляет элементы в конкретную позицию и возвращает итератор, указывающий на новый элемент */
            void erase(iterator pos);  // стирает элемент в позиции
            void push_back(const_reference value);  // добавляет элемент в конец
            void pop_back();  // удаляет последний элемент
            void swap(s21_vector& other);  // меняет содержимое
    };
}

#endif  // S21_VECTOR_H
