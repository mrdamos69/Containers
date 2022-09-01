#include "list.h"

template<typename T>
bool s21::const_iterator_cl<T>::operator ==(const const_iterator_cl<T> &right) {
    return (this->const_current->data == right.const_current->data);
}

template<typename T>
bool s21::const_iterator_cl<T>::operator !=(const const_iterator_cl &right) {
    return !(this->const_current->data == right.const_current->data);
}

template<typename T>
s21::iterator_cl<T>& s21::iterator_cl<T>::operator ++() {
    if (this->const_current->pNext != nullptr)
        this->const_current = this->const_current->pNext;
    return *this;
}

template<typename T>
s21::iterator_cl<T>& s21::iterator_cl<T>::operator --() {
    if (this->const_current->pBack != nullptr)
        this->const_current = this->const_current->pBack;
    return *this;
}

template<typename T>
s21::iterator_cl<T>& s21::iterator_cl<T>::operator ++(int) {
    this->operator++();
    return *this;
}

template<typename T>
s21::iterator_cl<T>& s21::iterator_cl<T>::operator --(int) {
    this->operator--();
    return *this;
}

template<typename T>
void s21::iterator_cl<T>::set_current(Node<T>* other) {
    this->const_current = other;
}

template<typename T>
s21::s21_list<T>::s21_list(size_type n) : s21_list() {
    while (n--)
        this->push_back(0);
}

template<typename T>
s21::s21_list<T>::s21_list(const s21_list &l) : s21_list() {
    Node<value_type>* current =  l.head;
    while (current != l.tail) {
        this->push_back(current->data);
        current = current->pNext;
    }
}

template<typename T>
s21::s21_list<T>::s21_list(s21_list &&l) : s21_list<T>(l) {
    l.clear();
}

template<typename T>
s21::s21_list<T>::s21_list(std::initializer_list<value_type> const &items) : s21_list() {
    for (auto &i : items) {
        this->push_back(i);
    }
}

template<typename T>
s21::s21_list<T>::~s21_list() {
    this->clear();
}

template<typename T>
void s21::s21_list<T>::push_back(value_type data) {
    if (this->head == nullptr && this->tail == nullptr) {
        this->head = new Node<T>(data);
        this->tail = new Node<T>;
        this->head->pNext = this->tail;
        this->tail->pNext = this->head->pNext;
    } else {
        Node<T>* current = this->head;
        while (current->pNext != this->tail) {
            current = current->pNext;
        }
        Node<T>* temp = current;
        current->pNext = new Node<T>(data);
        current = current->pNext;
        current->pBack = temp;
        this->tail->pBack = current;
        current->pNext = this->tail;
    }
    (this->m_size)++;
}

template<typename T>
void s21::s21_list<T>::push_front(value_type data) {
    if (this->head == nullptr && this->tail == nullptr) {
        this->head = new Node<value_type>(data, this->head);
        this->tail = new Node<T>;
        this->head->pNext = this->tail;
        this->tail->pBack = this->head;
        this->tail->pNext = this->head->pNext;
    } else {
        this->head = new Node<value_type>(data, this->head);
    }
    (this->m_size)++;
}

template<typename T>
void s21::s21_list<T>::pop_back() {
    this->erase(this->m_size - 1);
}

template<typename T>
void s21::s21_list<T>::pop_front() {
    Node<value_type>* current = this->head;
    this->head = this->head->pNext;
    delete current;
    (this->m_size)--;
}

template<typename T>
T& s21::s21_list<T>::operator[](const int index) {
    int counter = 0;
    Node<value_type>* current = this->head;
    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
    return this->head->data;
}

template<typename T>
s21::s21_list<T>& s21::s21_list<T>::operator = (const s21_list &l) {
    if (this->head) {
        this->clear();
    }
    this->set_copy(l.head, l.tail);
    return *this;
}

