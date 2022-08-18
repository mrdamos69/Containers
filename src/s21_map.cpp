#include "s21_map.h"


template<typename T, typename T2>
s21::s21_map<T, T2>::~s21_map() {
    // this->clear();
}

template<typename T, typename T2>
s21::s21_map<T, T2>::s21_map(std::initializer_list<value_type> const &items) : element(nullptr),
                                                                                back_elem(nullptr) {
    for (auto&& i : items) {
        this->insert(i);
    }
}

template<typename T, typename T2>
s21::s21_map<T, T2>::s21_map(const s21_map &m) : element(nullptr),
                                                back_elem(nullptr) {
    this->set_copy(m.element);
    
}

template<typename T, typename T2>
s21::s21_map<T, T2>::s21_map(s21_map &&m) : element(nullptr),
                                            back_elem(nullptr) {
    this->set_copy(m.element);
    m.clear();
}

template<typename T, typename T2>
s21::s21_map<T, T2> s21::s21_map<T, T2>::operator = (s21_map &&m) {
    this->clear();
    for (auto&& i : m) {
        this->insert(i);
    }
    return *this;
}

template<typename T, typename T2>
T& s21::s21_map<T, T2>::at(const Key_Map<key_type, mapped_type>& key) {

}

template<typename T, typename T2>
T& s21::s21_map<T, T2>::operator[](const Key_Map<key_type, mapped_type>& key) {

}

template<typename T, typename T2>
typename s21::s21_map<T, T2>::iterator s21::s21_map<T, T2>::begin() {

}
template<typename T, typename T2>
typename s21::s21_map<T, T2>::iterator s21::s21_map<T, T2>::end() {

}

template<typename T, typename T2>
bool s21::s21_map<T, T2>::empty() {
    return !(this->m_size > 0);
}

template<typename T, typename T2>
typename s21::s21_map<T, T2>::size_type s21::s21_map<T, T2>::get_size() {
    return m_size;
}

template<typename T, typename T2>
typename s21::s21_map<T, T2>::size_type s21::s21_map<T, T2>::max_size() {
    return MAX_SIZE_MAP;
}

template<typename T, typename T2>
void s21::s21_map<T, T2>::clear() {

}

template<typename T, typename T2>
std::pair<typename s21::s21_map<T, T2>::iterator, bool> s21::s21_map<T, T2>::insert(typename s21::s21_map<T, T2>::value_type& value) {
    std::pair<T*, bool> result;
    if (element == nullptr) {
        element = new Key_Map<T, T2>();
        back_elem = new Key_Map<T, T2>();
        element->pRoot = element;
        element->data = value;
        result.first = element;
        result.second = true;
        element->pLeft = back_elem;
        element->pRight = back_elem;
        ++m_size;
    }
    else {
        input_in_branch(element, value);
        result.second = true;
    }
    I_ll_be_back();
    return result;
}

template<typename T, typename T2>
void s21::s21_map<T, T2>::input_in_branch(s21::Key_Map<T, T2>* branch, typename s21::s21_map<T, T2>::value_type& value) {
    if (branch->data.first > value.first) {

        if (branch->pLeft != back_elem) {
            input_in_branch(branch->pLeft, value);
        }
        else {
            branch->pLeft = new Key_Map<T, T2>();
            branch->pLeft->pBack = branch;
            branch = branch->pLeft;
            branch->data = value;
            branch->pLeft = back_elem;
            branch->pRight = back_elem;
            back_elem->pBack = branch;
            ++m_size;
        }
    }
    else {
        if (branch->pRight != back_elem) {
            input_in_branch(branch->pRight, value);
        }
        else {
            branch->pRight = new Key_Map<T, T2>(); 
            branch->pRight->pBack = branch;
            branch = branch->pRight;
            branch->data = value;
            branch->pLeft = back_elem;
            branch->pRight = back_elem;
            back_elem->pBack = branch;
            ++m_size;
        }
    }
}

template<typename T, typename T2>
void s21::s21_map<T, T2>::I_ll_be_back() {
    back_to_root();
    while (this->element->pRight != back_elem) {
        this->element = this->element->pRight;
    }
    back_elem->pBack = this->element;
    back_to_root();
}

template<typename T, typename T2>
void s21::s21_map<T, T2>::back_to_root() {
    while (element->pBack != nullptr) {
        element = element->pBack;
    }
}

template<typename T, typename T2>
std::pair<typename s21::s21_map<T, T2>::iterator, bool> insert( s21::Key_Map<T, T2>& key,  T& obj) {

}

template<typename T, typename T2>
std::pair<typename s21::s21_map<T, T2>::iterator, bool> insert_or_assign(s21::Key_Map<T, T2>& key, T& obj) {

}

template<typename T, typename T2>
void s21::s21_map<T, T2>::erase(typename s21::s21_map<T, T2>::iterator pos) {

}

template<typename T, typename T2>
void s21::s21_map<T, T2>::swap(s21_map& other) {

}

template<typename T, typename T2>
void s21::s21_map<T, T2>::merge(s21_map& other) {

}

template<typename T, typename T2>
bool s21::s21_map<T, T2>::contains(const s21::Key_Map<T, T2>& key) {
    return false;
}