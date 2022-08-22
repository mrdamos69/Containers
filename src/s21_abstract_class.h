#pragma once
#ifndef s21_ABSTRACT_CLASS_H
#define s21_ABSTRACT_CLASS_H

namespace s21 {
    template<typename T>
    class abstract_iterator {
    public:
        virtual T& operator *() = 0;
    };

    template<typename T>
    class abstract_containers {
    private:
        size_t m_size;
    public:
        abstract_containers() : m_size(0) {}
        virtual size_t max_size();
        virtual bool empty();
        virtual size_t get_size();
    };

}

#endif  // s21_ABSTRACT_CLASS_H