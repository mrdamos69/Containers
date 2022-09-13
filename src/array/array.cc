#include "array.h"

template <typename T, size_t SIZE>
s21::s21_array<T, SIZE>::s21_array() : abstract_containers_arr<T>() {
  this->m_size = SIZE;
  this->arr_ = new value_type[SIZE]();
}

template <typename T, size_t SIZE>
s21::s21_array<T, SIZE>::s21_array(const s21_array &v) : s21_array() {
  if (this->arr_ != nullptr) delete[] this->arr_;
  this->arr_ = new value_type[this->m_size]();
  for (size_t i = 0; i < this->m_size; i++) {
    this->arr_[i] = v.arr_[i];
  }
}

template <typename T, size_t SIZE>
s21::s21_array<T, SIZE>::s21_array(
    std::initializer_list<value_type> const &items) {
  this->arr_ = new value_type[SIZE];
  for (size_t i = 0; i < SIZE; i++) this->arr_[i] = 0;
  int i = 0;
  for (auto it = items.begin(); it != items.end(); it++) {
    this->arr_[i] = *it;
    i++;
  }
  this->m_size = SIZE;
}

template <typename T, size_t SIZE>
s21::s21_array<T, SIZE> &s21::s21_array<T, SIZE>::operator=(
    const s21_array<T, SIZE> &v) {
  for (size_t i = 0; i <= v.m_size; i++) {
    this->arr_[i] = v.arr_[i];
  }
  return *this;
}

template <typename T, size_t SIZE>
bool s21::s21_array<T, SIZE>::operator==(const s21_array<T, SIZE> &v) {
  if (this->m_size != v.m_size) {
    return false;
  }
  for (size_t i = 0; i < this->m_size; i++) {
    if (this->arr_[i] != v.arr_[i]) {
      return false;
    }
  }
  return true;
}

template <typename T, size_t SIZE>
size_t s21::s21_array<T, SIZE>::max_size() {
  return this->m_size;
}

template <typename T, size_t SIZE>
void s21::s21_array<T, SIZE>::swap(s21_array &other) {
  std::swap(this->arr_, other.arr_);
  std::swap(this->m_size, other.m_size);
}

template <typename T, size_t SIZE>
void s21::s21_array<T, SIZE>::fill(const_reference value) {
  for (auto &&i : *this) i = value;
}
