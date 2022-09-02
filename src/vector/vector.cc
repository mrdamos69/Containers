#include "vector.h"

template <typename T>
void s21::s21_vector<T>::reserve_more_capacity(size_t size) {
  if (size > this->m_capacity) {
    value_type *buff = new value_type[size]();
    for (size_t i = 0; i < this->m_size; ++i) buff[i] = std::move(this->arr[i]);
    delete[] this->arr;
    this->arr = buff;
    this->m_capacity = size;
  }
}

template <typename T>
s21::s21_vector<T>::s21_vector(size_type n) {
  this->m_capacity = this->m_size = n;
  this->arr = n ? new T[n]() : nullptr;
}

template <typename T>
s21::s21_vector<T>::s21_vector(s21_vector &&v) : s21_vector(v) {
  v.arr = nullptr;
  v.m_size = 0;
}

template <typename T>
s21::s21_vector<T>::s21_vector(std::initializer_list<value_type> const &items) {
  this->arr = new value_type[items.size()]();
  int i = 0;
  for (auto it = items.begin(); it != items.end(); it++) {
    this->arr[i] = *it;
    i++;
  }
  this->m_size = items.size();
  this->m_capacity = items.size();
  reserve_more_capacity(this->m_size * 2);
}

template <typename T>
s21::s21_vector<T> &s21::s21_vector<T>::operator=(const s21_vector<T> &v) {
  if (this->arr) {
    this->clear();
  }
  for (size_t i = 0; i <= v.m_size; i++) {
    this->push_back(v.arr[i]);
  }
  return *this;
}

template <typename T>
bool s21::s21_vector<T>::operator==(const s21_vector<T> &v) {
  if (this->m_size != v.m_size) {
    return false;
  }
  for (size_t i = 0; i < this->m_size; i++)
    if (this->arr[i] != v.arr[i]) {
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
    current[i] = this->arr[i];
  }
  delete[] this->arr;
  this->arr = new value_type[this->m_size]();
  this->m_capacity = this->m_size;
  for (size_t i = 0; i < this->m_size; i++) {
    this->arr[i] = current[i];
  }
}

template <typename T>
size_t s21::s21_vector<T>::max_size() {
  return (MAX_SIZE_VECTOR / sizeof(T)) * sizeof(T);
}

template <typename T>
void s21::s21_vector<T>::reserve(size_type m_size) {
  T *current = new value_type[m_size];
  for (size_t i = 0; i < m_size; i++) current[i] = this->arr[i];
}

template <typename T>
void s21::s21_vector<T>::push_back(const_reference value) {
  if (this->m_size == this->m_capacity) {
    reserve_more_capacity(this->m_size * 2);
  }
  this->arr[(this->m_size)++] = value;
}

template <typename T>
void s21::s21_vector<T>::pop_back() {
  T *current = new value_type[this->m_capacity];
  for (size_t i = 0, x = 0; i < this->m_capacity; i++, x++) {
    if (i != (this->m_size - 1))
      current[x] = this->arr[i];
    else
      x--;
  }
  this->m_size--;
  this->arr = current;
}

template <typename T>
void s21::s21_vector<T>::push_front(const_reference value) {
  T *current = new value_type[++(this->m_size)];
  *current = value;
  for (size_t i = 1, j = 0; i < this->m_size; i++, j++) {
    current[i] = this->arr[j];
  }
  delete[] this->arr;
  this->arr = current;
  reserve_more_capacity(this->m_size * 2);
}

template <typename T>
void s21::s21_vector<T>::swap(s21_vector &other) {
  s21_vector<T> temp(*this);
  *this = other;
  other = temp;
  other.m_size -= 1;
  this->m_size -= 1;
}

template <typename T>
T *s21::s21_vector<T>::insert(iterator pos, const_reference value) {
  bool flag = true;
  if (pos == this->begin()) {
    this->push_front(value);
  } else {
    value_type *buff = new value_type[this->m_capacity + 1];

    for (size_t i = 0, x = 0; i < this->m_capacity; i++, x++) {
      if ((pos == (this->arr + i)) || (pos == (this->arr + this->m_size))) {
        if (pos != (this->arr + this->m_size))
          buff[x++] = value;
        else
          buff[this->m_size] = value;
        flag = false;
      }
      buff[x] = this->arr[i];
    }
    if (!flag) {
      delete[] this->arr;
      this->m_size++;
      this->arr = buff;
    } else {
      delete[] buff;
      this->push_back(this->front());
    }
  }
  for (auto i = this->begin(); i != this->end(); ++i) {
    if (*i == value) return i;
  }
  return this->arr;
}

template <typename T>
void s21::s21_vector<T>::erase(iterator pos) {
  value_type *buff = new value_type[this->m_capacity - 1];
  for (size_t i = 0, x = 0; i < this->m_capacity; i++, x++) {
    if (pos == (this->arr + i - 1)) x--;
    buff[x] = this->arr[i];
  }
  delete[] this->arr;
  (this->m_size)--;
  this->arr = buff;
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
