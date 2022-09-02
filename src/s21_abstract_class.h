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
  Node *pNext;
  Node *pBack;
  T data;
  explicit Node(T data = T(), Node *pNext = nullptr, Node *pBack = nullptr) {
    this->data = data;
    this->pNext = pNext;
    this->pBack = pBack;
  }
};

template <typename T>
class Key {
 public:
  Key *pLeft = nullptr;
  Key *pRight = nullptr;
  Key *pBack = nullptr;
  Key *pRoot = nullptr;
  T data = 0;
};

template <typename T, typename T2>
class Key_Map {
 public:
  Key_Map *pLeft = nullptr;
  Key_Map *pRight = nullptr;
  Key_Map *pBack = nullptr;
  Key_Map *pRoot = nullptr;
  std::pair<T, T2> data;
};

template <typename T>
class abstract_containers {
 protected:
  size_t m_size;  // количество элементов в списке
 public:
  abstract_containers() : m_size(0) {}
  size_t virtual max_size() = 0;  // возвращает максимально возможное количество
                                  // элементов
  bool empty() { return !(this->m_size > 0); }  // проверяет, пуст ли контейнер
  size_t get_size() { return this->m_size; }  // возвращает количество элементов
};

template <typename T>
class abstract_containers_list : public abstract_containers<T> {
 protected:
  Node<T> *head;  // указатель на следующий элемент списка
  Node<T> *tail;  // указатель на предыдущий элемент списка
 public:
  abstract_containers_list()
      : abstract_containers<T>(), head(nullptr), tail(nullptr) {}
};

template <typename T>
class abstract_containers_arr : public abstract_containers<T> {
 protected:
  size_t m_capacity;
  T *arr;

 public:
  abstract_containers_arr()
      : abstract_containers<T>(), m_capacity(0), arr(nullptr) {}
  T *begin() { return this->arr; }  // возвращает итератор в начало
  T *end() { return this->arr + this->m_size; }
  // возвращает итератор в конец
  const T &front() { return arr[0]; }
  // получить доступ к первому элементу
  const T &back() { return arr[this->m_size - 1]; }
  // получить доступ к последнему элементу
  T &operator[](size_t pos) { return pos > 0 ? this->arr[pos] : this->arr[0]; }
  // доступ к указанному элементу
  T &at(size_t pos) { return pos < this->m_size ? arr[pos] : arr[0]; }
  // доступ к указанному элементу с проверкой границ
  T *data() { return this->arr; }
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
