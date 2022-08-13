#pragma once
#ifndef S21_STACK_H
#define S21_STACK_H

#include <iostream>
#include <initializer_list>
#include <utility>
#include "s21_list.h"


namespace s21 {
    template<typename T>
    class s21_stack {
    private:
        size_t m_size;  // количество элементов в списке
        Node<T>* head;  // указатель на следующий элемент списка
        void push_back(T data);
        void reverse();
    public:
        using value_type = T;  // Tопределяет тип элемента (T — параметр шаблона)
        using reference = T &;  // T &определяет тип ссылки на элемент
        using const_reference = const T &;  // const T &определяет тип постоянной ссылки
        using size_type = size_t;  // size_tопределяет тип размера контейнера (стандартный тип — size_t)

        s21_stack() : m_size(0), head(nullptr) {} // конструктор по умолчанию, создает пустой стек
        s21_stack(std::initializer_list<value_type> const &items);  // конструктор списка инициализаторов
        s21_stack(const s21_stack &s);  // конструктор копирования
        s21_stack(s21_stack &&s);  // конструктор перемещения
        ~s21_stack();  // деструктор

        s21_stack<T>& operator = (s21_stack &s);  // Перегрузка оператора присваивания для движущегося объекта

        const_reference top();  // получить доступ к первому элементу
        
        bool empty();  // проверяет, пуст ли контейнер
        size_type get_size();  // возвращает количество элементов
        
        void push(value_type data);  // добавляет элемент в голову

        void pop();  // удаляет первый элемент

        void swap(s21_stack& other);  // Меняет местами элементы двух списков

        void clear();
    };

    #include "s21_stack.cpp"
}

#endif  // S21_STACK_H