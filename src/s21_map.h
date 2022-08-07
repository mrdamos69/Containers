#pragma once
#ifndef S21_MAP_H
#define S21_MAP_H
#include <iostream>
#include <initializer_list>
#include <utility>
#define MAX_SIZE 777

namespace s21 {
    template<typename T>
    class Node {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };

    template<typename T, typename T2>
    class s21_map {
    private:
        size_t m_size;
        Node<T>* head;

    public:
        using key_type = T;  // первый параметр шаблона (ключ)
        using mapped_type = T2;  // второй параметр шаблона (T)
        using value_type = std::pair<const key_type,mapped_type>;  // Пара ключ-значение
        using reference = T &;  // определяет тип ссылки на элемент
        using const_reference = const T &;  // определяет тип постоянной ссылки
        using iterator = T*; // 
        using const_iterator = const T*;  // 
        using size_type = size_t;  // определяет тип размера контейнера

        s21_map();  // конструктор по умолчанию 
        explicit s21_map(size_type n);  // параметризованный конструктор, создает список размера n
        s21_map(std::initializer_list<value_type> const &items);  // конструктор списка инициализаторов
        s21_map(const s21_map &m);  // конструктор копирования
        s21_map(s21_map &&m);  // конструктор перемещения
        ~s21_map();  // деструктор
        s21_map<key_type, mapped_type>operator = (map &&m)

        T& at(const Key& key);  // доступ к указанному элементу с проверкой границ
        T& operator[](const Key& key);  // получить доступ или вставить указанный элемент

        iterator begin();  // возвращает итератор в начало
        iterator end();  // возвращает итератор в конец

        bool empty();  // проверяет, пуст ли контейнер
        size_type get_size();  // возвращает количество элементов
        size_type max_size();  // возвращает максимально возможное количество элементов

        void clear();  // очищает содержимое

        std::pair<iterator, bool> insert(const value_type& value);  // вставляет узел и возвращает итератор туда, где элемент находится
        // в контейнере, и логическое значение, обозначающее, имела ли место вставка

        std::pair<iterator, bool> insert(const Key& key, const T& obj);  // вставляет значение по ключу и возвращает итератор туда,
        // где элемент находится в контейнере, и логическое значение, обозначающее, имела ли место вставка

        std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);  // вставляет элемент или присваивает значение текущему элементу,
        // если ключ уже существует

        void erase(iterator pos);  // стирает элемент в позиции
        void swap(set& other);  // меняет содержимое
        void merge(set& other);  // соединяет узлы из другого контейнера

        bool contains(const Key& key);  // проверяет, содержит ли контейнер элемент с определенным ключом
    };
}

#endif  // S21_MAP_H
