#include "stack.h"

template<typename T>
s21::s21_stack<T>::s21_stack(std::initializer_list<value_type> const &items) : s21_stack() {
    for (auto &i : items)
        this->push(i);
}

template<typename T>
s21::s21_stack<T>::s21_stack(const s21_stack& s) : s21_stack() {
    Node<value_type>* current =  s.head;
    while (current != nullptr) {
        this->push(current->data);
        current = current->pNext;
    }
}

template<typename T>
s21::s21_stack<T>::s21_stack(s21_stack &&s) : s21::s21_stack<T>(s) {
    s.clear();
}

template<typename T>
s21::s21_stack<T>::~s21_stack() {
    this->clear();
}

template<typename T>
s21::s21_stack<T>&  s21::s21_stack<T>::operator = (const s21_stack &s) {
    if (this->head) {
        this->clear();
    }
    Node<value_type>* current = s.head;
    while (current != nullptr) {
        this->push_back(current->data);
        current = current->pNext;
    }
    return *this;
}

template<typename T>
const T& s21::s21_stack<T>::top() {
    return this->head->data;
}

template<typename T>
void s21::s21_stack<T>::push(value_type data) {
    this->head = new Node<value_type>(data, this->head);
    (this->m_size)++;
}

template<typename T>
void s21::s21_stack<T>::pop() {
    Node<value_type>* current = this->head;
    this->head = this->head->pNext;
    delete current;
    (this->m_size)--;
}

template<typename T>
void s21::s21_stack<T>::swap(s21_stack& other) {
    s21_stack<T> temp(*this);
    *this = other;
    other = temp;
    other.reverse();
}

template<typename T>
void s21::s21_stack<T>::push_back(value_type data) {
    if (this->head == nullptr) {
        this->head = new Node<value_type>(data);
    } else {
        Node<value_type>* current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<value_type>(data);
    }
    (this->m_size)++;
}

template<typename T>
void s21::s21_stack<T>::reverse() {
    Node<value_type>* current = this->head;
    s21_stack<T> temp;
    while (current != nullptr) {
        temp.push(current->data);
        current = current->pNext;
    }
    *this = temp;
}

template<typename T>
void s21::s21_stack<T>::clear() {
    while (this->m_size) {
        this->pop();
    }
}

template<typename T>
size_t s21::s21_stack<T>::max_size() {
    return MAX_SIZE_STECK;
}

template<typename T>
template<typename ... Arg>
void s21::s21_stack<T>::emplace_front(T value, Arg&&...args) {
    this->push(value);
    this->emplace_front(args...);
}
