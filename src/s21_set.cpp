#include "s21_set.h"
// #include <random>
using namespace s21;

template<typename T>
s21_set<T>::~s21_set() {
    this->clear();
}

template <typename T>
s21_set<T>::s21_set(std::initializer_list<value_type> const& items) : m_size(0),
element(nullptr),
back_elem(nullptr) {
    for (auto&& i : items) {
        this->insert(i);
    }
}

template<typename T>
s21_set<T>::s21_set(s21_set<T>& s) : m_size(0),
element(nullptr),
back_elem(nullptr) {
    this->set_copy(s.element);
}

template<typename T>
s21::s21_set<T> s21_set<T>::operator = (s21_set& value) {
    this->clear();
    for (auto&& i : value) {
        this->insert(i);
    }
    return *this;
}

template<typename T>
size_t s21_set<T>::get_size() {
    return m_size;
}

template<typename T>
bool s21_set<T>::empty() {
    return !(this->m_size > 0);
}

template<typename T>
std::pair<T, bool> s21_set<T>::insert(const value_type& value) {
    std::pair<T, bool> result;
    if (element == nullptr) {
        element = new Key<T>();
        back_elem = new Key<T>();
        element->pRoot = element;
        result.first = element->data = value;
        result.second = true;
        element->pLeft = back_elem;
        element->pRight = back_elem;
        back_elem->data = ++m_size;
    }
    else {
        input_in_branch(element, value);
    }
    return result;
}

template<typename T>
bool s21_set<T>::contains(const Key<T>& key) {
    for (auto&& i : *this) {
        if (i == key.data) { return true; }
    }
    return false;
}

template<typename T>
void s21_set<T>::clear() {
    if (element->pLeft != nullptr) {
        this->element = this->element->pLeft;
        this->clear();
        delete element;
    }
    else if (element->pRight != nullptr) {
        this->element = this->element->pRight;
        this->clear();
        delete element;
    }
    element = nullptr;
}

template<typename T>
Key<T>* s21_set<T>::get_element() {
    return this->element;
}

template<typename T>
void s21::s21_set<T>::back_to_root() {
    while (element->pBack != nullptr) {
        element = element->pBack;
    }
}

template<typename T>
void s21::s21_set<T>::erase(iterator pos) {
    for (auto&& i = begin(); i != end(); ++i) {
        if (*i == pos.const_current->data) {
            if ((pos.const_current->pLeft == back_elem) && (pos.const_current->pRight == back_elem)) {
                if (pos.const_current->pBack->pRight->data == pos.const_current->data) {
                    pos.const_current->pBack->pRight = back_elem;
                }
                if (pos.const_current->pBack->pLeft->data == pos.const_current->data) {
                    pos.const_current->pBack->pLeft = back_elem;
                }
                delete pos.const_current;
                this->m_size--;
            }
            else {
                if (pos.const_current->pRoot == pos.const_current) {
                    Key<T>* temp_data = pos.const_current;
                    pos.const_current = pos.const_current->pRight;
                    while (pos.const_current->pLeft != back_elem) {
                        pos.const_current = pos.const_current->pLeft;
                    }
                    temp_data->data = pos.const_current->data;
                    pos.const_current->pBack->pLeft = back_elem;
                    delete pos.const_current;
                } else {
                    pos.const_current->pLeft->data = pos.const_current->data;
                    delete pos.const_current->pLeft;
                    pos.const_current->pLeft = back_elem;
                }
            }
        }
    }
}

template<typename T>
void s21::s21_set<T>::swap(s21_set& other) {
    s21_set<T> temp_set(*this);
    *this = other;
    other = temp_set;
}

template<typename T>
void s21::s21_set<T>::merge(s21_set& other) {
    this->set_copy(other.element);
}

template<typename T>
void s21::s21_set<T>::set_copy(Key<T>* other) {
    if (other->pLeft != nullptr) {
        this->set_copy(other->pLeft);
        this->insert(other->data);
    }
    if (other->pRight != nullptr) {
        this->set_copy(other->pRight);
    }
}

template<typename T>
typename s21::s21_set<T>::iterator s21::s21_set<T>::find(const Key<T>& key) {
    for (auto i = begin(); i != end(); ++i) {
        if (*i == key.data) { return i; }
    }
    return iterator();
}

template<typename T>
typename s21::s21_set<T>::iterator s21::s21_set<T>::find(const T key) {
    for (auto i = begin(); i != end(); ++i) {
        if (*i == key) { return i; }
    }
    return iterator();
}

template<typename T>
void s21::s21_set<T>::input_in_branch(Key<T>* branch, T value) {
    if (branch->data > value) {
        if (branch->pLeft != back_elem) {
            input_in_branch(branch->pLeft, value);
        }
        else {
            branch->pLeft = new Key<T>();
            branch->pLeft->pBack = branch;
            branch = branch->pLeft;
            branch->data = value;
            branch->pLeft = back_elem;
            branch->pRight = back_elem;
            back_elem->pBack = branch;
            back_elem->data = ++m_size;
        }
    }
    else {
        if (branch->pRight != back_elem) {
            input_in_branch(branch->pRight, value);
        }
        else {
            branch->pRight = new Key<T>();
            branch->pRight->pBack = branch;
            branch = branch->pRight;
            branch->data = value;
            branch->pLeft = back_elem;
            branch->pRight = back_elem;
            back_elem->pBack = branch;
            back_elem->data = ++m_size;
        }
    }
}


// int main() {
//     s21_set<int> s21_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};
//     auto x = s21_set_1.end();
//     //for (auto &&i : s21_set_1) {
//     //    std::cout << "s21_set: " << i << std::endl; 
//     //}
//     //std::cout << std::endl;
//     //x--;
//     //x--;
//     std::cout << x.const_current->data << std::endl;

//     //s21_set_1.erase(x);
//     //for (auto&& i : s21_set_1) {
//     //    std::cout << "s21_set: " << i << std::endl;
//     //}
//     return 0;
// }