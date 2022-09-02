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
    this->const_current = this->const_current->pRight;
    return *this;
  }

  if (this->const_current->pRoot == this->const_current) {
    this->const_current = this->const_current->pRight;
    while (this->const_current->pLeft->pLeft != nullptr) {
      this->const_current = this->const_current->pLeft;
    }
    return *this;
  }

  if (this->const_current->data.first <
          this->const_current->pRight->data.first &&
      this->const_current->pRight->pRight) {
    this->const_current = this->const_current->pRight;

    while (this->const_current->pLeft->pLeft != nullptr) {
      this->const_current = this->const_current->pLeft;
    }
    return *this;
  }

  T temp = this->const_current->data.first;
  this->const_current = this->const_current->pBack;

  if (temp == this->const_current->pLeft->data.first) {
    return *this;
  } else if (temp == this->const_current->pRight->data.first) {
    this->const_current = this->const_current->pBack;
    if (this->const_current->pRight->pRight &&
        temp == this->const_current->pRight->pRight->data.first) {
      this->const_current = this->const_current->pBack;
    }
    return *this;
  }
  return *this;
}

template <typename T, typename T2>
s21::iterator_map<T, T2> &s21::iterator_map<T, T2>::operator--() {
  if (this->const_current->pRoot == this->const_current) {
    this->const_current = this->const_current->pLeft;
    while (this->const_current->pLeft->pRight != nullptr) {
      this->const_current = this->const_current->pRight;
    }
    return *this;
  }

  if (!this->const_current->pLeft && !this->const_current->pRight) {
    this->const_current = this->const_current->pBack;
    return *this;
  }

  if (this->const_current->pLeft->data.first <
          this->const_current->data.first &&
      this->const_current->pLeft->pLeft != nullptr) {
    this->const_current = this->const_current->pLeft;
    while (this->const_current->pRight->pRight != nullptr) {
      this->const_current = this->const_current->pRight;
    }
    return *this;
  }

  T temp = this->const_current->data.first;
  this->const_current = this->const_current->pBack;

  if (temp == this->const_current->pRight->data.first &&
      this->const_current->pRight != nullptr) {
    return *this;
  }

  if (temp == this->const_current->pLeft->data.first) {
    this->const_current = this->const_current->pBack;
    if (this->const_current->pLeft->pLeft &&
        temp == this->const_current->pLeft->pLeft->data.first) {
      while (this->const_current->pBack != nullptr) {
        this->const_current = this->const_current->pBack;
      }
    }
    return *this;
  }
  return *this;
}

template <typename T, typename T2>
bool s21::iterator_map<T, T2>::it_end() {
  T it_end_count = this->const_current->data.first;
  Key_Map<T, T2> *temp = this->const_current;
  while (temp->pBack != nullptr) {
    temp = temp->pBack;
  }
  while (temp->pRight->pRight != nullptr) {
    temp = temp->pRight;
  }
  if (temp->data.first == it_end_count) {
    return true;
  }
  return false;
}

template <typename T, typename T2>
s21::s21_map<T, T2>::~s21_map() {
  this->clear();
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
  this->clear();
  // for (auto&& i : m) {
  //     this->insert(i);
  // }
  this->set_copy(m.element);
  return *this;
}

template <typename T, typename T2>
T &s21::s21_map<T, T2>::at(const Key_Map<key_type, mapped_type> &key) {
  for (auto i = this->begin(); i != this->end(); ++i) {
    if ((*i).first == key.data.first) {
      if ((*i).second == key.data.second) {
        return i.const_current->data.second;
      }
    }
  }
  throw std::invalid_argument("MyFunc argument too large.");
}

template <typename T, typename T2>
T2 &s21::s21_map<T, T2>::operator[](const Key_Map<key_type, mapped_type> &key) {
  for (auto i = this->begin(); i != this->end(); ++i) {
    if ((*i).first == key.data.first) {
      if ((*i).second == key.data.second) {
        return i.const_current->data.second;
      }
    }
  }
  this->insert(key.data);
  return this->element->data.second;
}

