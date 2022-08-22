#pragma once
#ifndef S21_SET_H
#define S21_SET_H
#include <iostream>
#include <initializer_list>
#include <utility>
#include "s21_abstract_class.h"
#define MAX_SIZE_SET 230584300921369395

namespace s21 {

    template<typename T>
    class Key {
    public:
        Key* pLeft = nullptr;
        Key* pRight = nullptr;
        Key* pBack = nullptr;
        Key* pRoot = nullptr;
        T data = 0;
    };

    template<typename T>
    class const_iterator_set : public abstract_iterator<T> {
    public:
        Key<T>* const_current;
        const_iterator_set() : const_current(0) {}
        const_iterator_set(Key<T>* curr) : const_current(curr) {}
        T& operator *() { return const_current->data; }
        bool operator == (const const_iterator_set& right);
        bool operator != (const const_iterator_set& right);
    };

    template<typename T>
    class iterator_set : public const_iterator_set<T> {
    public:
        iterator_set() : const_iterator_set<T>() {}
        iterator_set(Key<T>* curr) : const_iterator_set<T>(curr) {}
        iterator_set& operator ++ ();
        iterator_set& operator ++ (int);
        iterator_set& operator -- ();
        iterator_set& operator -- (int);
    private:
        bool it_end();
    };

    template<typename T>
    class s21_set {
    protected:
        size_t m_size;  // количество элементов в set
        Key<T>* element;
        Key<T>* back_elem;

    public:
        using key_type = T;  // первый параметр шаблона (ключ)
        using value_type = T;  // тип значения (само значение является ключом)
        using reference = T&;  // определяет тип ссылки на элемент
        using const_reference = const T&;  // определяет тип постоянной ссылки
        using iterator = iterator_set<T>; // внутренний класс SetIterator<T>или BinaryTree::iteratorкак внутренний итератор подкласса дерева;
        // определяет тип для итерации по контейнеру
        using const_iterator = const const_iterator_set<T>;  // внутренний класс SetConstIterator<T>или BinaryTree::const_iteratorкак внутренний итератор const подкласса дерева;
        // определяет тип константы для итерации по контейнеру
        using size_type = size_t;

        s21_set() : m_size(0), element(nullptr), back_elem(nullptr) {}  // конструктор по умолчанию 
        s21_set(std::initializer_list<value_type> const& items);  // конструктор списка инициализаторов
        s21_set(/*const*/ s21_set<T>& s);  // конструктор копирования
        s21_set(s21_set&& s);  // конструктор перемещения
        ~s21_set();  // деструктор

        s21_set operator = (s21_set& value);

        iterator begin() {
            while (element->pLeft != back_elem)
                element = element->pLeft;
            return this->element;
        }  // возвращает итератор в начало

        iterator end() { return this->back_elem; }  // возвращает итератор в конец

        bool empty();  // проверяет, пуст ли контейнер
        size_type get_size();  // возвращает количество элементов
        size_type max_size();  // возвращает максимально возможное количество элементов

        void clear();  // очищает содержимое
        void clear(Key<T>* key);

        std::pair<T, bool> insert(const value_type& value);  // вставляет узел и возвращает итератор туда, где элемент находится
        // в контейнере, и логическое значение, обозначающее, имела ли место вставка
        void erase(iterator pos);  // стирает элемент в позиции
        void swap(s21_set& other);  // меняет содержимое
        void merge(s21_set& other);  // соединяет узлы из другого контейнера
        iterator find(const Key<T>& key);  // находит элемент с определенным ключом
        iterator find(const T key);
        bool contains(const Key<T>& key);  // проверяет, содержит ли контейнер элемент с определенным ключом

        void back_to_root();

        Key<T>* get_element();

        virtual void set_copy(Key<T>* other);

        virtual bool input_in_branch(Key<T>* branch, T value);

        void I_ll_be_back();
    };
    #include "s21_set.cpp"

}

#endif  // S21_SET_H

