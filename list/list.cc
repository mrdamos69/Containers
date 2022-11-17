#include "list.h"

template <typename T>
bool s21::const_iterator_cl<T>::operator==(const const_iterator_cl<T> &right) {
  return (this->const_current->data_ == right.const_current->data_);
}

template <typename T>
bool s21::const_iterator_cl<T>::operator!=(const const_iterator_cl &right) {
  return !(this->const_current->data_ == right.const_current->data_);
}

template <typename T>
s21::iterator_cl<T> &s21::iterator_cl<T>::operator++() {
  if (this->const_current->pNext_ != nullptr)
    this->const_current = this->const_current->pNext_;
  else
    this->const_current = this->begin_current;
  return *this;
}

template <typename T>
s21::iterator_cl<T> &s21::iterator_cl<T>::operator--() {
  if (this->const_current->pBack_ != nullptr)
    this->const_current = this->const_current->pBack_;
  return *this;
}

template <typename T>
s21::iterator_cl<T> &s21::iterator_cl<T>::operator++(int) {
  this->operator++();
  return *this;
}

template <typename T>
s21::iterator_cl<T> &s21::iterator_cl<T>::operator--(int) {
  this->operator--();
  return *this;
}

template <typename T>
void s21::iterator_cl<T>::set_current(Node<T> *other) {
  this->const_current = other;
}

template <typename T>
s21::s21_list<T>::s21_list(size_type n) : s21_list() {
  while (n--) this->push_back(0);
}

template <typename T>
s21::s21_list<T>::s21_list(const s21_list &l) : s21_list() {
  Node<value_type> *current = l.head_;
  while (current != l.tail_) {
    this->push_back(current->data_);
    current = current->pNext_;
  }
}

template <typename T>
s21::s21_list<T>::s21_list(s21_list &&l) : s21_list<T>(l) {
  if (this->head_ == l.head_)
    throw std::invalid_argument("s21_list argument too large.");
  l.clear();
}

template <typename T>
s21::s21_list<T>::s21_list(std::initializer_list<value_type> const &items)
    : s21_list() {
  for (auto &i : items) {
    this->push_back(i);
  }
}

template <typename T>
s21::s21_list<T>::~s21_list() {
  this->clear();
}

template <typename T>
void s21::s21_list<T>::push_back(value_type data_) {
  if (this->head_ == nullptr && this->tail_ == nullptr) {
    this->head_ = new Node<T>(data_);
    this->tail_ = new Node<T>;
    this->head_->pNext_ = this->tail_;
    this->tail_->pNext_ = nullptr;
  } else {
    Node<T> *current = this->head_;
    while (current->pNext_ != this->tail_) {
      current = current->pNext_;
    }
    Node<T> *temp = current;
    current->pNext_ = new Node<T>(data_);
    current = current->pNext_;
    current->pBack_ = temp;
    this->tail_->pBack_ = current;
    current->pNext_ = this->tail_;
  }
  (this->m_size)++;
}

template <typename T>
void s21::s21_list<T>::push_front(value_type data_) {
  if (this->head_ == nullptr && this->tail_ == nullptr) {
    this->head_ = new Node<value_type>(data_, this->head_);
    this->tail_ = new Node<T>;
    this->head_->pNext_ = this->tail_;
    this->tail_->pBack_ = this->head_;
    this->tail_->pNext_ = nullptr;
  } else {
    this->head_ = new Node<value_type>(data_, this->head_);
  }
  (this->m_size)++;
}

template <typename T>
void s21::s21_list<T>::pop_back() {
  this->erase(this->m_size - 1);
}

template <typename T>
void s21::s21_list<T>::pop_front() {
  Node<value_type> *current = this->head_;
  this->head_ = this->head_->pNext_;
  if (current != nullptr) delete current;
  (this->m_size)--;
}

template <typename T>
T &s21::s21_list<T>::operator[](const int index) {
  int counter = 0;
  Node<value_type> *current = this->head_;
  while (current != nullptr) {
    if (counter == index) {
      return current->data_;
    }
    current = current->pNext_;
    counter++;
  }
  return this->head_->data_;
}

template <typename T>
s21::s21_list<T> &s21::s21_list<T>::operator=(const s21_list &l) {
  if (this->head_) {
    this->clear();
  }
  this->set_copy(l.head_, l.tail_);
  return *this;
}

template <typename T>
void s21::s21_list<T>::set_copy(Node<T> *other, Node<T> *end) {
  if (other != end) {
    this->push_back(other->data_);
    this->set_copy(other->pNext_, end);
  }
}

