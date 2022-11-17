#include "multiset.h"

template <typename T>
s21::s21_multiset<T>::s21_multiset(std::initializer_list<T> const &items)
    : s21_set<T>() {
  for (auto &&i : items) {
    s21::s21_multiset<T>::insert(i);
  }
}

template <typename T>
s21::s21_multiset<T>::s21_multiset(const s21_multiset<T> &ms) : s21_set<T>() {
  this->set_copy(ms.element);
}

template <typename T>
s21::s21_multiset<T>::s21_multiset(s21_multiset &&s) : s21_multiset<T>(s) {
  s.clear();
}

template <typename T>
std::pair<s21::iterator_set<T>, bool> s21::s21_multiset<T>::insert(
    const T &value) {
  std::pair<iterator_set<T>, bool> result;
  if (this->element == nullptr) {
    this->element = new Key<T>();
    this->back_elem = new Key<T>();
    this->element->data_ = value;
    this->element->pRoot_ = this->element;
    this->element->pLeft_ = this->back_elem;
    this->element->pRight_ = this->back_elem;
    this->back_elem->data_ = ++(this->m_size);
  } else {
    result = input_in_branch(this->element, value);
  }
  this->I_ll_be_back();
  return result;
}

template <typename T>
std::pair<s21::iterator_set<T>, bool> s21::s21_multiset<T>::input_in_branch(
    Key<T> *branch, T value) {
  if (branch->data_ >= value) {
    if (branch->pLeft_ != this->back_elem) {
      input_in_branch(branch->pLeft_, value);
    } else {
      branch->pLeft_ = new Key<T>();
      branch->pLeft_->pBack_ = branch;
      branch = branch->pLeft_;
      branch->data_ = value;
      branch->pLeft_ = this->back_elem;
      branch->pRight_ = this->back_elem;
      this->back_elem->pBack_ = branch;
      this->back_elem->data_ = ++(this->m_size);
      return std::pair<s21::iterator_set<T>, bool>(branch, true);
    }
  } else if (branch->data_ < value) {
    if (branch->pRight_ != this->back_elem) {
      input_in_branch(branch->pRight_, value);
    } else {
      branch->pRight_ = new Key<T>();
      branch->pRight_->pBack_ = branch;
      branch = branch->pRight_;
      branch->data_ = value;
      branch->pLeft_ = this->back_elem;
      branch->pRight_ = this->back_elem;
      this->back_elem->pBack_ = branch;
      this->back_elem->data_ = ++(this->m_size);
      return std::pair<s21::iterator_set<T>, bool>(branch, true);
    }
  }
  return std::pair<s21::iterator_set<T>, bool>(this->end(), false);
}

template <typename T>
s21::s21_multiset<T> s21::s21_multiset<T>::operator=(
    const s21_multiset<T> &value) {
  s21_multiset<T> temp(value);
  std::swap(temp.element, this->element);
  std::swap(temp.back_elem, this->back_elem);
  std::swap(temp.m_size, this->m_size);
  return *this;
}

template <typename T>
void s21::s21_multiset<T>::swap(s21_multiset<T> &other) {
  s21_multiset<T> temp_set(*this);
  *this = other;
  other = temp_set;
}

template <typename T>
void s21::s21_multiset<T>::merge(const s21_multiset<T> &other) {
  this->set_copy(other.element);
}

template <typename T>
void s21::s21_multiset<T>::set_copy(Key<T> *other) {
  if (other->pLeft_ && other->pRight_) {
    this->set_copy(other->pLeft_);
    this->insert(other->data_);
    this->set_copy(other->pRight_);
  }
}

template <typename T>
s21::s21_vector<std::pair<typename s21::s21_set<T>::iterator, bool>>
s21::s21_multiset<T>::emplace() {
  s21::s21_vector<std::pair<typename s21::s21_set<T>::iterator, bool>> result;
  return result;
}

template <typename T>
template <typename... Arg>
s21::s21_vector<std::pair<typename s21::s21_set<T>::iterator, bool>>
s21::s21_multiset<T>::emplace(T value, Arg &&...args) {
  s21::s21_vector<std::pair<typename s21::s21_set<T>::iterator, bool>> result(
      this->m_size);
  result.push_back(this->insert(value));
  this->emplace(std::forward<Arg>(args)...);
  return result;
}
