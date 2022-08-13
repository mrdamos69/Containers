#include "s21_vector.h"
using namespace s21;

template <typename T>
void s21_vector<T>::reserve_more_capacity(size_t size) {
    if (size > m_capacity) {
        value_type *buff = new value_type[size];
        for (size_t i = 0; i < m_size; ++i)
            buff[i] = std::move(arr[i]);
        delete[] arr;
        arr = buff;
        m_capacity = size;
    }
}

template <typename T>
s21_vector<T>::s21_vector(std::initializer_list<value_type> const &items) {
    arr = new value_type[items.size()];
    int i = 0;
    for (auto it = items.begin(); it != items.end(); it++) {
        arr[i] = *it;
        i++;
    }
    m_size = items.size();
    m_capacity = items.size();
}

template <typename T>
s21_vector<T>& s21_vector<T>::operator = (s21_vector<T> &v) {
    if (arr) {
        clear();
    }
    for (size_t i = 0; i <= v.m_size; i++) {
        push_back(v.arr[i]);
    }
    return *this;
}

template <typename T>
T& s21_vector<T>::operator[](size_type pos) {
    return pos > 0 ? this->arr[pos] : this->arr[0];
}

template <typename T>
bool s21_vector<T>::operator == (s21_vector<T> &v) {
    if (this->m_size != v.m_size){return false;}
    for (size_t i = 0; i < this->m_size; i++)
        if (this->arr[i] != v.arr[i]) {return false;}
    return true;
}

template <typename T>
const T& s21_vector<T>::front() {
    return this->arr[0];
}

template <typename T>
const T& s21_vector<T>::back() {
    return this->arr[m_size - 1];
}

template <typename T>
bool s21_vector<T>::empty() {
    return !(this->m_size > 0);
}

template <typename T>
size_t s21_vector<T>::get_size() {
    return this->m_size;
}

template <typename T>
size_t s21_vector<T>::get_capacity() {
    return this->m_capacity;
}

template <typename T>
T* s21_vector<T>::data() {
    T* current = new value_type[m_size];
    for (size_t i = 0; i < m_size; i++) {
        current[i] = this->arr[i];
    }
    this->arr = current;
    return this->arr;
}

template <typename T>
void s21_vector<T>::shrink_to_fit() {
    T* current = new value_type[this->m_size];
    for (size_t i = 0; i < m_size; i++)
        current[i] = this->arr[i];
    delete [] arr;
    this->arr = new value_type[this->m_size];
    m_capacity = m_size;
    for (size_t i = 0; i < this->m_size; i++)
        this->arr[i] = current[i];
}

template <typename T>
size_t s21_vector<T>::max_size() {
    return (MAX_SIZE_VECTOR/sizeof(T)) * sizeof(T);
}

template <typename T>
void s21_vector<T>::reserve(size_type m_size) {
    T* current = new value_type[m_size];
    for (size_t i = 0; i < m_size; i++)
        current[i] = this->arr[i];
}

template <typename T>
T& s21_vector<T>::at(size_type pos) {
    return arr[pos];
}

template <typename T>
void s21_vector<T>::push_back(const_reference value) {
    if (m_size == m_capacity) {
        reserve_more_capacity(m_size * 2);
    }
    arr[m_size++] = value;
}

template <typename T>
void s21_vector<T>::pop_back() {
    T* current = new value_type[m_capacity];
    for (size_t i = 0, x = 0; i < m_capacity; i++, x++) {
        if (i != (m_size - 1))
            current[x] = arr[i];
        else
            x--;
    }
    m_size--;
    arr = current;
}

template <typename T>
void s21_vector<T>::swap(s21_vector& other) {
    s21_vector<T> temp(*this);
    *this = other;
    other = temp;
    other.m_size-=1;
    this->m_size-=1;
}

template <typename T>
T* s21_vector<T>::insert(iterator pos, const_reference value) {
    bool flag = true;
    if (pos == this->begin()) {
        push_back(value);
    } else {
        value_type *buff = new value_type[m_capacity + 1];
        for (size_t i = 0, x = 0; i < m_capacity; i++, x++) {
            if((pos == (this->arr + i)) || (pos == (this->arr + m_size))) {
                if (pos != (this->arr + m_size))
                    buff[x++] = value;
                else
                    buff[m_size] = value;
                flag = false;
            }
            buff[x] = this->arr[i];
        }
        if (!flag) {
            delete [] arr;
            m_size++;
            this->arr = buff;
        } else {
            delete [] buff;
            push_back(this->front());
        }
    }
    return this->arr;
}

template <typename T>
void s21_vector<T>::erase(iterator pos) {
    value_type *buff = new value_type[m_capacity - 1];
    for (size_t i = 0, x = 0; i < m_capacity; i++, x++) {
        if(pos == (this->arr + i - 1))
            x--;
        buff[x] = this->arr[i];
    }
    delete [] arr;
    m_size--;
    this->arr = buff;
}

template <typename T>
void s21_vector<T>::clear() {
    while (m_size) {
        this->pop_back();
    }
}

template class s21_vector<int>;