template <typename T>
typename s21::s21_list<T>::iterator s21::s21_list<T>::insert(size_t index,
                                                             value_type value) {
  auto result = this->begin();
  if (index == 0) {
    push_front(value);
  } else {
    Node<T> *current = this->head_;
    for (size_t i = 0; i < index - 1; i++, ++result) {
      current = current->pNext_;
    }
    current->pNext_ = new Node<value_type>(value, current->pNext_);
    (this->m_size)++;
  }
  return ++result;
}

template <typename T>
typename s21::s21_list<T>::iterator s21::s21_list<T>::insert(
    iterator pos, const_reference value) {
  size_t index = 0;
  Node<T> *current;
  for (auto i = this->begin(); i != this->end(); ++i, index++) {
    if (pos == i) break;
  }
  if (index == 0) {
    push_front(value);
  } else {
    current = this->head_;
    for (size_t y = 0; y < index - 1; y++) {
      current = current->pNext_;
    }
    current->pNext_ = new Node<value_type>(value, current->pNext_);
    (this->m_size)++;
  }
  iterator_cl<T> result;
  result.const_current = current->pNext_;
  return result;
}

template <typename T>
void s21::s21_list<T>::erase(int index) {
  if (index == 0) {
    pop_front();
  } else {
    Node<value_type> *current = this->head_;
    for (int i = 0; i < index - 1; i++) {
      current = current->pNext_;
    }
    Node<value_type> *to_delete = current->pNext_;
    current->pNext_ = to_delete->pNext_;
    if (to_delete != nullptr) delete to_delete;
    (this->m_size)--;
  }
}

template <typename T>
void s21::s21_list<T>::swap(s21_list &other) {
  s21_list<T> temp(*this);
  *this = other;
  other = temp;
}

template <typename T>
void s21::s21_list<T>::reverse() {
  s21_list<T> temp;
  for (auto &&i : *this) {
    temp.push_front(i);
  }
  *this = temp;
}

template <typename T>
void s21::s21_list<T>::sort() {
  s21_list<T> temp_this;
  temp_this = *this;
  T temp;
  for (size_t i = 0; i < this->m_size - 1; i++) {
    for (size_t j = 0; j < this->m_size - i - 1; j++) {
      if (temp_this[j] > temp_this[j + 1]) {
        temp = temp_this[j];
        temp_this[j] = temp_this[j + 1];
        temp_this[j + 1] = temp;
      }
    }
  }
  *this = temp_this;
}

template <typename T>
void s21::s21_list<T>::merge(const s21_list &other) {
  this->set_copy(other.head_, other.tail_);
  this->sort();
}

template <typename T>
void s21::s21_list<T>::unique() {
  Node<value_type> *current = this->head_;
  s21_list<T> temp;
  T temp_data;
  while (current != this->tail_) {
    if (temp_data != current->data_) {
      temp.push_back(current->data_);
      temp_data = current->data_;
    }
    current = current->pNext_;
  }
  *this = temp;
}

template <typename T>
void s21::s21_list<T>::splice(const_iterator pos, s21_list other) {
  iterator_cl<T> temp_iter;
  temp_iter.set_current(pos.const_current);
  for (auto &&i : *this) {
    if (i == *pos) {
      for (auto &&y : other) {
        this->insert(temp_iter, y);
      }
      break;
    }
  }
}

template <typename T>
size_t s21::s21_list<T>::max_size() {
  return MAX_SIZE_LIST;
}

template <typename T>
void s21::s21_list<T>::clear() {
  while (this->m_size) {
    this->pop_front();
  }
  if (this->tail_ != nullptr) {
    if (this->tail_ != nullptr) delete this->tail_;
  }
  this->tail_ = nullptr;
  this->head_ = nullptr;
}

template <typename T>
const T &s21::s21_list<T>::front() {
  return this->head_->data_;
}

template <typename T>
const T &s21::s21_list<T>::back() {
  if (this->head_ == nullptr) {
    return this->head_->data_;
  } else {
    Node<value_type> *current = this->head_;
    while (current->pNext_ != this->tail_) {
      current = current->pNext_;
    }
    return current->data_;
  }
}

template <typename T>
template <typename... Arg>
typename s21::s21_list<T>::iterator s21::s21_list<T>::emplace(iterator pos,
                                                              T value,
                                                              Arg &&...args) {
  pos = insert(pos, value);
  this->emplace(pos, args...);
  return pos;
}

template <typename T>
template <typename... Arg>
void s21::s21_list<T>::emplace_back(T value, Arg &&...args) {
  this->push_back(value);
  this->emplace_back(args...);
}

template <typename T>
template <typename... Arg>
void s21::s21_list<T>::emplace_front(T value, Arg &&...args) {
  this->push_front(value);
  this->emplace_front(args...);
}
