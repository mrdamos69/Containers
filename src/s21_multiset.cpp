#include "s21_multiset.h"

template <typename T>
s21::s21_multiset<T>::s21_multiset(std::initializer_list<T> const& items) : s21_set<T>() {
    for (auto&& i : items) {
        s21::s21_multiset<T>::insert(i);
    }
}

template<typename T>
s21::s21_multiset<T>::s21_multiset(s21_multiset<T>& ms) : s21_set<T>() {
    this->set_copy(ms.element);
}

template<typename T>
s21::s21_multiset<T>::s21_multiset(s21_multiset&& s) : s21_multiset<T>(s) {
    s.clear();
}

template<typename T>
s21::iterator_set<T> s21::s21_multiset<T>::insert(const T& value) {
    // s21::iterator_set<T> it_result = this->begin();
    if (this->element == nullptr) {
        this->element = new Key<T>();
        this->back_elem = new Key<T>();
        this->element->data = value;
        this->element->pRoot = this->element;
        this->element->pLeft = this->back_elem;
        this->element->pRight = this->back_elem;
        this->back_elem->data = ++(this->m_size);
    }
    else {
        input_in_branch(this->element, value);
    }
    this->I_ll_be_back();
    // return it_result;
}

template<typename T>
bool s21::s21_multiset<T>::input_in_branch(Key<T>* branch, T value) {
    if (branch->data >= value) {
        if (branch->pLeft != this->back_elem) {
            input_in_branch(branch->pLeft, value);
        }
        else {
            branch->pLeft = new Key<T>();
            branch->pLeft->pBack = branch;
            branch = branch->pLeft;
            branch->data = value;
            branch->pLeft = this->back_elem;
            branch->pRight = this->back_elem;
            this->back_elem->pBack = branch;
            this->back_elem->data = ++(this->m_size);
            return true;
        }
    } else if (branch->data < value) {
        if (branch->pRight != this->back_elem) {
            input_in_branch(branch->pRight, value);
        }
        else {
            branch->pRight = new Key<T>(); 
            branch->pRight->pBack = branch;
            branch = branch->pRight;
            branch->data = value;
            branch->pLeft = this->back_elem;
            branch->pRight = this->back_elem;
            this->back_elem->pBack = branch;
            this->back_elem->data = ++(this->m_size);
            return true;
        }
    }
    return false;
}

template<typename T>
s21::s21_multiset<T> s21::s21_multiset<T>::operator = (s21_multiset<T>& value) {
    this->clear();
    for (auto&& i : value) {
        this->insert(i);
    }
    return *this;
}

template<typename T>
void s21::s21_multiset<T>::swap(s21_multiset<T>& other) {
    s21_multiset<T> temp_set(*this);
    *this = other;
    other = temp_set;
}

template<typename T>
void s21::s21_multiset<T>::merge(s21_multiset<T>& other) {
    this->set_copy(other.element);
}

template<typename T>
void s21::s21_multiset<T>::set_copy(Key<T>* other) {
    if (other->pLeft && other->pRight) {
        this->set_copy(other->pLeft);
        this->insert(other->data);
        this->set_copy(other->pRight);
    }
}
