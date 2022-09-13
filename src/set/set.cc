#include "set.h"

template <typename T>
bool s21::const_iterator_set<T>::operator==(const const_iterator_set &right) {
  return this->const_current == right.const_current;
}

template <typename T>
bool s21::const_iterator_set<T>::operator!=(const const_iterator_set &right) {
  return !(this->operator==(right));
}

template <typename T>
s21::iterator_set<T> &s21::iterator_set<T>::operator++() {
  if (it_end()) {
    this->const_current = this->const_current->pRight_;
    return *this;
  }

  if (this->const_current->pRoot_ == this->const_current) {
    this->const_current = this->const_current->pRight_;
    while (this->const_current->pLeft_->pLeft_ != nullptr) {
      this->const_current = this->const_current->pLeft_;
    }
    return *this;
  }

  if (this->const_current->data_ < this->const_current->pRight_->data_ &&
      this->const_current->pRight_->pRight_) {
    this->const_current = this->const_current->pRight_;

    while (this->const_current->pLeft_->pLeft_ != nullptr) {
      this->const_current = this->const_current->pLeft_;
    }
    return *this;
  }

  T temp = this->const_current->data_;
  this->const_current = this->const_current->pBack_;

  if (temp == this->const_current->pLeft_->data_) {
    return *this;
  } else if (temp == this->const_current->pRight_->data_) {
    this->const_current = this->const_current->pBack_;
    if (this->const_current->pRight_->pRight_ &&
        temp == this->const_current->pRight_->pRight_->data_) {
      this->const_current = this->const_current->pBack_;
    }
    return *this;
  }
  return *this;
}

template <typename T>
s21::iterator_set<T> &s21::iterator_set<T>::operator--() {
  if (this->const_current->pRoot_ == this->const_current) {
    this->const_current = this->const_current->pLeft_;
    while (this->const_current->pLeft_->pRight_ != nullptr) {
      this->const_current = this->const_current->pRight_;
    }
    return *this;
  }

  if (!this->const_current->pLeft_ && !this->const_current->pRight_) {
    this->const_current = this->const_current->pBack_;
    return *this;
  }

  if (this->const_current->pLeft_->data_ <= this->const_current->data_ &&
      this->const_current->pLeft_->pLeft_ != nullptr) {
    this->const_current = this->const_current->pLeft_;
    while (this->const_current->pRight_->pRight_ != nullptr) {
      this->const_current = this->const_current->pRight_;
    }
    return *this;
  }

  T temp = this->const_current->data_;
  this->const_current = this->const_current->pBack_;

  if (temp == this->const_current->pRight_->data_ &&
      this->const_current->pRight_ != nullptr) {
    return *this;
  }

  if (temp == this->const_current->pLeft_->data_) {
    this->const_current = this->const_current->pBack_;
    if (this->const_current->pLeft_->pLeft_ &&
        temp == this->const_current->pLeft_->pLeft_->data_) {
      while (this->const_current->pBack_ != nullptr) {
        this->const_current = this->const_current->pBack_;
      }
    }
    return *this;
  }
  return *this;
}

template <typename T>
s21::iterator_set<T> &s21::iterator_set<T>::operator++(int) {
  this->operator++();
  return *this;
}

template <typename T>
s21::iterator_set<T> &s21::iterator_set<T>::operator--(int) {
  this->operator--();
  return *this;
}

template <typename T>
bool s21::iterator_set<T>::it_end() {
  T it_end_count = this->const_current->data_;
  Key<T> *temp = this->const_current;
  while (temp->pBack_ != nullptr) {
    temp = temp->pBack_;
  }
  while (temp->pRight_->pRight_ != nullptr) {
    temp = temp->pRight_;
  }
  if (temp->data_ == it_end_count) {
    return true;
  }
  return false;
}

template <typename T>
s21::s21_set<T>::~s21_set() {
  if (this->element) this->clear();
}

template <typename T>
s21::s21_set<T>::s21_set(std::initializer_list<value_type> const &items)
    : s21_set() {
  for (auto &&i : items) {
    this->insert(i);
  }
}

