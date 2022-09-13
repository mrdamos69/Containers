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

  if (this->const_current->data < this->const_current->pRight->data &&
      this->const_current->pRight->pRight) {
    this->const_current = this->const_current->pRight;

    while (this->const_current->pLeft->pLeft != nullptr) {
      this->const_current = this->const_current->pLeft;
    }
    return *this;
  }

  T temp = this->const_current->data;
  this->const_current = this->const_current->pBack;

  if (temp == this->const_current->pLeft->data) {
    return *this;
  } else if (temp == this->const_current->pRight->data) {
    this->const_current = this->const_current->pBack;
    if (this->const_current->pRight->pRight &&
        temp == this->const_current->pRight->pRight->data) {
      this->const_current = this->const_current->pBack;
    }
    return *this;
  }
  return *this;
}

template <typename T>
s21::iterator_set<T> &s21::iterator_set<T>::operator--() {
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

  if (this->const_current->pLeft->data <= this->const_current->data &&
      this->const_current->pLeft->pLeft != nullptr) {
    this->const_current = this->const_current->pLeft;
    while (this->const_current->pRight->pRight != nullptr) {
      this->const_current = this->const_current->pRight;
    }
    return *this;
  }

  T temp = this->const_current->data;
  this->const_current = this->const_current->pBack;

  if (temp == this->const_current->pRight->data &&
      this->const_current->pRight != nullptr) {
    return *this;
  }

  if (temp == this->const_current->pLeft->data) {
    this->const_current = this->const_current->pBack;
    if (this->const_current->pLeft->pLeft &&
        temp == this->const_current->pLeft->pLeft->data) {
      while (this->const_current->pBack != nullptr) {
        this->const_current = this->const_current->pBack;
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
  T it_end_count = this->const_current->data;
  Key<T> *temp = this->const_current;
  while (temp->pBack != nullptr) {
    temp = temp->pBack;
  }
  while (temp->pRight->pRight != nullptr) {
    temp = temp->pRight;
  }
  if (temp->data == it_end_count) {
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
s21::s21_set<T>::s21_set(s21_set &&s) : s21_set<T>(s) {
  s.clear();
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
    element->pRoot = element;
    element->data = value;
    element->pLeft = element->pRight = back_elem;
    back_elem->data = ++(this->m_size);
    return std::pair<iterator, bool>(this->element, true);
  }
  std::pair<iterator, bool> result = input_in_branch(element, value);
  I_ll_be_back();
  return result;
}

template <typename T>
bool s21::s21_set<T>::contains(const Key<T> &key) {
  for (auto &&i : *this) {
    if (i == key.data) {
      return true;
    }
  }
  return false;
}

template <typename T>
void s21::s21_set<T>::clear() {
  this->clear(this->element);
  this->m_size = 0;
  delete back_elem;
  this->back_elem = nullptr;
}

template <typename T>
void s21::s21_set<T>::clear(Key<T> *key) {
  if (key->pLeft && key->pRight) {
    this->clear(key->pLeft);
    this->clear(key->pRight);
    delete key;
    key = nullptr;
    (this->m_size)--;
  }
}

template <typename T>
void s21::s21_set<T>::back_to_root() {
  while (element->pBack != nullptr) {
    element = element->pBack;
  }
}

template <typename T>
void s21::s21_set<T>::erase(iterator pos) {
  for (auto &&i = begin(); i != end(); ++i) {
    if (*i == pos.const_current->data) {
      if ((pos.const_current->pLeft == back_elem) &&
          (pos.const_current->pRight == back_elem)) {
        if (pos.const_current->pBack->pRight->data == pos.const_current->data) {
          pos.const_current->pBack->pRight = back_elem;
        }
        if (pos.const_current->pBack->pLeft->data == pos.const_current->data) {
          pos.const_current->pBack->pLeft = back_elem;
        }
        delete pos.const_current;
        (this->m_size)--;
        break;
      } else {
        if (pos.const_current->pRoot == pos.const_current) {
          Key<T> *temp_key = pos.const_current;
          pos.const_current = pos.const_current->pRight;
          while (pos.const_current->pLeft != back_elem) {
            pos.const_current = pos.const_current->pLeft;
          }
          temp_key->data = pos.const_current->data;
          pos.const_current->pBack->pLeft = back_elem;
          delete pos.const_current;
          (this->m_size)--;
          break;
        } else {
          // if (pos.const_current->pLeft && pos.const_current->pLeft !=
          // this->back_elem) {
          //   pos.const_current = pos.const_current->pLeft;
          //   T temp_data = pos.const_current->data;
          //   pos.const_current->pBack->pLeft = back_elem;
          //   delete pos.const_current;
          //   *i = temp_data;
          // }

          back_to_root();
          if (pos.const_current->pBack->pRight->data ==
              pos.const_current->data) {
            pos.const_current->pBack->pRight = back_elem;
          }
          if (pos.const_current->pBack->pLeft->data ==
              pos.const_current->data) {
            pos.const_current->pBack->pLeft = back_elem;
          }
          pos.const_current->pBack = nullptr;
          set_copy(pos.const_current->pLeft);
          set_copy(pos.const_current->pRight);
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
void s21::s21_set<T>::merge(const s21_set &other) {
  this->set_copy(other.element);
}

template <typename T>
void s21::s21_set<T>::set_copy(Key<T> *other) {
  if (other->pLeft && other->pRight) {
    this->set_copy(other->pLeft);
    this->insert(other->data);
    this->set_copy(other->pRight);
  }
}

template <typename T>
typename s21::s21_set<T>::iterator s21::s21_set<T>::find(const Key<T> &key) {
  for (auto i = begin(); i != end(); ++i) {
    if (*i == key.data) {
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
  if (branch->data > value) {
    if (branch->pLeft != back_elem) {
      input_in_branch(branch->pLeft, value);
    } else {
      branch->pLeft = new Key<T>();
      branch->pLeft->pBack = branch;
      branch = branch->pLeft;
      branch->data = value;
      branch->pLeft = branch->pRight = back_elem;
      back_elem->pBack = branch;
      back_elem->data = ++(this->m_size);
      return std::pair<iterator, bool>(branch, true);
    }
  } else if (branch->data < value) {
    if (branch->pRight != back_elem) {
      input_in_branch(branch->pRight, value);
    } else {
      branch->pRight = new Key<T>();
      branch->pRight->pBack = branch;
      branch = branch->pRight;
      branch->data = value;
      branch->pLeft = branch->pRight = back_elem;
      back_elem->pBack = branch;
      back_elem->data = ++(this->m_size);
      return std::pair<iterator, bool>(branch, true);
    }
  }
  return std::pair<iterator, bool>(this->end(), false);
}

template <typename T>
void s21::s21_set<T>::I_ll_be_back() {
  back_to_root();
  while (this->element->pRight != back_elem) {
    this->element = this->element->pRight;
  }
  back_elem->pBack = this->element;
  back_to_root();
}

template <typename T>
s21::Key<T> *s21::s21_set<T>::go_to_begin(Key<T> *key) {
  while (key->pLeft != back_elem) key = key->pLeft;
  return key;
}

template <typename T>
template <typename... Arg>
s21::s21_vector<std::pair<typename s21::s21_set<T>::iterator, bool>>
s21::s21_set<T>::emplace(T value, Arg &&...args) {
  s21::s21_vector<std::pair<typename s21::s21_set<T>::iterator, bool>> result;
  result.push_back(this->insert(value));
  this->emplace(std::forward<Arg>(args)...);
  return result;
}
