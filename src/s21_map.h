#pragma once
#ifndef S21_MAP_H
#define S21_MAP_H
#include <iostream>
#include <initializer_list>
#include <utility>
#define MAX_SIZE_MAP 230584300921369395

namespace s21 {
    
    template<typename T, typename T2>
    class Key_Map {
    public:
        Key_Map* pLeft = nullptr;
        Key_Map* pRight = nullptr;
        Key_Map* pBack = nullptr;
        Key_Map* pRoot = nullptr;
        std::pair<T, T2> data;
    };

    template<typename T, typename T2>
    class s21_map {
    private:
        size_t m_size = 0;
        Key_Map<T, T2>* element;
        Key_Map<T, T2>* back_elem;

    public:
        using key_type = T;  // первый параметр шаблона (ключ)
        using mapped_type = T2;  // второй параметр шаблона (T)
        using value_type = std::pair<const key_type,mapped_type>;  // Пара ключ-значение
        using reference = T &;  // определяет тип ссылки на элемент
        using const_reference = const T &;  // определяет тип постоянной ссылки
        using iterator = T*; // 
        using const_iterator = const T*;  // 
        using size_type = size_t;  // определяет тип размера контейнера

        s21_map() : element(nullptr),  back_elem(nullptr) {}  // конструктор по умолчанию 
        s21_map(std::initializer_list<value_type> const &items);  // конструктор списка инициализаторов
        s21_map(const s21_map &m);  // конструктор копирования
        s21_map(s21_map &&m);  // конструктор перемещения
        ~s21_map();  // деструктор
        s21_map<key_type, mapped_type> operator = (s21_map &&m);

        T& at(const Key_Map<key_type, mapped_type>& key);  // доступ к указанному элементу с проверкой границ
        T& operator[](const Key_Map<key_type, mapped_type>& key);  // получить доступ или вставить указанный элемент

        iterator begin();  // возвращает итератор в начало
        iterator end();  // возвращает итератор в конец

        bool empty();  // проверяет, пуст ли контейнер
        size_type get_size();  // возвращает количество элементов
        size_type max_size();  // возвращает максимально возможное количество элементов

        void clear();  // очищает содержимое

        std::pair<iterator, bool> insert(value_type& value);  // вставляет узел и возвращает итератор туда, где элемент находится
        // в контейнере, и логическое значение, обозначающее, имела ли место вставка

        std::pair<iterator, bool> insert(Key_Map<key_type, mapped_type>& key,  T& obj);  // вставляет значение по ключу и возвращает итератор туда,
        // где элемент находится в контейнере, и логическое значение, обозначающее, имела ли место вставка

        std::pair<iterator, bool> insert_or_assign(Key_Map<key_type, mapped_type>& key, T& obj);  // вставляет элемент или присваивает значение текущему элементу,
        // если ключ уже существует

        void erase(iterator pos);  // стирает элемент в позиции
        void swap(s21_map& other);  // меняет содержимое
        void merge(s21_map& other);  // соединяет узлы из другого контейнера

        bool contains(const Key_Map<key_type, mapped_type>& key);  // проверяет, содержит ли контейнер элемент с определенным ключом

        void input_in_branch(Key_Map<T, T2>* branch, value_type& value);
        void I_ll_be_back();
        void back_to_root();
    };
    #include "s21_map.cpp"
}

#endif  // S21_MAP_H