template <typename T>
s21::s21_set<T>::s21_set(const s21_set<T> &s) : s21_set() {
  this->set_copy(s.element);
}

template <typename T>
s21::s21_set<T>::s21_set(s21_set &&s) {
  std::swap(this->element, s.element);
}

template <typename T>
s21::s21_set<T> s21::s21_set<T>::operator=(const s21_set &value) {
  s21_set<T> temp(value);
  std::swap(temp.element, this->element);
  std::swap(temp.back_elem, this->back_elem);
  std::swap(temp.m_size, this->m_size);
  return *this;
}

template <typename T>
typename s21::s21_set<T>::iterator s21::s21_set<T>::begin() {
  return go_to_begin(this->element);
}

template <typename T>
typename s21::s21_set<T>::iterator s21::s21_set<T>::end() {
  return this->back_elem;
}

template <typename T>
std::pair<s21::iterator_set<T>, bool> s21::s21_set<T>::insert(
    const value_type &value) {
  if (element == nullptr) {
    element = new Key<T>();
    back_elem = new Key<T>();
    element->pRoot_ = element;
    element->data_ = value;
    element->pLeft_ = element->pRight_ = back_elem;
    back_elem->data_ = ++(this->m_size);
    return std::pair<iterator, bool>(this->element, true);
  }
  std::pair<iterator, bool> result = input_in_branch(element, value);
  I_ll_be_back();
  return result;
}

template <typename T>
bool s21::s21_set<T>::contains(const Key<T> &key) {
  for (auto &&i : *this) {
    if (i == key.data_) {
      return true;
    }
  }
  return false;
}

template <typename T>
void s21::s21_set<T>::clear() {
  this->clear(this->element);
  this->m_size = 0;
  if (back_elem != nullptr) delete back_elem;
  this->back_elem = nullptr;
}

template <typename T>
void s21::s21_set<T>::clear(Key<T> *key) {
  if (key->pLeft_ && key->pRight_) {
    this->clear(key->pLeft_);
    this->clear(key->pRight_);
    if (key != nullptr) delete key;
    key = nullptr;
    (this->m_size)--;
  }
}

template <typename T>
void s21::s21_set<T>::back_to_root() {
  while (element->pBack_ != nullptr) {
    element = element->pBack_;
  }
}

template <typename T>
void s21::s21_set<T>::erase(iterator pos) {
  for (auto &&i = begin(); i != end(); ++i) {
    if (*i == pos.const_current->data_) {
      if ((pos.const_current->pLeft_ == back_elem) &&
          (pos.const_current->pRight_ == back_elem)) {
        if (pos.const_current->pBack_->pRight_->data_ ==
            pos.const_current->data_) {
          pos.const_current->pBack_->pRight_ = back_elem;
        }
        if (pos.const_current->pBack_->pLeft_->data_ ==
            pos.const_current->data_) {
          pos.const_current->pBack_->pLeft_ = back_elem;
        }
        if (pos.const_current != nullptr) delete pos.const_current;
        (this->m_size)--;
        break;
      } else {
        if (pos.const_current->pRoot_ == pos.const_current) {
          Key<T> *temp_key = pos.const_current;
          pos.const_current = pos.const_current->pRight_;
          while (pos.const_current->pLeft_ != back_elem) {
            pos.const_current = pos.const_current->pLeft_;
          }
          temp_key->data_ = pos.const_current->data_;
          pos.const_current->pBack_->pLeft_ = back_elem;
          if (pos.const_current != nullptr) delete pos.const_current;
          (this->m_size)--;
          break;
        } else {
          back_to_root();
          if (pos.const_current->pBack_->pRight_->data_ ==
              pos.const_current->data_) {
            pos.const_current->pBack_->pRight_ = back_elem;
          }
          if (pos.const_current->pBack_->pLeft_->data_ ==
              pos.const_current->data_) {
            pos.const_current->pBack_->pLeft_ = back_elem;
          }
          pos.const_current->pBack_ = nullptr;
          set_copy(pos.const_current->pLeft_);
          set_copy(pos.const_current->pRight_);
          this->clear(pos.const_current);
          break;
        }
      }
    }
  }
}

