#include "s21_queue.h"
using namespace s21;

template<typename T>
s21::s21_queue<T>::s21_queue(std::initializer_list<value_type> const &items) {
    this->m_size = 0;
    this->head = nullptr;
    for (auto &i : items) {
        this->push(i);
    }
}

template<typename T>
s21::s21_queue<T>::s21_queue(const s21_queue& s) : m_size(0), head(nullptr) {
    Node<value_type>* current =  s.head;
    while (current != nullptr) {
        this->push(current->data);
        current = current->pNext;
    }
}

template<typename T>
s21::s21_queue<T>::s21_queue(s21_queue &&s) : s21::s21_queue<T>(s) {
    s.clear();
}

template<typename T>
s21::s21_queue<T>::~s21_queue() {
    this->clear();
}

template<typename T>
s21::s21_queue<T>&  s21::s21_queue<T>::operator = (s21_queue &s) {
    if (head) {
        this->clear();
    }
    Node<value_type>* current = s.head;
    while (current != nullptr) {
        this->push(current->data);
        current = current->pNext;
    }
    return *this;
}

template<typename T>
const T& s21::s21_queue<T>::front() {
    return this->head->data;
}

template<typename T>
const T& s21::s21_queue<T>::back() {
    if (head == nullptr) {
        return this->head->data;
    } else {
        Node<value_type>* current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        return current->data;
    }
}


template<typename T>
bool s21::s21_queue<T>::empty() {
    return !(this->m_size > 0);
}

template<typename T>
size_t s21::s21_queue<T>::get_size() {
    return this->m_size;
}

template<typename T>
void s21::s21_queue<T>::push(value_type data) {
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
void s21::s21_queue<T>::pop() {
    Node<value_type>* current = this->head;
    this->head = this->head->pNext;
    delete current;
    m_size--;
}

template<typename T>
void s21::s21_queue<T>::swap(s21_queue& other) {
    s21_queue<T> temp(*this);
    *this = other;
    other = temp;
    other.reverse();
}

template<typename T>
void s21::s21_queue<T>::push_front(value_type data) {
    head = new Node<value_type>(data, head);
    m_size++;
}

template<typename T>
void s21::s21_queue<T>::reverse() {
    Node<value_type>* current = this->head;
    s21_queue<T> temp;
    while (current != nullptr) {
        temp.push(current->data);
        current = current->pNext;
    }
    *this = temp;
}

template<typename T>
void s21::s21_queue<T>::clear() {
    while (m_size) {
        this->pop();
    }
}