template <typename T, typename T2>
T2 &s21::s21_map<T, T2>::operator[](const key_type &key) {
  for (auto i = this->begin(); i != this->end(); ++i) {
    if ((*i).first == key) {
      return i.const_current->data.second;
    }
  }
  return this->element->data.second;
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::clear() {
  clear(this->element);
  this->m_size = 0;
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::clear(Key_Map<key_type, mapped_type> *key) {
  if (key->pLeft && key->pRight) {
    this->clear(key->pLeft);
    this->clear(key->pRight);
    delete key;
    (this->m_size)--;
    element = nullptr;
  }
}

template <typename T, typename T2>
typename s21::s21_map<T, T2>::iterator s21::s21_map<T, T2>::begin() {
  while (element->pLeft != back_elem) element = element->pLeft;
  return this->element;
}
template <typename T, typename T2>
typename s21::s21_map<T, T2>::iterator s21::s21_map<T, T2>::end() {
  return this->back_elem;
}

template <typename T, typename T2>
typename s21::s21_map<T, T2>::size_type s21::s21_map<T, T2>::max_size() {
  return MAX_SIZE_MAP;
}

template <typename T, typename T2>
std::pair<typename s21::s21_map<T, T2>::iterator, bool>
s21::s21_map<T, T2>::insert(
    const typename s21::s21_map<T, T2>::value_type &value) {
  std::pair<s21::s21_map<T, T2>::iterator, bool> result;
  if (element == nullptr) {
    element = new Key_Map<T, T2>();
    back_elem = new Key_Map<T, T2>();
    element->pRoot = element;
    element->data = value;
    result.first = element;
    result.second = true;
    element->pLeft = back_elem;
    element->pRight = back_elem;
    ++(this->m_size);
  } else {
    result.second = input_in_branch(element, value);
    result.first = this->contains(value);
  }
  I_ll_be_back();
  return result;
}

template <typename T, typename T2>
bool s21::s21_map<T, T2>::input_in_branch(
    s21::Key_Map<T, T2> *branch,
    const typename s21::s21_map<T, T2>::value_type &value) {
  if (branch->data.first > value.first) {
    if (branch->pLeft != back_elem) {
      input_in_branch(branch->pLeft, value);
    } else {
      branch->pLeft = new Key_Map<T, T2>();
      branch->pLeft->pBack = branch;
      branch = branch->pLeft;
      branch->data = value;
      branch->pLeft = back_elem;
      branch->pRight = back_elem;
      back_elem->pBack = branch;
      ++(this->m_size);
      return true;
    }
  } else if (branch->data.first < value.first) {
    if (branch->pRight != back_elem) {
      input_in_branch(branch->pRight, value);
    } else {
      branch->pRight = new Key_Map<T, T2>();
      branch->pRight->pBack = branch;
      branch = branch->pRight;
      branch->data = value;
      branch->pLeft = back_elem;
      branch->pRight = back_elem;
      back_elem->pBack = branch;
      ++(this->m_size);
      return true;
    }
  }
  return false;
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::I_ll_be_back() {
  back_to_root();
  while (this->element->pRight != back_elem) {
    this->element = this->element->pRight;
  }
  back_elem->pBack = this->element;
  back_to_root();
}

template <typename T, typename T2>
void s21::s21_map<T, T2>::back_to_root() {
  while (element->pBack != nullptr) {
    element = element->pBack;
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
    if (*i == pos.const_current->data) {
      if ((pos.const_current->pLeft == back_elem) &&
          (pos.const_current->pRight == back_elem)) {
        if (pos.const_current->pBack->pRight->data.first ==
            pos.const_current->data.first) {
          pos.const_current->pBack->pRight = back_elem;
        }
        if (pos.const_current->pBack->pLeft->data.first ==
            pos.const_current->data.first) {
          pos.const_current->pBack->pLeft = back_elem;
        }
        delete pos.const_current;
        (this->m_size)--;
        break;
      } else {
        if (pos.const_current->pRoot == pos.const_current) {
          Key_Map<T, T2> *temp_data = pos.const_current;
          pos.const_current = pos.const_current->pRight;
          while (pos.const_current->pLeft != back_elem) {
            pos.const_current = pos.const_current->pLeft;
          }
          temp_data->data.first = pos.const_current->data.first;
          pos.const_current->pBack->pLeft = back_elem;
          delete pos.const_current;
          (this->m_size)--;
          break;
        } else {
          back_to_root();

          if (pos.const_current->pBack->pRight->data.first ==
              pos.const_current->data.first) {
            pos.const_current->pBack->pRight = back_elem;
          }
          if (pos.const_current->pBack->pLeft->data.first ==
              pos.const_current->data.first) {
            pos.const_current->pBack->pLeft = back_elem;
          }
          pos.const_current->pBack = nullptr;
          set_copy(pos.const_current->pLeft);
          set_copy(pos.const_current->pRight);
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
  if (other->pLeft && other->pRight) {
    this->set_copy(other->pLeft);
    this->insert(other->data);
    this->set_copy(other->pRight);
  }
}

template <typename T, typename T2>
template <typename... Arg>
std::pair<typename s21::s21_map<T, T2>::iterator, bool>
s21::s21_map<T, T2>::emplace(std::pair<T, T2> value, Arg &&...args) {
  this->insert(value.first, value.second);
  this->emplace(args...);
  for (auto i = this->begin(); i != this->end(); ++i) {
    if (value == *i) {
      return std::pair<iterator, bool>(i, true);
    }
  }
  return std::pair<iterator, bool>(this->end(), false);
}
