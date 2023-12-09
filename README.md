# s21_containers

Implementation of the `s21_containers.h` library in C++, which includes standard container classes such as `list`, `map`, `queue`, `set`, `stack`, and `vector`. The library adheres to the C++17 standard and is developed using the GCC compiler. The code follows the Google Style, is contained within the `s21` namespace, and features comprehensive unit tests using the GTest library.

## Introduction

As part of this project, a custom library (`s21_containers.h`) has been developed, implementing essential standard container classes in C++. The library provides a comprehensive set of standard methods and attributes for each container, including `list`, `map`, `queue`, `set`, `stack`, and `vector`. Additionally, less commonly used container classes with varying implementation details have been included as part of the library.

- **Language:** C++ (C++17 standard).
- **Compiler:** GCC.
- **Coding Style:** Google Style.
- **Namespace:** `s21`.
- **Testing:** Full coverage with GTest library.
- **No STL:** The implementation does not rely on the Standard Template Library (STL).
- **Logic Adherence:** The logic of the Standard Template Library (STL) has been observed during development.

## Part 1. Implementation of `s21_containers.h` library

The primary library (`s21_containers.h`) includes classes such as `list`, `map`, `queue`, `set`, `stack`, and `vector`. The solution is provided in a header file (`s21_containers.h`), with separate header files for container implementations (`s21_list.h`, `s21_map.h`, etc.). The project includes a Makefile for running tests.

## Part 2. Implementation of `s21_containersplus.h` library

The extended library (`s21_containersplus.h`) introduces additional functions for less commonly used container classes, including `array` and `multiset`. Similar to Part 1, the solution is provided in a header file (`s21_containersplus.h`), with separate header files for container implementations (`s21_array.h`, `s21_multiset.h`). A Makefile is included for running tests, and the final choice of algorithms remains flexible.

## Part 3. Implementation of modified `emplace` methods

The classes have been enhanced with modified `emplace` methods, following the specifications outlined in the table:

| Modifiers | Definition | Containers |
| ---------- | ----------------------------------------------- | ------------------------------------- |
| `iterator emplace(const_iterator pos, Args&&... args)` | Inserts new elements into the container directly before `pos`. | List, Vector |
| `void emplace_back(Args&&... args)` | Appends new elements to the end of the container. | List, Vector, Queue |
| `void emplace_front(Args&&... args)` | Appends new elements to the top of the container. | List, Stack |
| `std::pair<iterator,bool> emplace(Args&&... args)` | Inserts new elements into the container. | Map, Set, Multiset |

## Usage

To run tests for the libraries, use the provided Makefile with the following goals:

```bash
make clean   # Clean the project files
make test    # Run tests
