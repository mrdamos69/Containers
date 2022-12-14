#pragma once
#ifndef S21_MAP_H
#define S21_MAP_H
#include <initializer_list>
#include <utility>

#include "../s21_abstract_class.h"
#include "../vector/vector.h"

namespace s21 {
template <typename T, typename T2>
class const_iterator_map {
 public:
  Key_Map<T, T2> *const_current;
  const_iterator_map() : const_current(0) {}
  explicit const_iterator_map(Key_Map<T, T2> *curr) : const_current(curr) {}
  std::pair<T, T2> &operator*() { return const_current->data_; }
  bool operator==(const const_iterator_map &right);
  bool operator!=(const const_iterator_map &right);
};

template <typename T, typename T2>
class iterator_map : public const_iterator_map<T, T2> {
 public:
  iterator_map() : const_iterator_map<T, T2>() {}
  iterator_map(Key_Map<T, T2> *curr) : const_iterator_map<T, T2>(curr) {}
  iterator_map &operator++();
  iterator_map &operator--();

 private:
  bool it_end();
};

template <typename T, typename T2>
class s21_map : public abstract_containers_tree<T> {
 private:
  Key_Map<T, T2> *element;
  Key_Map<T, T2> *back_elem;

 public:
  using key_type = T;  // первый параметр шаблона (ключ)
  using mapped_type = T2;  // второй параметр шаблона (T)
  using value_type =
      std::pair<const key_type, mapped_type>;  // Пара ключ-значение
  using reference = T &;  // определяет тип ссылки на элемент
  using const_reference = const T &;  // определяет тип постоянной ссылки
  using iterator = iterator_map<T, T2>;
  using const_iterator = const const_iterator_map<T, T2>;
  using size_type = size_t;  // определяет тип размера контейнера

  s21_map()
      : abstract_containers_tree<T>(), element(nullptr), back_elem(nullptr) {}
  // конструктор по умолчанию
  s21_map(std::initializer_list<value_type> const &items);
  // конструктор списка инициализаторов
  s21_map(const s21_map &m);  // конструктор копирования
  s21_map(s21_map &&m);       // конструктор перемещения
  ~s21_map();                 // деструктор
  s21_map<key_type, mapped_type> operator=(const s21_map &m);

  T &at(const Key_Map<key_type, mapped_type> &key);
  // доступ к указанному элементу с проверкой границ
  T2 &operator[](const Key_Map<key_type, mapped_type> &key);
  // получить доступ или вставить указанный элемент
  T2 &operator[](const key_type &key);

  iterator begin();  // возвращает итератор в начало
  iterator end();    // возвращает итератор в конец

  void clear();  // очищает содержимое
  void clear(Key_Map<key_type, mapped_type> *key);

  std::pair<iterator, bool> insert(const value_type &value);
  // вставляет узел и возвращает итератор туда, где элемент находится
  // в контейнере, и логическое значение, обозначающее, имела ли место вставка

  std::pair<iterator, bool> insert(const key_type &key, const mapped_type &obj);
  // вставляет значение по ключу и возвращает итератор туда,
  // где элемент находится в контейнере, и логическое значение, обозначающее,
  // имела ли место вставка

  std::pair<iterator, bool> insert_or_assign(const key_type &key,
                                             const mapped_type &obj);
  // вставляет элемент или присваивает значение текущему элементу,
  // если ключ уже существует

  void erase(iterator pos);   // стирает элемент в позиции
  void swap(s21_map &other);  // меняет содержимое
  void merge(const s21_map &other);  // соединяет узлы из другого контейнера

  bool contains(const key_type &key);
  // проверяет, содержит ли контейнер элемент с определенным ключом
  iterator contains(const value_type &key);

  template <typename... Arg>
  s21::s21_vector<std::pair<iterator, bool>> emplace(std::pair<T, T2> value,
                                                     Arg &&...args);
  bool emplace() { return true; }

 private:
  std::pair<iterator, bool> input_in_branch(Key_Map<T, T2> *branch,
                                            const value_type &value);
  void I_ll_be_back();
  void back_to_root();
  Key_Map<T, T2> *go_to_begin(Key_Map<T, T2> *key);
  void set_copy(Key_Map<T, T2> *other);
  s21_map<T, T2> set_merge(s21_map &other);
};
}  // namespace s21

#endif  // S21_MAP_H
