#pragma once
#ifndef S21_MULTISET_H
#define S21_MULTISET_H
#include <initializer_list>
#include <iostream>
#include <utility>

#include "../set/set.h"
#define MAX_SIZE_MULTISET 230584300921369395

namespace s21 {
template <typename T>
class s21_multiset : public s21_set<T> {
 public:
  s21_multiset() : s21_set<T>() {}

  s21_multiset(std::initializer_list<T> const &items);

  s21_multiset(const s21_multiset<T> &ms);
  s21_multiset(s21_multiset<T> &&ms);

  s21::s21_multiset<T> operator=(const s21_multiset<T> &value);

  s21::iterator_set<T> insert(const T &value);

  std::pair<s21::iterator_set<T>, s21::iterator_set<T>> equal_range(
      const Key<T> &key);

  s21::iterator_set<T> lower_bound(const Key<T> &key);
  s21::iterator_set<T> upper_bound(const Key<T> &key);
  void swap(s21_multiset<T> &other);
  void merge(const s21_multiset &other);

  template <typename... Arg>
  std::pair<s21::iterator_set<T>, bool> emplace(T value, Arg &&...args);
  std::pair<s21::iterator_set<T>, bool> emplace();

 private:
  bool input_in_branch(Key<T> *branch, T value) override;
  void set_copy(Key<T> *other) override;
};
// #include "multiset.cc"
}  // namespace s21

#endif  // S21_MULTISET_H
