#pragma once
#ifndef s21_ABSTRACT_CLASS_H
#define s21_ABSTRACT_CLASS_H

namespace s21 {
    // template<typename T>
    // using value_type = T;  // Tопределяет тип элемента (T — параметр шаблона)

    // template<typename T>
    // using reference = T &;  // T &определяет тип ссылки на элемент

    // template<typename T>
    // using const_reference = const T &;  // const T &определяет тип постоянной ссылки

    // template<typename T>
    // using size_type = size_t;  // size_tопределяет тип размера контейнера (стандартный тип — size_t)

    template<typename T>
    class abstract_iterator {
    public:
        virtual T& operator *() = 0;
    };

    template<typename T>
    class abstract_containers {
    public:
        // using value_type = T;  // Tопределяет тип элемента (T — параметр шаблона)
        // using reference = T &;  // T &определяет тип ссылки на элемент
        // using const_reference = const T &;  // const T &определяет тип постоянной ссылки
        // using size_type = size_t;  // size_tопределяет тип размера контейнера (стандартный тип — size_t)

        // virtual bool empty() = 0;
        // virtual size_type get_size() = 0;
        // virtual size_type max_size() = 0;
        virtual void swap() = 0;
        virtual void clear() = 0;
    };
}

#endif  // s21_ABSTRACT_CLASS_H