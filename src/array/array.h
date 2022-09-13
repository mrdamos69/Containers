#pragma once
#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include <initializer_list>
#include <utility>

#include "../s21_abstract_class.h"

namespace s21 {
template <typename T, size_t SIZE>
class s21_array : public abstract_containers_arr<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  s21_array();
  s21_array(std::initializer_list<value_type> const &items);

  s21_array(const s21_array &v);

  s21_array(s21_array &&v) : s21_array(v) { v.clear(); }
  ~s21_array() {
    if (this->arr_ != nullptr) delete[] this->arr_;
  }

  s21_array<T, SIZE> &operator=(const s21_array<T, SIZE> &v);
  // Перегрузка оператора присваивания для движущегося объекта

  bool operator==(const s21_array<T, SIZE> &v);

  size_t max_size() override;
  // возвращает максимально возможное количество элементов

  void clear();                 // очищает содержимое
  void swap(s21_array &other);  // меняет содержимое
  void fill(const_reference value);
  // присваивает заданное значение value всем элементам в контейнере
};
}  // namespace s21

#endif  // S21_ARRAY_H
