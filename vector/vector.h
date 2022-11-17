#pragma once
#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <initializer_list>
#include <utility>

#include "../s21_abstract_class.h"

namespace s21 {
template <typename T>
class s21_vector : public abstract_containers_arr<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 private:
  void reserve_more_capacity(size_type size);
  void push_front(const_reference value);

 public:
  s21_vector() : abstract_containers_arr<T>() {}
  explicit s21_vector(size_type n);
  s21_vector(std::initializer_list<value_type> const &items);
  s21_vector(const s21_vector &v) : s21_vector(v.m_size) { *this = v; }
  s21_vector(s21_vector &&v);
  ~s21_vector() {
    if (this->arr_ != nullptr) delete[] this->arr_;
  }

  s21_vector<T> &operator=(const s21_vector &v);
  // Перегрузка оператора присваивания для движущегося объекта

  bool operator==(const s21_vector<T> &v);

  void reserve(size_type m_size);
  // выделяет хранилище элементов размера и копирует текущие элементы массива в
  // новый выделенный массив
  size_type get_capacity();
  // возвращает количество элементов, которые могут храниться в выделенной в
  // данный момент памяти

  void shrink_to_fit();
  // уменьшает использование памяти, освобождая неиспользуемую память

  void clear();  // очищает содержимое
  iterator insert(iterator pos, const_reference value);
  /*вставляет элементы в конкретную позицию
  и возвращает итератор, указывающий на новый элемент */

  void erase(iterator pos);  // стирает элемент в позиции
  void push_back(const_reference value);  // добавляет элемент в конец
  void pop_back();  // удаляет последний элемент
  void swap(s21_vector &other);  // меняет содержимое

  template <typename... Arg>
  iterator emplace(iterator pos, T value, Arg &&...args);
  iterator emplace(iterator pos) { return pos; }
  // вставляет новые элементы в контейнер непосредственно перед pos

  template <typename... Arg>
  void emplace_back(T value, Arg &&...args);
  // добавляет новые элементы в конец контейнера
  void emplace_back() {}
};
}  // namespace s21

#endif  // S21_VECTOR_H