template <typename T>
void s21::s21_set<T>::swap(s21_set &other) {
  std::swap(other.element, this->element);
  std::swap(other.back_elem, this->back_elem);
  std::swap(other.m_size, this->m_size);
}

template <typename T>
void s21::s21_set<T>::merge(s21_set &other) {
  s21::s21_set<T> temp(this->set_merge(other));
  other = temp;
}

template <typename T>
s21::s21_set<T> s21::s21_set<T>::set_merge(s21_set &other) {
  s21::s21_set<T> new_other;
  for (auto x = other.begin(); x != other.end(); ++x) {
    for (auto i = this->begin(); i != this->end(); ++i) {
      if (*x == *i) new_other.insert(*x);
    }
  }
  this->set_copy(other.element);
  return new_other;
}

template <typename T>
void s21::s21_set<T>::set_copy(Key<T> *other) {
  if (other->pLeft_ != nullptr && other->pLeft_ && other->pRight_) {
    this->set_copy(other->pLeft_);
    this->insert(other->data_);
    this->set_copy(other->pRight_);
  }
}

template <typename T>
typename s21::s21_set<T>::iterator s21::s21_set<T>::find(const Key<T> &key) {
  for (auto i = begin(); i != end(); ++i) {
    if (*i == key.data_) {
      return i;
    }
  }
  return iterator();
}

template <typename T>
typename s21::s21_set<T>::iterator s21::s21_set<T>::find(const T key) {
  for (auto i = begin(); i != end(); ++i) {
    if (*i == key) {
      return i;
    }
  }
  return iterator();
}

template <typename T>
std::pair<typename s21::s21_set<T>::iterator, bool>
s21::s21_set<T>::input_in_branch(Key<T> *branch, T value) {
  if (branch->data_ > value) {
    if (branch->pLeft_ != back_elem) {
      input_in_branch(branch->pLeft_, value);
    } else {
      branch->pLeft_ = new Key<T>();
      branch->pLeft_->pBack_ = branch;
      branch = branch->pLeft_;
      branch->data_ = value;
      branch->pLeft_ = branch->pRight_ = back_elem;
      back_elem->pBack_ = branch;
      back_elem->data_ = ++(this->m_size);
      return std::pair<iterator, bool>(branch, true);
    }
  } else if (branch->data_ < value) {
    if (branch->pRight_ != back_elem) {
      input_in_branch(branch->pRight_, value);
    } else {
      branch->pRight_ = new Key<T>();
      branch->pRight_->pBack_ = branch;
      branch = branch->pRight_;
      branch->data_ = value;
      branch->pLeft_ = branch->pRight_ = back_elem;
      back_elem->pBack_ = branch;
      back_elem->data_ = ++(this->m_size);
      return std::pair<iterator, bool>(branch, true);
    }
  }
  return std::pair<iterator, bool>(this->end(), false);
}

template <typename T>
void s21::s21_set<T>::I_ll_be_back() {
  back_to_root();
  while (this->element->pRight_ != back_elem) {
    this->element = this->element->pRight_;
  }
  back_elem->pBack_ = this->element;
  back_to_root();
}

template <typename T>
s21::Key<T> *s21::s21_set<T>::go_to_begin(Key<T> *key) {
  while (key->pLeft_ != back_elem) key = key->pLeft_;
  return key;
}

template <typename T>
template <typename... Arg>
s21::s21_vector<std::pair<typename s21::s21_set<T>::iterator, bool>>
s21::s21_set<T>::emplace(T value, Arg &&...args) {
  s21::s21_vector<std::pair<typename s21::s21_set<T>::iterator, bool>> result(
      this->m_size);
  result.push_back(this->insert(value));
  this->emplace(std::forward<Arg>(args)...);
  return result;
}
