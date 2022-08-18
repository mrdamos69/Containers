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
    public:
        virtual void swap() = 0;
        virtual void clear() = 0;
    };

    template<typename T, typename T2>
    class abstract_key {
    public:
        abstract_key* pLeft = nullptr;
        abstract_key* pRight = nullptr;
        abstract_key* pBack = nullptr;
        abstract_key* pRoot = nullptr;
    };
}

#endif  // s21_ABSTRACT_CLASS_H