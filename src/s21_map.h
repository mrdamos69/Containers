#pragma once
#ifndef S21_MAP_H
#define S21_MAP_H
#include <iostream>
#include <initializer_list>
#include <utility>
#include "s21_abstract_class.h"
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
    class const_iterator_map {
    public:
        Key_Map<T, T2>* const_current;
        const_iterator_map() : const_current(0) {}
        const_iterator_map(Key_Map<T, T2>* curr) : const_current(curr) {}
        std::pair<T, T2>& operator *() { return const_current->data; }
        bool operator == (const const_iterator_map& right) {
            return this->const_current == right.const_current;
        }
        bool operator != (const const_iterator_map& right) {
            return !(this->operator==(right));
        }
        //std::ostream& operator << (std::ostream& os, const const_iterator_map& other) {
        //    os << other->const_current->data;
        //    return os;
        //}
    };

    template<typename T, typename T2>
    class iterator_map : public const_iterator_map<T, T2> {
    public:
        iterator_map() : const_iterator_map<T, T2>() {}
        iterator_map(Key_Map<T, T2>* curr) : const_iterator_map<T, T2>(curr) {}

        iterator_map& operator ++ () {
            if (it_end()) {
                this->const_current = this->const_current->pRight;
                return *this;
            }

            if (this->const_current->pRoot == this->const_current) {
                this->const_current = this->const_current->pRight;
                while (this->const_current->pLeft->pLeft != nullptr) {
                    this->const_current = this->const_current->pLeft;
                }
                return *this;
            }

            if (this->const_current->data.first < this->const_current->pRight->data.first && this->const_current->pRight->pRight) {
                this->const_current = this->const_current->pRight;

                while (this->const_current->pLeft->pLeft != nullptr) {
                    this->const_current = this->const_current->pLeft;
                }
                return *this;
            }

            T temp = this->const_current->data.first;
            this->const_current = this->const_current->pBack;

            if (temp == this->const_current->pLeft->data.first) {
                return *this;
            }
            else if (temp == this->const_current->pRight->data.first) {
                this->const_current = this->const_current->pBack;
                if (this->const_current->pRight->pRight && temp == this->const_current->pRight->pRight->data.first) {
                    this->const_current = this->const_current->pBack;
                }
                return *this;
            }
            return *this;
        }

        //iterator_set& operator ++ (int) {
        //    this->operator++();
        //    return *this;
        //}

        iterator_map& operator -- () {
            if (this->const_current->pRoot == this->const_current) {
                this->const_current = this->const_current->pLeft;
                while (this->const_current->pLeft->pRight != nullptr) {
                    this->const_current = this->const_current->pRight;
                }
                return *this;
            }

            if (!this->const_current->pLeft && !this->const_current->pRight) {
                this->const_current = this->const_current->pBack;
                return *this;
            }

            if (this->const_current->pLeft->data.first < this->const_current->data.first && this->const_current->pLeft->pLeft != nullptr) {
                this->const_current = this->const_current->pLeft;
                while (this->const_current->pRight->pRight != nullptr) {
                    this->const_current = this->const_current->pRight;
                }
                return *this;
            }

            T temp = this->const_current->data.first;
            this->const_current = this->const_current->pBack;

            if (temp == this->const_current->pRight->data.first && this->const_current->pRight != nullptr) {
                return *this;
            }

            if (temp == this->const_current->pLeft->data.first) {
                this->const_current = this->const_current->pBack;
                if (this->const_current->pLeft->pLeft && temp == this->const_current->pLeft->pLeft->data.first) {
                    while (this->const_current->pBack != nullptr) {
                        this->const_current = this->const_current->pBack;
                    }
                }
                return *this;
            }

            return *this;
        }

        /*iterator_set& operator -- (int) {
            this->operator--();
            return *this;
        }*/

        private:
            bool it_end() {
                T it_end_count = this->const_current->data.first;
                Key_Map<T, T2>* temp = this->const_current;
                while (temp->pBack != nullptr) {
                    temp = temp->pBack;
                }
                while (temp->pRight->pRight != nullptr) {
                    temp = temp->pRight;
                }
                if (temp->data.first == it_end_count) { return true; }

                return false;
            }
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
        using value_type = std::pair<const key_type, mapped_type>;  // Пара ключ-значение
        using reference = T&;  // определяет тип ссылки на элемент
        using const_reference = const T&;  // определяет тип постоянной ссылки
        using iterator = iterator_map<T, T2>; //
        using const_iterator = const const_iterator_map<T, T2>;  // 
        using size_type = size_t;  // определяет тип размера контейнера

        s21_map() : element(nullptr), back_elem(nullptr) {}  // конструктор по умолчанию 
        s21_map(std::initializer_list<value_type> const& items);  // конструктор списка инициализаторов
        s21_map(const s21_map& m);  // конструктор копирования
        s21_map(s21_map&& m);  // конструктор перемещения
        ~s21_map();  // деструктор
        s21_map<key_type, mapped_type> operator = (s21_map& m);

        T& at(const Key_Map<key_type, mapped_type>& key);  // доступ к указанному элементу с проверкой границ
        T2& operator[](const Key_Map<key_type, mapped_type>& key);  // получить доступ или вставить указанный элемент
        T2& operator[](const key_type& key);

        iterator begin();  // возвращает итератор в начало
        iterator end();  // возвращает итератор в конец

        bool empty();  // проверяет, пуст ли контейнер
        size_type get_size();  // возвращает количество элементов
        size_type max_size();  // возвращает максимально возможное количество элементов

        void clear();  // очищает содержимое

        std::pair<iterator, bool> insert(const value_type& value);  // вставляет узел и возвращает итератор туда, где элемент находится
        // в контейнере, и логическое значение, обозначающее, имела ли место вставка

        std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj);  // вставляет значение по ключу и возвращает итератор туда,
        // где элемент находится в контейнере, и логическое значение, обозначающее, имела ли место вставка

        std::pair<iterator, bool> insert_or_assign(const key_type& key, const mapped_type& obj);  // вставляет элемент или присваивает значение текущему элементу,
        // если ключ уже существует

        void erase(iterator pos);  // стирает элемент в позиции
        void swap(s21_map& other);  // меняет содержимое
        void merge(s21_map& other);  // соединяет узлы из другого контейнера

        bool contains(const key_type& key);  // проверяет, содержит ли контейнер элемент с определенным ключом

        void input_in_branch(Key_Map<T, T2>* branch, const value_type& value);
        void I_ll_be_back();
        void back_to_root();
        void set_copy(Key_Map<T, T2>* other);
    };
    #include "s21_map.cpp"
}

#endif  // S21_MAP_H
