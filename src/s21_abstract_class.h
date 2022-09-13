#pragma once
#ifndef s21_ABSTRACT_CLASS_H
#define s21_ABSTRACT_CLASS_H
#include <iostream>

namespace s21 {
template <typename T>
class abstract_iterator {
 public:
  virtual T &operator*() = 0;
};

template <typename T>
class Node {
 public:
  Node *pNext_;
  Node *pBack_;
  T data_;
  explicit Node(T data_ = T(), Node *pNext_ = nullptr, Node *pBack_ = nullptr) {
    this->data_ = data_;
    this->pNext_ = pNext_;
    this->pBack_ = pBack_;
  }
};

template <typename T>
class Key {
 public:
  Key *pLeft_ = nullptr;
  Key *pRight_ = nullptr;
  Key *pBack_ = nullptr;
  Key *pRoot_ = nullptr;
  T data_ = 0;
};

template <typename T, typename T2>
class Key_Map {
 public:
  Key_Map *pLeft_ = nullptr;
  Key_Map *pRight_ = nullptr;
  Key_Map *pBack_ = nullptr;
  Key_Map *pRoot_ = nullptr;
  std::pair<T, T2> data_;
};

template <typename T>
class abstract_containers {
 protected:
  size_t m_size;  // количество элементов в списке
 public:
  abstract_containers() : m_size(0) {}
  size_t virtual max_size() {
    return std::numeric_limits<size_t>::max() / (sizeof(T));
  }
  // возвращает максимально возможное количество элементов
  bool empty() { return !(this->m_size > 0); }  // проверяет, пуст ли контейнер
  size_t get_size() { return this->m_size; }  // возвращает количество элементов
};

template <typename T>
class abstract_containers_list : public abstract_containers<T> {
 protected:
  Node<T> *head_;  // указатель на следующий элемент списка
  Node<T> *tail_;  // указатель на предыдущий элемент списка
 public:
  abstract_containers_list()
      : abstract_containers<T>(), head_(nullptr), tail_(nullptr) {}
};

template <typename T>
class abstract_containers_arr : public abstract_containers<T> {
 protected:
  size_t m_capacity;
  T *arr_;

 public:
  abstract_containers_arr()
      : abstract_containers<T>(), m_capacity(0), arr_(nullptr) {}
  T *begin() { return this->arr_; }  // возвращает итератор в начало
  T *end() { return this->arr_ + this->m_size; }
  // возвращает итератор в конец
  const T &front() { return arr_[0]; }
  // получить доступ к первому элементу
  const T &back() { return arr_[this->m_size - 1]; }
  // получить доступ к последнему элементу
  T &operator[](size_t pos) {
    return pos > 0 ? this->arr_[pos] : this->arr_[0];
  }
  // доступ к указанному элементу
  T &at(size_t pos) {
    return pos < this->m_size ? this->arr_[pos] : this->arr_[0];
  }
  // доступ к указанному элементу с проверкой границ
  T *data_() { return this->arr_; }
  // прямой доступ к базовому массиву
};

template <typename T>
class abstract_containers_tree : public abstract_containers<T> {
 protected:
  void virtual back_to_root() = 0;
  void virtual I_ll_be_back() = 0;

 public:
};
}  // namespace s21

#endif  // s21_ABSTRACT_CLASS_H
