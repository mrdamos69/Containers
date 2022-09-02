#pragma once
#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include <initializer_list>
#include <iostream>
#include <utility>

#include "../s21_abstract_class.h"
#define MAX_SIZE_QUEUE 768614336404564650

namespace s21 {
template <typename T>
class s21_queue : public abstract_containers_list<T> {
 private:
  void push_front(T data);
  void reverse();
  void clear();

 public:
  using value_type = T;  // Tопределяет тип элемента (T — параметр шаблона)
  using reference = T &;  // T &определяет тип ссылки на элемент
  using const_reference =
      const T &;  // const T &определяет тип постоянной ссылки
  using size_type = size_t;  // size_tопределяет тип размера контейнера
                             // (стандартный тип — size_t)

  s21_queue()
      : abstract_containers_list<T>() {
  }  // конструктор по умолчанию, создает пустой стек
  s21_queue(std::initializer_list<value_type> const
                &items);  // конструктор списка инициализаторов
  s21_queue(const s21_queue &q);  // конструктор копирования
  s21_queue(s21_queue &&q);  // конструктор перемещения
  ~s21_queue();              // деструктор

  s21_queue<T> &operator=(const s21_queue &s);
  // Перегрузка оператора присваивания для движущегося объекта

  const_reference front();  // получить доступ к первому элементу
  const_reference back();  //

  void push(value_type data);  // добавляет элемент в голову
  void pop();                  // удаляет первый элемент
  void swap(s21_queue &other);  // Меняет местами элементы двух списков
  size_t max_size() override;

  template <typename... Arg>
  void emplace_back(
      T value,
      Arg &&...args);  // добавляет новые элементы в конец контейнера
  void emplace_back() {}
};
// #include "queue.cc"
}  // namespace s21

#endif  // S21_QUEUE_H
