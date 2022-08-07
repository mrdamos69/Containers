#include "s21_stack.h"
using namespace s21;

template<typename T>
s21::s21_stack<T>::s21_stack(std::initializer_list<value_type> const &items) {
    this->m_size = 0;
    this->head = nullptr;
    for (auto &i : items) {
        this->push(i);
    }
}

template<typename T>
s21::s21_stack<T>::s21_stack(const s21_stack& s) : m_size(0), head(nullptr) {
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
s21::s21_stack<T>&  s21::s21_stack<T>::operator = (s21_stack &s) {
    if (head) {
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
bool s21::s21_stack<T>::empty() {
    return !(this->m_size > 0);
}

template<typename T>
size_t s21::s21_stack<T>::get_size() {
    return this->m_size;
}

template<typename T>
void s21::s21_stack<T>::push(value_type data) {
    head = new Node<value_type>(data, head);
    m_size++;
}

template<typename T>
void s21::s21_stack<T>::pop() {
    Node<value_type>* current = this->head;
    this->head = this->head->pNext;
    delete current;
    m_size--;
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
    if (head == nullptr) {
        head = new Node<value_type>(data);
    } else {
        Node<value_type>* current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<value_type>(data);
    }
    m_size++;
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
    while (m_size) {
        this->pop();
    }
}
