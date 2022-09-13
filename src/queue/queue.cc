#include "queue.h"

template <typename T>
s21::s21_queue<T>::s21_queue(std::initializer_list<value_type> const &items)
    : s21_queue() {
  for (auto &i : items) {
    this->push(i);
  }
}

template <typename T>
s21::s21_queue<T>::s21_queue(const s21_queue &q) : s21_queue() {
  Node<value_type> *current = q.head;
  while (current != nullptr) {
    this->push(current->data);
    current = current->pNext;
  }
}

template <typename T>
s21::s21_queue<T>::s21_queue(s21_queue &&q) : s21::s21_queue<T>(q) {
  if (this->head == q.head)
    throw std::invalid_argument("s21_queue argument too large.");
  q.clear();
}

template <typename T>
s21::s21_queue<T>::~s21_queue() {
  this->clear();
}

template <typename T>
s21::s21_queue<T> &s21::s21_queue<T>::operator=(const s21_queue &q) {
  if (this->head) {
    this->clear();
  }
  Node<value_type> *current = q.head;
  while (current != nullptr) {
    this->push(current->data);
    current = current->pNext;
  }
  return *this;
}

template <typename T>
const T &s21::s21_queue<T>::front() {
  return this->head->data;
}

template <typename T>
const T &s21::s21_queue<T>::back() {
  if (this->head == nullptr) {
    return this->head->data;
  } else {
    Node<value_type> *current = this->head;
    while (current->pNext != nullptr) {
      current = current->pNext;
    }
    return current->data;
  }
}

template <typename T>
void s21::s21_queue<T>::push(value_type data) {
  if (this->head == nullptr) {
    this->head = new Node<value_type>(data);
  } else {
    Node<value_type> *current = this->head;
    while (current->pNext != nullptr) {
      current = current->pNext;
    }
    current->pNext = new Node<value_type>(data);
  }
  (this->m_size)++;
}

template <typename T>
void s21::s21_queue<T>::pop() {
  Node<value_type> *current = this->head;
  this->head = this->head->pNext;
  delete current;
  (this->m_size)--;
}

template <typename T>
void s21::s21_queue<T>::swap(s21_queue &other) {
  s21_queue<T> temp(*this);
  *this = other;
  other = temp;
  other.reverse();
}

template <typename T>
void s21::s21_queue<T>::push_front(value_type data) {
  this->head = new Node<value_type>(data, this->head);
  (this->m_size)++;
}

template <typename T>
void s21::s21_queue<T>::reverse() {
  Node<value_type> *current = this->head;
  s21_queue<T> temp;
  while (current != nullptr) {
    temp.push(current->data);
    current = current->pNext;
  }
  *this = temp;
}

template <typename T>
void s21::s21_queue<T>::clear() {
  while (this->m_size) {
    this->pop();
  }
}

template <typename T>
template <typename... Arg>
void s21::s21_queue<T>::emplace_back(T value, Arg &&...args) {
  this->push(value);
  this->emplace_back(args...);
}
