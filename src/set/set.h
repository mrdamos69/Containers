#pragma once
#ifndef S21_SET_H
#define S21_SET_H
#include <initializer_list>
#include <iostream>
#include <utility>

#include "../s21_abstract_class.h"
#include "../vector/vector.h"

namespace s21 {
template <typename T>
class const_iterator_set : public abstract_iterator<T> {
 public:
  Key<T> *const_current;
  const_iterator_set() : const_current(0) {}
  explicit const_iterator_set(Key<T> *curr) : const_current(curr) {}
  T &operator*() { return const_current->data_; }
  bool operator==(const const_iterator_set &right);
  bool operator!=(const const_iterator_set &right);
};

template <typename T>
class iterator_set : public const_iterator_set<T> {
 public:
  iterator_set() : const_iterator_set<T>() {}
  iterator_set(Key<T> *curr) : const_iterator_set<T>(curr) {}
  iterator_set &operator++();
  iterator_set &operator++(int);
  iterator_set &operator--();
  iterator_set &operator--(int);

 private:
  bool it_end();
};

template <typename T>
class s21_set : public abstract_containers_tree<T> {
 protected:
  Key<T> *element;
  Key<T> *back_elem;
  void I_ll_be_back() override;
  s21_set<T> set_merge(s21_set &other);

 public:
  using key_type = T;  // первый параметр шаблона (ключ)
  using value_type = T;  // тип значения (само значение является ключом)
  using reference = T &;  // определяет тип ссылки на элемент
  using const_reference = const T &;  // определяет тип постоянной ссылки

  using iterator = iterator_set<T>;
  /*внутренний класс SetIterator<T>или BinaryTree::iterator
  как внутренний итератор подкласса дерева определяет тип для итерации по
  контейнеру*/

  using const_iterator = const const_iterator_set<T>;
  /* внутренний класс SetConstIterator<T>или BinaryTree::const_iteratorкак
  внутренний итератор const подкласса дерева;
  определяет тип константы для итерации по контейнеру*/

  using size_type = size_t;

  s21_set()
      : abstract_containers_tree<T>(), element(nullptr), back_elem(nullptr) {}
  // конструктор по умолчанию
  s21_set(std::initializer_list<value_type> const &items);
  // конструктор списка инициализаторов
  s21_set(const s21_set<T> &s);  // конструктор копирования
  s21_set(s21_set &&s);  // конструктор перемещения
  ~s21_set();            // деструктор

  s21_set operator=(const s21_set &value);
  iterator begin();  // возвращает итератор в начало
  iterator end();    // возвращает итератор в конец

  void clear();  // очищает содержимое
  void clear(Key<T> *key);

  std::pair<iterator, bool> insert(const value_type &value);
  /*вставляет узел и возвращает итератор туда, где элемент находится
  в контейнере, и логическое значение, обозначающее, имела ли место вставка*/

  void erase(iterator pos);   // стирает элемент в позиции
  void swap(s21_set &other);  // меняет содержимое
  void merge(s21_set &other);  // соединяет узлы из другого контейнера
  iterator find(const Key<T> &key);
  // находит элемент с определенным ключом

  iterator find(const T key);
  bool contains(const Key<T> &key);
  // проверяет, содержит ли контейнер элемент с определенным ключом

  template <typename... Arg>
  s21::s21_vector<std::pair<iterator, bool>> emplace(T value, Arg &&...args);
  bool emplace() { return true; }

 private:
  void back_to_root() override;
  Key<T> *go_to_begin(Key<T> *key);
  virtual void set_copy(Key<T> *other);
  virtual std::pair<iterator, bool> input_in_branch(Key<T> *branch, T value);
};
}  // namespace s21

#endif  // S21_SET_H
