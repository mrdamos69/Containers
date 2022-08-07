#pragma once
#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include <iostream>
#include <initializer_list>
#include <utility>
#include "s21_list.h"

namespace s21 {
    template<typename T>
    class s21_queue {
    private:
        size_t m_size;  // количество элементов в списке
        Node<T>* head;  // указатель на следующий элемент списка
        void push_front(T data);
        void reverse();
        void clear();
    public:
        using value_type = T;  // Tопределяет тип элемента (T — параметр шаблона)
        using reference = T &;  // T &определяет тип ссылки на элемент
        using const_reference = const T &;  // const T &определяет тип постоянной ссылки
        using size_type = size_t;  // size_tопределяет тип размера контейнера (стандартный тип — size_t)

        s21_queue() : m_size(0), head(nullptr) {} // конструктор по умолчанию, создает пустой стек
        s21_queue(std::initializer_list<value_type> const &items);  // конструктор списка инициализаторов
        s21_queue(const s21_queue &s);  // конструктор копирования
        s21_queue(s21_queue &&s);  // конструктор перемещения
        ~s21_queue();  // деструктор

        s21_queue<T>& operator = (s21_queue &s);  // Перегрузка оператора присваивания для движущегося объекта

        const_reference front();  // получить доступ к первому элементу
        const_reference back();  //
        
        bool empty();  // проверяет, пуст ли контейнер
        size_type get_size();  // возвращает количество элементов
        
        void push(value_type data);  // добавляет элемент в голову

        void pop();  // удаляет первый элемент

        void swap(s21_queue& other);  // Меняет местами элементы двух списков
    };
}

#endif  // S21_QUEUE_H