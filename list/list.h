#pragma once
#ifndef S21_LIST_H
#define S21_LIST_H

#include <initializer_list>
#include <utility>

#include "../s21_abstract_class.h"

#define MAX_SIZE_LIST 768614336404564650

namespace s21 {
template <typename T>
class const_iterator_cl : public abstract_iterator<T> {
 public:
  Node<T> *const_current;
  Node<T> *begin_current;
  const_iterator_cl() : const_current(0) {}
  explicit const_iterator_cl(Node<T> *curr) : const_current(curr) {
    begin_current = const_current;
  }
  T &operator*() { return const_current->data_; }
  bool operator==(const const_iterator_cl &right);
  bool operator!=(const const_iterator_cl &right);
};

template <typename T>
class iterator_cl : public const_iterator_cl<T> {
 public:
  iterator_cl() : const_iterator_cl<T>() {}
  iterator_cl(Node<T> *curr) : const_iterator_cl<T>(curr) {}
  iterator_cl &operator++();
  iterator_cl &operator++(int);
  iterator_cl &operator--();
  iterator_cl &operator--(int);

  void set_current(Node<T> *other);
};

template <typename T>
class s21_list : public abstract_containers_list<T> {
 public:
  using value_type = T;  // Tопределяет тип элемента (T — параметр шаблона)
  using reference = T &;  // T &определяет тип ссылки на элемент
  using const_reference =
      const T &;  // const T &определяет тип постоянной ссылки
  using iterator = iterator_cl<T>;
  // внутренний класс ListIterator<T>определяет тип для итерации по контейнеру
  using const_iterator = const_iterator_cl<T>;
  // внутренний класс ListConstIterator<T>определяет тип константы для итерации
  // по контейнеру
  using size_type = size_t;
  // size_tопределяет тип размера контейнера (стандартный тип — size_t)

  s21_list() : abstract_containers_list<T>() {}
  // конструктор по умолчанию, создает пустой список

  explicit s21_list(size_type n);
  // параметризованный конструктор, создает список размера n
  s21_list(std::initializer_list<value_type> const &items);
  // конструктор списка инициализаторов
  s21_list(const s21_list &l);  // конструктор копирования
  s21_list(s21_list &&l);       // конструктор перемещения
  ~s21_list();                  // деструктор
  reference operator[](const int index);
  // Перегрузка оператора индексации по объекту
  s21_list<T> &operator=(const s21_list &l);
  // Перегрузка оператора присваивания для движущегося объекта
  size_type max_size() override;
  // возвращает максимально возможное количество элементов

  void push_back(value_type data_);  // добавляет элемент в конец
  void push_front(value_type data_);  // добавляет элемент в голову
  void pop_back();   // удаляет последний элемент
  void pop_front();  // удаляет первый элемент

  iterator insert(size_t index, value_type value);
  // вставляет элемент в конкретную позицию
  iterator insert(iterator pos, const_reference value);

  void erase(int index);  // стирает элемент в позиции
  void swap(s21_list &other);  // Меняет местами элементы двух списков
  void merge(const s21_list &other);  // объединяет два отсортированных списка
  void splice(const_iterator pos, s21_list other);
  // переносит элементы из списка other начиная с pos
  void reverse();  // меняет порядок элементов
  void unique();  // удаляет последовательные повторяющиеся элементы
  void sort();    // сортирует элементы

  const_reference front();  // получить доступ к первому элементу
  const_reference back();  // получить доступ к последнему элементу

  iterator begin() { return this->head_; }  // возвращает итератор в начало
  iterator end() { return this->tail_; }  // возвращает итератор в конец

  template <typename... Arg>
  iterator emplace(iterator pos, T value, Arg &&...args);
  iterator emplace(iterator pos) { return pos; }
  // вставляет новые элементы в контейнер непосредственно перед pos

  template <typename... Arg>
  void emplace_back(T value, Arg &&...args);
  // добавляет новые элементы в конец контейнера
  void emplace_back() {}

  template <typename... Arg>
  void emplace_front(T value, Arg &&...args);
  // добавляет новые элементы в верхнюю часть контейнера
  void emplace_front() {}

  void clear();  // очищает содержимое

  void set_copy(Node<T> *other, Node<T> *end);
};
// #include "list.cc"
}  // namespace s21

#endif  // S21_LIST_H
