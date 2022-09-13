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
  Node<value_type> *current = q.head_;
  while (current != nullptr) {
    this->push(current->data_);
    current = current->pNext_;
  }
}

template <typename T>
s21::s21_queue<T>::s21_queue(s21_queue &&q) : s21::s21_queue<T>(q) {
  if (this->head_ == q.head_)
    throw std::invalid_argument("s21_queue argument too large.");
  q.clear();
}

template <typename T>
s21::s21_queue<T>::~s21_queue() {
  this->clear();
}

template <typename T>
s21::s21_queue<T> &s21::s21_queue<T>::operator=(const s21_queue &q) {
  if (this->head_) {
    this->clear();
  }
  Node<value_type> *current = q.head_;
  while (current != nullptr) {
    this->push(current->data_);
    current = current->pNext_;
  }
  return *this;
}

template <typename T>
const T &s21::s21_queue<T>::front() {
  return this->head_->data_;
}

template <typename T>
const T &s21::s21_queue<T>::back() {
  if (this->head_ == nullptr) {
    return this->head_->data_;
  } else {
    Node<value_type> *current = this->head_;
    while (current->pNext_ != nullptr) {
      current = current->pNext_;
    }
    return current->data_;
  }
}

template <typename T>
void s21::s21_queue<T>::push(value_type data_) {
  if (this->head_ == nullptr) {
    this->head_ = new Node<value_type>(data_);
  } else {
    Node<value_type> *current = this->head_;
    while (current->pNext_ != nullptr) {
      current = current->pNext_;
    }
    current->pNext_ = new Node<value_type>(data_);
  }
  (this->m_size)++;
}

template <typename T>
void s21::s21_queue<T>::pop() {
  Node<value_type> *current = this->head_;
  this->head_ = this->head_->pNext_;
  if (current != nullptr) delete current;
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
void s21::s21_queue<T>::push_front(value_type data_) {
  this->head_ = new Node<value_type>(data_, this->head_);
  (this->m_size)++;
}

template <typename T>
void s21::s21_queue<T>::reverse() {
  Node<value_type> *current = this->head_;
  s21_queue<T> temp;
  while (current != nullptr) {
    temp.push(current->data_);
    current = current->pNext_;
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
