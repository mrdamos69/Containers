#include "vector.h"

template <typename T>
void s21::s21_vector<T>::reserve_more_capacity(size_t size) {
  if (size >= this->m_capacity) {
    value_type *buff = new value_type[size]();
    for (size_t i = 0; i < this->m_size; ++i)
      buff[i] = std::move(this->arr_[i]);
    if (this->arr_ != nullptr) delete[] this->arr_;
    this->arr_ = nullptr;
    this->arr_ = buff;
    this->m_capacity = size;
  }
}

template <typename T>
s21::s21_vector<T>::s21_vector(size_type n) {
  this->m_capacity = this->m_size = n;
  this->arr_ = n ? new T[n]() : nullptr;
}

template <typename T>
s21::s21_vector<T>::s21_vector(s21_vector &&v) : s21_vector(v) {
  if (this->arr_ != v.arr_) {
    v.arr_ = nullptr;
    v.m_size = 0;
  } else {
    throw std::invalid_argument("s21_map argument too large.");
  }
}

template <typename T>
s21::s21_vector<T>::s21_vector(std::initializer_list<value_type> const &items) {
  this->arr_ = new value_type[items.size()]();
  int i = 0;
  for (auto it = items.begin(); it != items.end(); it++) {
    this->arr_[i] = *it;
    i++;
  }
  this->m_size = items.size();
  this->m_capacity = items.size();
  reserve_more_capacity(this->m_size * 2);
}

template <typename T>
s21::s21_vector<T> &s21::s21_vector<T>::operator=(const s21_vector<T> &v) {
  if (this->arr_) this->clear();
  for (size_t i = 0; i < v.m_size; i++) {
    this->push_back(v.arr_[i]);
  }
  return *this;
}

template <typename T>
bool s21::s21_vector<T>::operator==(const s21_vector<T> &v) {
  if (this->m_size != v.m_size) {
    return false;
  }
  for (size_t i = 0; i < this->m_size; i++)
    if (this->arr_[i] != v.arr_[i]) {
      return false;
    }
  return true;
}

template <typename T>
size_t s21::s21_vector<T>::get_capacity() {
  return this->m_capacity;
}

template <typename T>
void s21::s21_vector<T>::shrink_to_fit() {
  T *current = new value_type[this->m_size];
  for (size_t i = 0; i < this->m_size; i++) {
    current[i] = this->arr_[i];
  }
  this->m_capacity = this->m_size;
  std::swap(this->arr_, current);
  if (current != nullptr) delete[] current;
}

template <typename T>
void s21::s21_vector<T>::reserve(size_type m_size) {
  if (m_size > this->m_size) {
    T *current = new value_type[m_size]();
    for (size_t i = 0; i < m_size; i++) current[i] = this->arr_[i];
    std::swap(this->arr_, current);
    if (current != nullptr) delete[] current;
  }
}

template <typename T>
void s21::s21_vector<T>::push_back(const_reference value) {
  if (this->m_size == this->m_capacity) {
    reserve_more_capacity(this->m_size * 2);
  }
  this->arr_[(this->m_size)++] = value;
}

template <typename T>
void s21::s21_vector<T>::pop_back() {
  T *current = new value_type[this->m_capacity];
  for (size_t i = 0, x = 0; i < this->m_capacity; i++, x++) {
    if (i != (this->m_size - 1))
      current[x] = this->arr_[i];
    else
      x--;
  }
  this->m_size--;
  std::swap(this->arr_, current);
  if (current != nullptr) delete[] current;
}

template <typename T>
void s21::s21_vector<T>::push_front(const_reference value) {
  T *current = new value_type[++(this->m_size)];
  *current = value;
  for (size_t i = 1, j = 0; i < this->m_size; i++, j++) {
    current[i] = this->arr_[j];
  }
  if (this->arr_ != nullptr) delete[] this->arr_;
  this->arr_ = current;
  reserve_more_capacity(this->m_size * 2);
}

template <typename T>
void s21::s21_vector<T>::swap(s21_vector &other) {
  std::swap(this->arr_, other.arr_);
  std::swap(this->m_size, other.m_size);
  std::swap(this->m_capacity, other.m_capacity);
}

template <typename T>
T *s21::s21_vector<T>::insert(iterator pos, const_reference value) {
  bool flag = true;
  if (pos == this->begin()) {
    this->push_front(value);
  } else {
    value_type *buff = new value_type[this->m_capacity + 1];

    for (size_t i = 0, x = 0; i < this->m_capacity; i++, x++) {
      if ((pos == (this->arr_ + i)) || (pos == (this->arr_ + this->m_size))) {
        if (pos != (this->arr_ + this->m_size))
          buff[x++] = value;
        else
          buff[this->m_size] = value;
        flag = false;
      }
      buff[x] = this->arr_[i];
    }
    if (!flag) {
      if (this->arr_ != nullptr) delete[] this->arr_;
      this->m_size++;
      this->arr_ = buff;
    } else {
      if (buff != nullptr) delete[] buff;
      this->push_back(this->front());
    }
  }
  for (auto i = this->begin(); i != this->end(); ++i) {
    if (*i == value) return i;
  }
  return this->arr_;
}

template <typename T>
void s21::s21_vector<T>::erase(iterator pos) {
  value_type *buff = new value_type[this->m_capacity - 1];
  for (size_t i = 0, x = 0; i < this->m_capacity; i++, x++) {
    if (pos == (this->arr_ + i - 1)) x--;
    buff[x] = this->arr_[i];
  }
  if (this->arr_ != nullptr) delete[] this->arr_;
  (this->m_size)--;
  this->arr_ = buff;
}

template <typename T>
void s21::s21_vector<T>::clear() {
  while (this->m_size) {
    this->pop_back();
  }
}

template <typename T>
template <typename... Arg>
typename s21::s21_vector<T>::iterator s21::s21_vector<T>::emplace(
    iterator pos, T value, Arg &&...args) {
  pos = insert(pos, value);
  this->emplace(pos, args...);
  return pos;
}

template <typename T>
template <typename... Arg>
void s21::s21_vector<T>::emplace_back(T value, Arg &&...args) {
  this->push_back(value);
  this->emplace_back(args...);
}
