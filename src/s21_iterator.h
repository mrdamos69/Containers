#pragma once
#include <iostream>

namespace s21 {
    template<typename T>
    class iterator {
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::forward_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
    
    iterator(T* curr) : current(curr){}
    iterator& operator = (const iterator& other);
    iterator& operator ++();
    iterator operator ++(int i);
    T& operator *() {return *current;}
    T* operator ->() {return current;}
    bool operator ==(const iterator& other) {return current == other.current;}
    bool operator !=(const iterator& other) {return !(*this == other);}
    private:
        T* current;
    };
}
