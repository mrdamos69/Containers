#include "map.h"

template <typename T, typename T2>
bool s21::const_iterator_map<T, T2>::operator==(
    const const_iterator_map &right) {
  return this->const_current == right.const_current;
}

template <typename T, typename T2>
bool s21::const_iterator_map<T, T2>::operator!=(
    const const_iterator_map &right) {
  return !(this->operator==(right));
}

template <typename T, typename T2>
s21::iterator_map<T, T2> &s21::iterator_map<T, T2>::operator++() {
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

  if (this->const_current->data_.first <
          this->const_current->pRight_->data_.first &&
      this->const_current->pRight_->pRight_) {
    this->const_current = this->const_current->pRight_;

    while (this->const_current->pLeft_->pLeft_ != nullptr) {
      this->const_current = this->const_current->pLeft_;
    }
    return *this;
  }

  T temp = this->const_current->data_.first;
  this->const_current = this->const_current->pBack_;

  if (temp == this->const_current->pLeft_->data_.first) {
    return *this;
  } else if (temp == this->const_current->pRight_->data_.first) {
    this->const_current = this->const_current->pBack_;
    if (this->const_current->pRight_->pRight_ &&
        temp == this->const_current->pRight_->pRight_->data_.first) {
      this->const_current = this->const_current->pBack_;
    }
    return *this;
  }
  return *this;
}

template <typename T, typename T2>
s21::iterator_map<T, T2> &s21::iterator_map<T, T2>::operator--() {
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

  if (this->const_current->pLeft_->data_.first <
          this->const_current->data_.first &&
      this->const_current->pLeft_->pLeft_ != nullptr) {
    this->const_current = this->const_current->pLeft_;
    while (this->const_current->pRight_->pRight_ != nullptr) {
      this->const_current = this->const_current->pRight_;
    }
    return *this;
  }

  T temp = this->const_current->data_.first;
  this->const_current = this->const_current->pBack_;

  if (temp == this->const_current->pRight_->data_.first &&
      this->const_current->pRight_ != nullptr) {
    return *this;
  }

  if (temp == this->const_current->pLeft_->data_.first) {
    this->const_current = this->const_current->pBack_;
    if (this->const_current->pLeft_->pLeft_ &&
        temp == this->const_current->pLeft_->pLeft_->data_.first) {
      while (this->const_current->pBack_ != nullptr) {
        this->const_current = this->const_current->pBack_;
      }
    }
    return *this;
  }
  return *this;
}

template <typename T, typename T2>
bool s21::iterator_map<T, T2>::it_end() {
  T it_end_count = this->const_current->data_.first;
  Key_Map<T, T2> *temp = this->const_current;
  while (temp->pBack_ != nullptr) {
    temp = temp->pBack_;
  }
  while (temp->pRight_->pRight_ != nullptr) {
    temp = temp->pRight_;
  }
  if (temp->data_.first == it_end_count) {
    return true;
  }
  return false;
}

template <typename T, typename T2>
s21::s21_map<T, T2>::~s21_map() {
  if (this->element) this->clear();
}

template <typename T, typename T2>
s21::s21_map<T, T2>::s21_map(std::initializer_list<value_type> const &items)
    : element(nullptr), back_elem(nullptr) {
  for (auto &&i : items) {
    this->insert(i);
  }
}

template <typename T, typename T2>
s21::s21_map<T, T2>::s21_map(const s21_map &m)
    : element(nullptr), back_elem(nullptr) {
  this->set_copy(m.element);
}

template <typename T, typename T2>
s21::s21_map<T, T2>::s21_map(s21_map &&m)
    : element(nullptr), back_elem(nullptr) {
  this->set_copy(m.element);
  m.clear();
}

template <typename T, typename T2>
s21::s21_map<T, T2> s21::s21_map<T, T2>::operator=(const s21_map &m) {
  s21_map<T, T2> temp(m);
  std::swap(temp.element, this->element);
  std::swap(temp.back_elem, this->back_elem);
  std::swap(temp.m_size, this->m_size);
  return *this;
}

template <typename T, typename T2>
T &s21::s21_map<T, T2>::at(const Key_Map<key_type, mapped_type> &key) {
  for (auto i = this->begin(); i != this->end(); ++i) {
    if ((*i).first == key.data_.first) {
      if ((*i).second == key.data_.second) {
        return i.const_current->data_.second;
      }
    }
  }
  throw std::invalid_argument("s21_map argument too large.");
}