template<typename T>
void s21::s21_list<T>::set_copy(Node<T>* other, Node<T>* end) {
    if (other != end) {
        this->push_back(other->data);
        this->set_copy(other->pNext, end);
    }
}

template<typename T>
typename s21::s21_list<T>::iterator s21::s21_list<T>::insert(size_t index, value_type value) {
    auto result = this->begin();
    if (index == 0) {
        push_front(value);
    } else {
        Node<T>* current = this->head;
        for (size_t i = 0; i < index - 1; i++, ++result) {
            current = current->pNext;
        }
        current->pNext = new Node<value_type>(value, current->pNext);
        (this->m_size)++;
    }
    return ++result;
}

template<typename T>
typename s21::s21_list<T>::iterator s21::s21_list<T>::insert(iterator pos, const_reference value) {
    size_t index = 0;
    Node<T>* current;
    for (auto i = this->begin(); i != this->end(); ++i, index++) {
        if (pos == i)
            break;
    }
    if (index == 0) {
        push_front(value);
    } else {
        current = this->head;
        for (size_t y = 0; y < index - 1; y++) {
            current = current->pNext;
        }
        current->pNext = new Node<value_type>(value, current->pNext);
        (this->m_size)++;
    }
    iterator_cl<T> result;
    result.const_current = current->pNext;
    return result;
}

template<typename T>
void s21::s21_list<T>::erase(int index) {
    if (index == 0) {
        pop_front();
    } else {
        Node<value_type>* current = this->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->pNext;
        }
        Node<value_type>* to_delete = current->pNext;
        current->pNext = to_delete->pNext;
        delete to_delete;
        (this->m_size)--;
    }
}

template<typename T>
void s21::s21_list<T>::swap(s21_list& other) {
    s21_list<T> temp(*this);
    *this = other;
    other = temp;
}

template<typename T>
void s21::s21_list<T>::reverse() {
    s21_list<T> temp;
    for (auto &&i : *this) {
        temp.push_front(i);
    }
    *this = temp;
}

template<typename T>
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

template<typename T>
void s21::s21_list<T>::merge(const s21_list& other) {
    this->set_copy(other.head, other.tail);
    this->sort();
}

template<typename T>
void s21::s21_list<T>::unique() {
    Node<value_type>* current = this->head;
    s21_list<T> temp;
    T temp_data;
    while (current != this->tail) {
        if (temp_data != current->data) {
            temp.push_back(current->data);
            temp_data = current->data;
        }
        current = current->pNext;
    }
    *this = temp;
}

template<typename T>
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

template<typename T>
size_t s21::s21_list<T>::max_size() {
    return MAX_SIZE_LIST;
}

template<typename T>
void s21::s21_list<T>::clear() {
    while (this->m_size) {
        this->pop_front();
    }
    if (this->tail != nullptr) {delete this->tail;}
    this->tail = nullptr;
    this->head = nullptr;
}

template<typename T>
const T& s21::s21_list<T>::front() {
    return this->head->data;
}


template<typename T>
const T& s21::s21_list<T>::back() {
    if (this->head == nullptr) {
        return this->head->data;
    } else {
        Node<value_type>* current = this->head;
        while (current->pNext != this->tail) {
            current = current->pNext;
        }
        return current->data;
    }
}

template<typename T>
template<typename ... Arg>
typename s21::s21_list<T>::iterator s21::s21_list<T>::emplace(iterator pos, T value, Arg&&...args) {
    pos = insert(pos, value);
    this->emplace(pos, args ...);
    return pos;
}

template<typename T>
template<typename ... Arg>
void s21::s21_list<T>::emplace_back(T value, Arg&&...args) {
    this->push_back(value);
    this->emplace_back(args ...);
}

template<typename T>
template<typename ... Arg>
void s21::s21_list<T>::emplace_front(T value, Arg&&...args) {
    this->push_front(value);
    this->emplace_front(args ...);
}
