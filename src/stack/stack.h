#pragma once
#ifndef S21_STACK_H
#define S21_STACK_H

#include <initializer_list>
#include <utility>

#include "../s21_abstract_class.h"

namespace s21 {
template <typename T>
class s21_stack : public abstract_containers_list<T> {
 private:
  void push_back(T data_);
  void reverse();

 public:
  using value_type = T;  // Tопределяет тип элемента (T — параметр шаблона)
  using reference = T &;  // T &определяет тип ссылки на элемент
  using const_reference =
      const T &;  // const T &определяет тип постоянной ссылки
  using size_type = size_t;  // size_tопределяет тип размера контейнера
                             // (стандартный тип — size_t)
  s21_stack() : abstract_containers_list<T>() {}
  // конструктор по умолчанию, создает пустой стек

  s21_stack(std::initializer_list<value_type> const &items);
  // конструктор списка инициализаторов

  explicit s21_stack(const s21_stack &s);  // конструктор копирования
  s21_stack(s21_stack &&s);  // конструктор перемещения
  ~s21_stack();              // деструктор
  s21_stack<T> &operator=(const s21_stack &s);
  // Перегрузка оператора присваивания для движущегося объекта
  const_reference top();  // получить доступ к первому элементу
  void push(value_type data_);  // добавляет элемент в голову
  void pop();                   // удаляет первый элемент
  void swap(s21_stack &other);  // Меняет местами элементы двух списков
  void clear();

  template <typename... Arg>
  void emplace_front(T value, Arg &&...args);
  // добавляет новые элементы в верхнюю часть контейнера

  void emplace_front() {}
};
}  // namespace s21

#endif  // S21_STACK_H
