#include "s21_set.h"
// #include <random>
using namespace s21;

template<typename T>
s21_set<T>::~s21_set() {
    this->clear();
}

template <typename T>
s21_set<T>::s21_set(std::initializer_list<value_type> const &items) : m_size(0),
                                                                    element(nullptr),
                                                                    back_elem(nullptr) {
    for (auto &&i : items) {
        this->insert(i);
    }
}

template<typename T>
s21_set<T>::s21_set(s21_set<T> &s) : m_size(0),
                                        element(nullptr),
                                        back_elem(nullptr) {             
    this->set_copy(s.element);
}

template<typename T>
s21::s21_set<T> s21_set<T>::operator = (s21_set& value) {
    
    this->clear();

    for (auto &&i : value) {
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
        m_size++;
        element->data = value;
        // result.first;
        result.second = true;

        element->pLeft = back_elem;
        element->pRight = back_elem;
        back_elem->data = m_size;
    } else {
        if (element->data > value) {
            input_left(value);
        }
        else if (element->data < value) {
            input_right(value);
        }
    }
    return result;
}

template<typename T>
void s21_set<T>::input_left(T value) {
    Key<T>* temp;
    if (element->pLeft == back_elem) {
        temp = element;
        element->pLeft = new Key<T>();
        element = element->pLeft;
        element->pBack = temp;
        element->data = value;
        element->pLeft = back_elem;
        element->pRight = back_elem;
        back_elem->pBack = element;
        back_to_root();
        back_elem->data = ++m_size;
    }
    else {
        element = element->pLeft;
        insert(value);
    }
}

template<typename T>
void s21_set<T>::input_right(T value) {
    Key<T>* temp;
    if (element->pRight == back_elem) {
        temp = element;
        element->last_element = false;
        element->pRight = new Key<T>();
        element = element->pRight;
        element->pBack = temp;
        element->data = value;
        element->pLeft = back_elem;
        element->pRight = back_elem;
        element->last_element = true;
        back_elem->pBack = element;
        back_to_root();
        back_elem->data = ++m_size;
    }
    else {
        element = element->pRight;
        insert(value);
    }
}

template<typename T>
bool s21_set<T>::contains(const Key<T>& key) {
    for (auto &&i : *this) {
        if(i.const_current->data == key.data) {return true;}
    }
    return false;
}


template<typename T>
void s21_set<T>::clear() {
    if (this->element != nullptr) {
        if(element->pLeft != nullptr) {
            this->element = this->element->pLeft;
            this->clear();
            delete element->pLeft;
        }
        else if(element->pRight != nullptr) {
            this->element = this->element->pRight;
            this->clear();
            delete element->pRight;
        }
    }
}

template<typename T>
void s21_set<T>::print(Key<T>* branch) {
    if (branch == back_elem) {return;}
    // for (auto &&i : *this) {
    //     std::cout << i <<std::endl;
    // }

    if (branch->pLeft != nullptr) {
        this->print(branch->pLeft);   
        std::cout << branch->data << std::endl;
    }
    if (branch->pRight != nullptr) {
        this->print(branch->pRight);
    }
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
}

template<typename T>
void s21::s21_set<T>::swap(s21_set& other) {
    s21_set<T> temp_set(*this);
    *this = other;
    other = temp_set;
}

template<typename T>
void s21::s21_set<T>::merge(s21_set& other) {
    for (auto &&i : other) {
        this->insert(i);
    }
}

template<typename T>
void s21::s21_set<T>::set_copy(Key<T>* other) {
    
    // if (other->pLeft != nullptr) {
    //     this->set_copy(other->pLeft);
    //     this->insert(other->data);
    // }
    // if (other->pRight != nullptr) {
    //     this->set_copy(other->pRight);
    //     this->insert(other->pRight->data);
    // }

    if (other->pLeft != nullptr) {
        this->set_copy(other->pLeft);
        this->insert(other->data);
    }
    if (other->pRight != nullptr) {
        this->set_copy(other->pRight);
    }
}

// template<typename T>
// iterator s21::s21_set<T>::find(const Key<T>& key) {
//     return iterator();
// }