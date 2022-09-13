#include "stack.h"

template <typename T>
s21::s21_stack<T>::s21_stack(std::initializer_list<value_type> const &items)
    : s21_stack() {
  for (auto &i : items) this->push(i);
}

template <typename T>
s21::s21_stack<T>::s21_stack(const s21_stack &s) : s21_stack() {
  Node<value_type> *current = s.head_;
  while (current != nullptr) {
    this->push(current->data_);
    current = current->pNext_;
  }
}

template <typename T>
s21::s21_stack<T>::s21_stack(s21_stack &&s) : s21::s21_stack<T>(s) {
  if (this->head_ == s.head_)
    throw std::invalid_argument("s21_steck argument too large.");
  s.clear();
}

template <typename T>
s21::s21_stack<T>::~s21_stack() {
  this->clear();
}

template <typename T>
s21::s21_stack<T> &s21::s21_stack<T>::operator=(const s21_stack &s) {
  if (this->head_) {
    this->clear();
  }
  Node<value_type> *current = s.head_;
  while (current != nullptr) {
    this->push_back(current->data_);
    current = current->pNext_;
  }
  return *this;
}

template <typename T>
const T &s21::s21_stack<T>::top() {
  return this->head_->data_;
}

template <typename T>
void s21::s21_stack<T>::push(value_type data_) {
  this->head_ = new Node<value_type>(data_, this->head_);
  (this->m_size)++;
}

template <typename T>
void s21::s21_stack<T>::pop() {
  Node<value_type> *current = this->head_;
  this->head_ = this->head_->pNext_;
  if (current != nullptr) delete current;
  (this->m_size)--;
}

template <typename T>
void s21::s21_stack<T>::swap(s21_stack &other) {
  s21_stack<T> temp(*this);
  *this = other;
  other = temp;
  other.reverse();
}

template <typename T>
void s21::s21_stack<T>::push_back(value_type data_) {
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
void s21::s21_stack<T>::reverse() {
  Node<value_type> *current = this->head_;
  s21_stack<T> temp;
  while (current != nullptr) {
    temp.push(current->data_);
    current = current->pNext_;
  }
  *this = temp;
}

template <typename T>
void s21::s21_stack<T>::clear() {
  while (this->m_size) {
    this->pop();
  }
}

template <typename T>
template <typename... Arg>
void s21::s21_stack<T>::emplace_front(T value, Arg &&...args) {
  this->push(value);
  this->emplace_front(std::forward<Arg>(args)...);
}