template <typename T, typename T2>
T2 &s21::s21_map<T, T2>::operator[](const Key_Map<key_type, mapped_type> &key) {
  for (auto i = this->begin(); i != this->end(); ++i) {
    if ((*i).first == key.data_.first) {
      if ((*i).second == key.data_.second) {
        return i.const_current->data_.second;
      }
    }
  }
  this->insert(key.data_);
  return this->element->data_.second;
}

template <typename T, typename T2>
T2 &s21::s21_map<T, T2>::operator[](const key_type &key) {
  for (auto i = this->begin(); i != this->end(); ++i) {
    if ((*i).first == key) {
      return i.const_current->data_.second;
    }
  }
  return this->element->data_.second;
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::clear() {
  clear(this->element);
  if (back_elem != nullptr) delete back_elem;
  this->m_size = 0;
  this->back_elem = nullptr;
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::clear(Key_Map<key_type, mapped_type> *key) {
  if (key->pLeft_ && key->pRight_) {
    this->clear(key->pLeft_);
    this->clear(key->pRight_);
    if (key != nullptr) delete key;
    (this->m_size)--;
  }
}

template <typename T, typename T2>
typename s21::s21_map<T, T2>::iterator s21::s21_map<T, T2>::begin() {
  return go_to_begin(this->element);
}
template <typename T, typename T2>
typename s21::s21_map<T, T2>::iterator s21::s21_map<T, T2>::end() {
  return this->back_elem;
}

template <typename T, typename T2>
std::pair<typename s21::s21_map<T, T2>::iterator, bool>
s21::s21_map<T, T2>::insert(
    const typename s21::s21_map<T, T2>::value_type &value) {
  if (element == nullptr) {
    element = new Key_Map<T, T2>();
    back_elem = new Key_Map<T, T2>();
    element->pRoot_ = element;
    element->data_ = value;
    element->pLeft_ = back_elem;
    element->pRight_ = back_elem;
    ++(this->m_size);
    return std::pair<iterator, bool>(this->element, true);
  }
  std::pair<iterator, bool> result = input_in_branch(element, value);
  I_ll_be_back();
  return result;
}

template <typename T, typename T2>
std::pair<typename s21::s21_map<T, T2>::iterator, bool>
s21::s21_map<T, T2>::input_in_branch(
    s21::Key_Map<T, T2> *branch,
    const typename s21::s21_map<T, T2>::value_type &value) {
  if (branch->data_.first > value.first) {
    if (branch->pLeft_ != back_elem) {
      input_in_branch(branch->pLeft_, value);
    } else {
      branch->pLeft_ = new Key_Map<T, T2>();
      branch->pLeft_->pBack_ = branch;
      branch = branch->pLeft_;
      branch->data_ = value;
      branch->pLeft_ = back_elem;
      branch->pRight_ = back_elem;
      back_elem->pBack_ = branch;
      ++(this->m_size);
      return std::pair<iterator, bool>(branch, true);
    }
  } else if (branch->data_.first < value.first) {
    if (branch->pRight_ != back_elem) {
      input_in_branch(branch->pRight_, value);
    } else {
      branch->pRight_ = new Key_Map<T, T2>();
      branch->pRight_->pBack_ = branch;
      branch = branch->pRight_;
      branch->data_ = value;
      branch->pLeft_ = back_elem;
      branch->pRight_ = back_elem;
      back_elem->pBack_ = branch;
      ++(this->m_size);
      return std::pair<iterator, bool>(branch, true);
    }
  }
  return std::pair<iterator, bool>(this->end(), false);
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::I_ll_be_back() {
  back_to_root();
  while (this->element->pRight_ != back_elem) {
    this->element = this->element->pRight_;
  }
  back_elem->pBack_ = this->element;
  back_to_root();
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::back_to_root() {
  while (element->pBack_ != nullptr) {
    element = element->pBack_;
  }
}

template <typename T, typename T2>
std::pair<typename s21::s21_map<T, T2>::iterator, bool>
s21::s21_map<T, T2>::insert(const key_type &key, const mapped_type &obj) {
  for (auto i = this->begin(); i != this->end(); ++i) {
    if ((*i).first == key) {
      return std::pair<s21::s21_map<T, T2>::iterator, bool>(i, false);
    }
  }
  this->back_to_root();
  return this->insert(std::pair<T, T2>(key, obj));
}

template <typename T, typename T2>
std::pair<typename s21::s21_map<T, T2>::iterator, bool>
s21::s21_map<T, T2>::insert_or_assign(const key_type &key,
                                      const mapped_type &obj) {
  for (auto i = this->begin(); i != this->end(); ++i) {
    if ((*i).first == key) {
      (*i).second = obj;
      return std::pair<s21::s21_map<T, T2>::iterator, bool>(i, true);
    }
  }
  this->back_to_root();
  return this->insert(std::pair<T, T2>(key, obj));
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::erase(typename s21::s21_map<T, T2>::iterator pos) {
  for (auto &&i = begin(); i != end(); ++i) {
    if (*i == pos.const_current->data_) {
      if ((pos.const_current->pLeft_ == back_elem) &&
          (pos.const_current->pRight_ == back_elem)) {
        if (pos.const_current->pBack_->pRight_->data_.first ==
            pos.const_current->data_.first) {
          pos.const_current->pBack_->pRight_ = back_elem;
        }
        if (pos.const_current->pBack_->pLeft_->data_.first ==
            pos.const_current->data_.first) {
          pos.const_current->pBack_->pLeft_ = back_elem;
        }
        if (pos.const_current != nullptr) delete pos.const_current;
        (this->m_size)--;
        break;
      } else {
        if (pos.const_current->pRoot_ == pos.const_current) {
          Key_Map<T, T2> *temp_data = pos.const_current;
          pos.const_current = pos.const_current->pRight_;
          while (pos.const_current->pLeft_ != back_elem) {
            pos.const_current = pos.const_current->pLeft_;
          }
          temp_data->data_ = pos.const_current->data_;
          pos.const_current->pBack_->pLeft_ = back_elem;
          if (pos.const_current != nullptr) delete pos.const_current;
          (this->m_size)--;
          break;
        } else {
          back_to_root();

          if (pos.const_current->pBack_->pRight_->data_.first ==
              pos.const_current->data_.first) {
            pos.const_current->pBack_->pRight_ = back_elem;
          }
          if (pos.const_current->pBack_->pLeft_->data_.first ==
              pos.const_current->data_.first) {
            pos.const_current->pBack_->pLeft_ = back_elem;
          }
          pos.const_current->pBack_ = nullptr;
          set_copy(pos.const_current->pLeft_);
          set_copy(pos.const_current->pRight_);
          this->clear(pos.const_current);
          (this->m_size)--;
          break;
        }
      }
    }
  }
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::swap(s21_map &other) {
  s21_map<T, T2> temp_set(*this);
  *this = other;
  other = temp_set;
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::merge(const s21_map &other) {
  this->set_copy(other.element);
}

template <typename T, typename T2>
s21::s21_map<T, T2> s21::s21_map<T, T2>::set_merge(s21_map &other) {
  s21::s21_map<T, T2> new_other;
  for (auto x = other.begin(); x != other.end(); ++x) {
    for (auto i = this->begin(); i != this->end(); ++i) {
      if (*x == *i) new_other.insert(*x);
    }
  }
  this->set_copy(other.element);
  return new_other;
}

template <typename T, typename T2>
bool s21::s21_map<T, T2>::contains(const key_type &key) {
  for (auto i = this->begin(); i != this->end(); ++i) {
    if ((*i).first == key) return true;
  }
  return false;
}

template <typename T, typename T2>
typename s21::s21_map<T, T2>::iterator s21::s21_map<T, T2>::contains(
    const value_type &key) {
  for (auto i = this->begin(); i != this->end(); ++i) {
    if ((*i).first == key.first) return i;
  }
  return this->end();
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::set_copy(Key_Map<T, T2> *other) {
  if (other->pLeft_ && other->pRight_) {
    this->set_copy(other->pLeft_);
    this->insert(other->data_);
    this->set_copy(other->pRight_);
  }
}

template <typename T, typename T2>
s21::Key_Map<T, T2> *s21::s21_map<T, T2>::go_to_begin(Key_Map<T, T2> *key) {
  while (key->pLeft_ != back_elem) key = key->pLeft_;
  return key;
}

template <typename T, typename T2>
template <typename... Arg>
s21::s21_vector<std::pair<typename s21::s21_map<T, T2>::iterator, bool>>
s21::s21_map<T, T2>::emplace(std::pair<T, T2> value, Arg &&...args) {
  s21::s21_vector<std::pair<iterator, bool>> result(this->m_size);
  result.push_back(this->insert(value.first, value.second));
  this->emplace(std::forward<Arg>(args)...);
  return result;
}
