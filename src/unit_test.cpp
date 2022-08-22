#include <gtest/gtest.h>
#include <iostream>
#include "s21_list.h"
#include "s21_list.cpp"
#include "s21_vector.h"
// #include "s21_vector.cpp"
#include "s21_array.h"
// #include "s21_array.cpp"
#include "s21_stack.h"
// #include "s21_stack.cpp"
#include "s21_queue.h"
// #include "s21_queue.cpp"
#include "s21_set.h"
// #include "s21_set.cpp"
#include "s21_map.h"
#include <list>
#include <vector>
#include <array>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace s21;
using std::cout;
using std::endl;
using std::list;
using std::stack;
using std::queue;
using std::vector;
using std::array;
using std::set;
using std::map;

/**********************/
/***** ___LIST___ *****/
/**********************/

TEST(Test_s21_list, s21_list_test_list) {
    s21_list<int> s21_list_1;
    list<int> std_list_1;
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_list_parametr) {
    s21_list<int> s21_list_1(5);
    list<int> std_list_1(5);
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_list_construct_copy) {
    s21_list<int> s21_list_1 {10, 5, 15, 13};
    s21_list<int> s21_list_2(s21_list_1);

    list<int> std_list_1 {10, 5, 15, 13};
    list<int> std_list_2(std_list_1);
    
    int y = 0;
    for (auto &i : std_list_2) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_2[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_sort_1) {
    s21_list<int> s21_list_1 {10, 5, 15, 13};
    list<int> std_list_1 {10, 5, 15, 13};
    s21_list_1.sort();
    std_list_1.sort();
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_marge_1) {
    s21_list<int> s21_list_1 {1, 2, 3, 4};
    s21_list<int> s21_list_2 {1, 2, 3, 4};
    s21_list_1.merge(s21_list_2);
    list<int> std_list_1 {1, 2, 3, 4};
    list<int> std_list_2 {1, 2, 3, 4};
    std_list_1.merge(std_list_2);
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_marge_2) {
    s21_list<int> s21_list_1 {1, 2, 3, 4};
    s21_list<int> s21_list_2 {5, 6};
    s21_list_1.merge(s21_list_2);
    list<int> std_list_1 {1, 2, 3, 4};
    list<int> std_list_2 {5, 6};
    std_list_1.merge(std_list_2);
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_marge_3) {
    s21_list<int> s21_list_1 {1, 2};
    s21_list<int> s21_list_2 {3, 4, 5, 6};
    s21_list_1.merge(s21_list_2);
    list<int> std_list_1 {1, 2};
    list<int> std_list_2 {3, 4, 5, 6};
    std_list_1.merge(std_list_2);
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_insert_1) {
    s21_list<int> s21_list_1 {10, 5, 15, 13};
    list<int> std_list_1 {10, 5, 15, 13};
    auto s21_result = s21_list_1.insert(1, 111111);

    auto x = std_list_1.begin();
    ++x;
    auto std_result = std_list_1.insert(x, 111111);
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
    // cout << "\n" << "std_list: " << *std_result << " " << "s21_list: " << *s21_result << endl;
    ASSERT_EQ(*s21_result, *std_result);
}

TEST(Test_s21_list, s21_list_test_insert_2) {
    s21_list<int> s21_list_1 {10, 5, 15, 13};
    auto y = s21_list_1.begin();
    ++y;
    auto s21_result = s21_list_1.insert(y, 111111);
    ++y;
    s21_list_1.insert(y, 999);

    list<int> std_list_1 {10, 5, 15, 13};
    auto x = std_list_1.begin();
    ++x;
    auto std_result = std_list_1.insert(x, 111111);
    ++x;
    std_list_1.insert(x, 999);

    int j = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[j++] << endl;
        ASSERT_EQ(i, s21_list_1[j++]);
    }
    // cout << "\n" << "std_list: " << *std_result << " " << "s21_list: " << *s21_result << endl;
    ASSERT_EQ(*s21_result, *std_result);
}

TEST(Test_s21_list, s21_list_test_erase_1) {
    s21_list<int> s21_list_1 {10, 5, 15, 13};
    list<int> std_list_1 {10, 5, 15, 13};
    s21_list_1.erase(0);
    std_list_1.erase(std_list_1.begin());
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_swap_1) {
    s21_list<int> s21_list_1 {1, 2, 3, 4};
    s21_list<int> s21_list_2 {5, 6, 7, 8};
    s21_list_1.swap(s21_list_2);
    list<int> std_list_1 {1, 2, 3, 4};
    list<int> std_list_2 {5, 6, 7, 8};
    std_list_1.swap(std_list_2);
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_swap_2) {
    s21_list<int> s21_list_1 {1, 2};
    s21_list<int> s21_list_2 {3, 4, 5, 6};
    s21_list_1.swap(s21_list_2);
    list<int> std_list_1 {1, 2};
    list<int> std_list_2 {3, 4, 5, 6};
    std_list_1.swap(std_list_2);
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_swap_3) {
    s21_list<int> s21_list_1 {1, 2, 3, 4};
    s21_list<int> s21_list_2 {5, 6};
    s21_list_1.swap(s21_list_2);
    list<int> std_list_1 {1, 2, 3, 4};
    list<int> std_list_2 {5, 6};
    std_list_1.swap(std_list_2);
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_unique_1) {
    s21_list<int> s21_list_1 {10, 10, 5, 5, 15, 13, 13};
    list<int> std_list_1 {10, 10, 5, 5, 15, 13, 13};
    s21_list_1.unique();
    std_list_1.unique();
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_reverse_1) {
    s21_list<int> s21_list_1 {10, 10, 5, 5, 15, 13, 13};
    list<int> std_list_1 {10, 10, 5, 5, 15, 13, 13};
    s21_list_1.reverse();
    std_list_1.reverse();
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_reverse_2) {
    s21_list<int> s21_list_1 {10};
    list<int> std_list_1 {10};
    s21_list_1.reverse();
    std_list_1.reverse();
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_empty_1) {
    s21_list<int> s21_list_1 {10, 10, 5, 5, 15, 13, 13};
    list<int> std_list_1 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_EQ(std_list_1.empty(), s21_list_1.empty());
}

TEST(Test_s21_list, s21_list_test_empty_2) {
    s21_list<int> s21_list_1;
    list<int> std_list_1;
    ASSERT_EQ(std_list_1.empty(), s21_list_1.empty());
}

TEST(Test_s21_list, s21_list_test_get_size_1) {
    s21_list<int> s21_list_1 {10, 10, 5, 5, 15, 13, 13};
    list<int> std_list_1 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_EQ(std_list_1.size(), s21_list_1.get_size());
}

TEST(Test_s21_list, s21_list_test_max_size_1) {
    s21_list<char> s21_list_1 {10, 10, 5, 5, 15, 13, 13};
    list<char> std_list_1 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_EQ(std_list_1.max_size(), s21_list_1.max_size());
    // cout << "std_list MAX_SIZE: " << std_list_1.max_size() << " " << "s21_list MAX_SIZE: " << s21_list_1.max_size() << endl;
}

TEST(Test_s21_list, s21_list_test_push_back_1) {
    s21_list<int> s21_list_1 {10, 10, 5, 5, 15, 13, 13};
    list<int> std_list_1 {10, 10, 5, 5, 15, 13, 13};
    s21_list_1.push_back(777);
    std_list_1.push_back(777);
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_push_front_1) {
    s21_list<int> s21_list_1 {10, 10, 5, 5, 15, 13, 13};
    list<int> std_list_1 {10, 10, 5, 5, 15, 13, 13};
    s21_list_1.push_front(777);
    s21_list_1.push_front(666);

    std_list_1.push_front(777);
    std_list_1.push_front(666);
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_push_front_2) {
    s21_list<int> s21_list_1;
    list<int> std_list_1;
    s21_list_1.push_front(11);
    s21_list_1.push_front(22);
    s21_list_1.push_front(33);

    std_list_1.push_front(11);
    std_list_1.push_front(22);
    std_list_1.push_front(33);
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }  
}

TEST(Test_s21_list, s21_list_test_pop_back_1) {
    s21_list<int> s21_list_1 {10, 10, 5, 5, 15, 13, 13};
    list<int> std_list_1 {10, 10, 5, 5, 15, 13, 13};
    s21_list_1.pop_back();
    std_list_1.pop_back();
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_pop_front_1) {
    s21_list<int> s21_list_1 {10, 10, 5, 5, 15, 13, 13};
    list<int> std_list_1 {10, 10, 5, 5, 15, 13, 13};
    s21_list_1.pop_front();
    std_list_1.pop_front();
    int y = 0;
    for (auto &i : std_list_1) {
        // cout << "std_list: " << i << " " << "s21_list: " << s21_list_1[y++] << endl;
        ASSERT_EQ(i, s21_list_1[y++]);
    }
}

TEST(Test_s21_list, s21_list_test_front_1) {
    s21_list<int> s21_list_1 {10, 10, 5, 5, 15, 13, 13};
    list<int> std_list_1 {10, 10, 5, 5, 15, 13, 13};
    // cout << "std_list: " << std_list_1.front() << " " << "s21_list: " << s21_list_1.front() << endl;
    ASSERT_EQ(std_list_1.front(), s21_list_1.front());
}

TEST(Test_s21_list, s21_list_test_back_1) {
    s21_list<int> s21_list_1 {10, 10, 5, 5, 15, 13, 13};
    list<int> std_list_1 {10, 10, 5, 5, 15, 13, 13};
    // cout << "std_list: " << std_list_1.back() << " " << "s21_list: " << s21_list_1.back() << endl;
    ASSERT_EQ(std_list_1.back(), s21_list_1.back());
}

TEST(Test_s21_list, s21_list_test_begin_end) {
    s21_list<int> s21_list_1 {10, 10, 5, 5, 15, 13};
    list<int> std_list_1 {10, 10, 5, 5, 15, 13};
    auto y = std_list_1.begin();
    for (auto &i : s21_list_1) {
        ASSERT_EQ(i, *y);
        y++;
    }
}

TEST(Test_s21_list, s21_list_test_splice) {
    s21_list<int> s21_list_1 {10, 9, 5, 6, 15, 7};
    s21_list<int> s21_list_2 {4, 7, 2, 6};

    auto i = s21_list_1.begin();
    i++;
    s21_list_1.splice(i, s21_list_2);

    list<int> std_list_1 {10, 9, 5, 6, 15, 7};
    list<int> std_list_2 {4, 7, 2, 6};

    auto y = std_list_1.begin();
    y++;
    std_list_1.splice(y, std_list_2);
    
    int count = 0;
    for (auto &n : std_list_1) {
        // cout << "std_list: " << n << " " << "s21_list: " << s21_list_1[count++] << endl;
        ASSERT_EQ(n, s21_list_1[count++]);
    }
}

TEST(Test_s21_list, s21_list_test_operator_minus_minus) {
    s21_list<int> s21_list_1 {10, 9, 5, 5, 15, 13, 8};
    list<int> std_list_1 {10, 9, 5, 5, 15, 13, 8};
    auto y = std_list_1.end();
    for (auto i = s21_list_1.end(); i != s21_list_1.begin(); i--) {
        // cout << "std_list: " << *y << " " << "s21_list: " << *i << endl;
        if(i != s21_list_1.end()) {ASSERT_EQ(*i, *y);}
        y--;
    }
}

/**********************/
/**** ___VECTOR___ ****/
/**********************/

TEST(Test_s21_vector, s21_vector_test_vector) {
    s21_vector<int> s21_vector_1;
    vector<int> std_vector_1;
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
}

TEST(Test_s21_vector, s21_vector_test_list_param) {
    s21_vector<int> s21_vector_1(5);
    vector<int> std_vector_1(5);
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
}

TEST(Test_s21_vector, s21_vector_test_insert_1) {
    s21_vector<int> s21_vector_1 {10, 5, 15, 13};
    s21_vector<int>::iterator s21_itr = s21_vector_1.begin();
    s21_itr += 3;

    vector<int> std_vector_1 {10, 5, 15, 13};
    vector<int>::iterator std_itr = std_vector_1.begin();
    std_itr += 3;

    s21_vector_1.insert(s21_itr, 777);
    std_vector_1.insert(std_itr, 777);
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
}

TEST(Test_s21_vector, s21_vector_test_insert_2) {
    s21_vector<int> s21_vector_1 {10, 5, 15, 13};
    s21_vector<int>::iterator s21_itr = s21_vector_1.begin();
    s21_itr += 4;

    vector<int> std_vector_1 {10, 5, 15, 13};
    vector<int>::iterator std_itr = std_vector_1.begin();
    std_itr += 4;

    s21_vector_1.insert(s21_itr, 777);
    std_vector_1.insert(std_itr, 777);
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
}

TEST(Test_s21_vector, s21_vector_test_erase_1) {
    s21_vector<int> s21_vector_1 {10, 5, 15, 13};
    s21_vector<int>::iterator s21_itr = s21_vector_1.begin();
    s21_itr += 2;

    vector<int> std_vector_1 {10, 5, 15, 13};
    vector<int>::iterator std_itr = std_vector_1.begin();
    std_itr += 2;

    s21_vector_1.erase(s21_itr);
    std_vector_1.erase(std_itr);
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
}

TEST(Test_s21_vector, s21_vector_test_erase_2) {
    s21_vector<int> s21_vector_1 {15, 13};
    s21_vector<int>::iterator s21_itr = s21_vector_1.begin();
    s21_itr += 1;
    vector<int> std_vector_1 {15, 13};
    vector<int>::iterator std_itr = std_vector_1.begin();
    std_itr += 1;
    s21_vector_1.erase(s21_itr);
    std_vector_1.erase(std_itr);
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
}

TEST(Test_s21_vector, s21_vector_test_erase_3) {
    s21_vector<int> s21_vector_1 {15, 13};
    s21_vector<int>::iterator s21_itr = s21_vector_1.begin();
    vector<int> std_vector_1 {15, 13};
    vector<int>::iterator std_itr = std_vector_1.begin();
    s21_vector_1.erase(s21_itr);
    std_vector_1.erase(std_itr);
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
}

TEST(Test_s21_vector, s21_vector_test_erase_4) {
    s21_vector<int> s21_vector_1 {15};
    s21_vector<int>::iterator s21_itr = s21_vector_1.begin();

    vector<int> std_vector_1 {15};
    vector<int>::iterator std_itr = std_vector_1.begin();

    s21_vector_1.erase(s21_itr);
    std_vector_1.erase(std_itr);
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
}

TEST(Test_s21_vector, s21_vector_test_swap_1) {
    s21_vector<int> s21_vector_1 {1, 2, 3, 4};
    s21_vector<int> s21_vector_2 {5, 6, 7, 8};
    s21_vector_1.swap(s21_vector_2);

    vector<int> std_vector_1 {1, 2, 3, 4};
    vector<int> std_vector_2 {5, 6, 7, 8};
    std_vector_1.swap(std_vector_2);

    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
    
}

TEST(Test_s21_vector, s21_vector_test_swap_2) {
    s21_vector<int> s21_vector_1 {1, 2, 3, 4};
    s21_vector<int> s21_vector_2 {5, 6};
    s21_vector_1.swap(s21_vector_2);

    vector<int> std_vector_1 {1, 2, 3, 4};
    vector<int> std_vector_2 {5, 6};
    std_vector_1.swap(std_vector_2);

    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
    
}

TEST(Test_s21_vector, s21_vector_test_swap_3) {
    s21_vector<int> s21_vector_1 {1, 2};
    s21_vector<int> s21_vector_2 {3, 4, 5, 6};
    s21_vector_1.swap(s21_vector_2);

    vector<int> std_vector_1 {1, 2};
    vector<int> std_vector_2 {3, 4, 5, 6};
    std_vector_1.swap(std_vector_2);
    
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
    
}

TEST(Test_s21_vector, s21_vector_test_reverse_1) {
    s21_vector<int> s21_vector_1 {1, 2, 3, 4};
    vector<int> std_vector_1 {1, 2, 3, 4};
    s21_vector_1.reserve(3);
    std_vector_1.reserve(3);
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
}

TEST(Test_s21_vector, s21_vector_test_empty_1) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    vector<int> std_vector_1 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_EQ(std_vector_1.empty(), s21_vector_1.empty());
}

TEST(Test_s21_vector, s21_vector_test_empty_2) {
    s21_vector<int> s21_vector_1;
    vector<int> std_vector_1;
    ASSERT_EQ(std_vector_1.empty(), s21_vector_1.empty());
}

TEST(Test_s21_vector, s21_vector_test_get_size_1) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    vector<int> std_vector_1 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_EQ(std_vector_1.size(), s21_vector_1.get_size());
}

TEST(Test_s21_vector, s21_vector_test_max_size_1) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    vector<int> std_vector_1 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_FALSE(std_vector_1.max_size() == s21_vector_1.max_size());
}

TEST(Test_s21_vector, s21_vector_test_push_back_1) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    vector<int> std_vector_1 {10, 10, 5, 5, 15, 13, 13};
    s21_vector_1.push_back(999);
    std_vector_1.push_back(999);
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
}

TEST(Test_s21_vector, s21_vector_test_pop_back_1) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    vector<int> std_vector_1 {10, 10, 5, 5, 15, 13, 13};
    s21_vector_1.pop_back();
    std_vector_1.pop_back();
    int y = 0;
    for (auto &i : std_vector_1) {
        // cout << "std_vector: " << i << " " << "s21_vector: " << s21_vector_1[y++] << endl;
        ASSERT_EQ(i, s21_vector_1[y++]);
    }
}

TEST(Test_s21_vector, s21_vector_test_front_1) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    vector<int> std_vector_1 {10, 10, 5, 5, 15, 13, 13};
    // cout << "std_list: " << std_vector_1.front() << " " << "s21_list: " << std_vector_1.front() << endl;
    ASSERT_EQ(std_vector_1.front(), std_vector_1.front());
}

TEST(Test_s21_vector, s21_vector_test_back_1) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    vector<int> std_vector_1 {10, 10, 5, 5, 15, 13, 13};
    // cout << "std_list: " << std_vector_1.back() << " " << "s21_list: " << std_vector_1.back() << endl;
    ASSERT_EQ(std_vector_1.back(), s21_vector_1.back());
}

TEST(Test_s21_vector, s21_vector_test_begin_end) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    vector<int> std_vector_1 {10, 10, 5, 5, 15, 13, 13};
    for (auto &&i : std_vector_1) {
        for (auto &&y : s21_vector_1) {
            if (i == y) {ASSERT_EQ(i, y);}
        }
    }
}

TEST(Test_s21_vector, s21_vector_test_data) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    vector<int> std_vector_1 {10, 10, 5, 5, 15, 13, 13};

    int* arr_1 = s21_vector_1.data();
    int* arr_2 = std_vector_1.data();

    for (size_t i = 0; i < 7; i++) {
        ASSERT_EQ(arr_1[i], arr_2[i]);
    }
}

TEST(Test_s21_vector, s21_vector_test_shrink_to_fit) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    vector<int> std_vector_1 {10, 10, 5, 5, 15, 13, 13};
    s21_vector_1.shrink_to_fit();
    std_vector_1.shrink_to_fit();
    ASSERT_TRUE(sizeof(std_vector_1) == sizeof(s21_vector_1));
}

TEST(Test_s21_vector, s21_vector_test_1) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    s21_vector_1[15] = 8;
    // cout << "s21: " << s21_vector_1[15] << endl;
    vector<int> std_vector_1 {10, 10, 5, 5, 15, 13, 13};
    std_vector_1[15] = 8;
    // cout << "std: " << std_vector_1[15] << endl;
    ASSERT_EQ(std_vector_1[15], s21_vector_1[15]);
}

TEST(Test_s21_vector, s21_vector_test_operator_eq_1) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    s21_vector<int> s21_vector_2 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_TRUE(s21_vector_1 == s21_vector_2);
}

TEST(Test_s21_vector, s21_vector_test_operator_eq_2) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    s21_vector<int> s21_vector_2 {10, 10, 5};
    ASSERT_FALSE(s21_vector_1 == s21_vector_2);
}

TEST(Test_s21_vector, s21_vector_test_operator_eq_3) {
    s21_vector<int> s21_vector_1 {10};
    s21_vector<int> s21_vector_2 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_FALSE(s21_vector_1 == s21_vector_2);
}

TEST(Test_s21_vector, s21_vector_test_iterator) {
    s21_vector<int> s21_vector_1 {10, 10, 5, 5, 15, 13, 13};
    vector<int> std_vector_2 {10, 10, 5, 5, 15, 13, 13};
    auto i = s21_vector_1.end();

    for (size_t y = 0; y < 4; y++)
        i++;
    // cout << *i << endl;
    
    auto i_2 = std_vector_2.end();
    for (size_t i = 0; i < 4; i++)
        i_2++;
    // cout << *i_2 << endl;

    ASSERT_EQ(*i, *i_2);
}

/**********************/
/***** ___ARRAY___ ****/
/**********************/

TEST(Test_s21_array, s21_array_test_array) {
    s21_array<int, 5> s21_array_1;
    array<int, 5> std_array_1;
    ASSERT_EQ(std_array_1.size(), s21_array_1.get_size());
}

TEST(Test_s21_array, s21_array_test_array_2) {
    s21_array<int, 3> s21_array_1 {1, 3, 5};
    s21_array<int, 3> s21_array_2(s21_array_1);

    array<int, 3> std_array_1 {1, 3, 5};
    array<int, 3> std_array_2(std_array_1);
    int y = 0;
    for (auto &i : std_array_2) {
        // cout << "std_array: " << i << " " << "s21_array: " << s21_array_2[y++] << endl;
        ASSERT_EQ(i, s21_array_2[y++]);
    }
}

TEST(Test_s21_array, s21_array_test_swap_1) {
    s21_array<int, 4> s21_array_1 {1, 2, 3, 4};
    s21_array<int, 4> s21_array_2 {5, 6, 7, 8};
    s21_array_1.swap(s21_array_2);

    array<int, 4> std_array_1 {1, 2, 3, 4};
    array<int, 4> std_array_2 {5, 6, 7, 8};
    std_array_1.swap(std_array_2);

    int y = 0;
    for (auto &i : std_array_1) {
        // cout << "std_array: " << i << " " << "s21_array: " << s21_array_1[y++] << endl;
        ASSERT_EQ(i, s21_array_1[y++]);
    }
}
TEST(Test_s21_array, s21_array_test_swap_2) {
    s21_array<int, 4> s21_array_1 {1, 2};
    s21_array<int, 4> s21_array_2 {3, 4, 5, 6};
    s21_array_1.swap(s21_array_2);

    array<int, 4> std_array_1 {1, 2};
    array<int, 4> std_array_2 {3, 4, 5, 6};
    std_array_1.swap(std_array_2);

    int y = 0;
    for (auto &i : std_array_1) {
        // cout << "std_array: " << i << " " << "s21_array: " << s21_array_1[y++] << endl;
        ASSERT_EQ(i, s21_array_1[y++]);
    }
}

TEST(Test_s21_array, s21_array_test_swap_3) {
    s21_array<int, 4> s21_array_1 {1, 2, 3, 4};
    s21_array<int, 4> s21_array_2 {5, 6};
    s21_array_1.swap(s21_array_2);

    array<int, 4> std_array_1 {1, 2, 3, 4};
    array<int, 4> std_array_2 {5, 6};
    std_array_1.swap(std_array_2);

    int y = 0;
    for (auto &i : std_array_1) {
        // cout << "std_array: " << i << " " << "s21_array: " << s21_array_1[y++] << endl;
        ASSERT_EQ(i, s21_array_1[y++]);
    }
}


TEST(Test_s21_array, s21_array_test_empty_1) {
    s21_array<int, 7> s21_array_1 {10, 10, 5, 5, 15, 13, 13};
    array<int, 7> std_array_1 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_EQ(std_array_1.empty(), s21_array_1.empty());
}

TEST(Test_s21_array, s21_array_test_empty_2) {
    s21_array<int, 0> s21_array_1;
    array<int, 0> std_array_1;
    ASSERT_EQ(std_array_1.empty(), s21_array_1.empty());
}

TEST(Test_s21_array, s21_array_test_get_size_1) {
    s21_array<int, 7> s21_array_1 {10, 10, 5, 5, 15, 13, 13};
    array<int, 7> std_array_1 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_EQ(std_array_1.size(), s21_array_1.get_size());
}

TEST(Test_s21_array, s21_array_test_max_size_1) {
s21_array<int, 7> s21_array_1 {10, 10, 5, 5, 15, 13, 13};
    array<int, 7> std_array_1 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_EQ(std_array_1.max_size(), s21_array_1.max_size());
}

TEST(Test_s21_array, s21_array_test_front_1) {
    s21_array<int, 7> s21_array_1 {10, 10, 5, 5, 15, 13, 13};
    array<int, 7> std_array_1 {10, 10, 5, 5, 15, 13, 13};
    // cout << "std_list: " << std_vector_1.front() << " " << "s21_list: " << std_vector_1.front() << endl;
    ASSERT_EQ(std_array_1.front(), s21_array_1.front());
}

TEST(Test_s21_array, s21_array_test_front_2) {
    s21_array<int, 7> s21_array_1 {10, 10, 5, 5, 15, 13, 13};
    array<int, 7> std_array_1 {10, 10, 5, 5, 15, 13, 13};
    // cout << "std_list: " << std_vector_1.front() << " " << "s21_list: " << std_vector_1.front() << endl;
    ASSERT_EQ(std_array_1.back(), s21_array_1.back());
}

TEST(Test_s21_array, s21_array_test_begin_end) {
    s21_array<int, 7> s21_array_1 {10, 10, 5, 5, 15, 13, 13};
    array<int, 7> std_array_1 {10, 10, 5, 5, 15, 13, 13};
    for (auto &&i : std_array_1) {
        for (auto &&y : s21_array_1) {
            if (i == y){ASSERT_EQ(i, y);}
        }
    }
}

TEST(Test_s21_array, s21_array_test_data) {
    s21_array<int, 7> s21_array_1 {10, 10, 5, 5, 15, 13, 13};
    array<int, 7> std_array_1 {10, 10, 5, 5, 15, 13, 13};

    int* arr_1 = s21_array_1.data();
    int* arr_2 = std_array_1.data();

    for (size_t i = 0; i < 7; i++) {
        ASSERT_EQ(arr_1[i], arr_2[i]);
    }
}

TEST(Test_s21_array, s21_array_test_operator_eq_1) {
    s21_array<int, 7> s21_array_1 {10, 10, 5, 5, 15, 13, 13};
    s21_array<int, 7> s21_array_2 {10, 10, 5, 5, 15, 13, 13};
    ASSERT_TRUE(s21_array_1 == s21_array_2);
}

// TEST(Test_s21_array, s21_array_test_operator_eq_2) {
//     s21_array<int, 7> s21_array_1 {10, 10, 5, 5, 15, 13, 13};
//     s21_array<int, 4> s21_array_2 {10, 10, 5, 5};
//     ASSERT_FALSE(s21_array_1 == s21_array_2);
// }

// TEST(Test_s21_array, s21_array_test_operator_eq_3) {
//     s21_array<int, 3> s21_array_1 {10};
//     s21_array<int, 4> s21_array_2 {10, 10, 5, 5};
//     ASSERT_FALSE(s21_array_1 == s21_array_2);
// }

TEST(Test_s21_array, s21_array_test_fill_1) {
    s21_array<int, 7> s21_array_1 {10, 10, 5, 5, 15, 13, 13};
    s21_array_1.fill(77777);
    array<int, 7> std_array_1 {10, 10, 5, 5, 15, 13, 13};
    std_array_1.fill(77777);
    int y = 0;
    for (auto &i : std_array_1) {
        // cout << "std_array: " << i << " " << "s21_array: " << s21_array_1[y++] << endl;
        ASSERT_EQ(i, s21_array_1[y++]);
    };
}

/**********************/
/***** ___STACK___ ****/
/**********************/

TEST(Test_s21_stack, s21_stack_test_stack_1) {
    s21_stack<int> s21_stack_1;
    for (size_t i = 0; i < 10; i++)
        s21_stack_1.push(i);
    
    stack<int> std_stack_1;
    for (size_t i = 0; i < 10; i++)
        std_stack_1.push(i);

    while(!std_stack_1.empty()) {
        ASSERT_EQ(std_stack_1.top(), s21_stack_1.top());
        // cout << "std_stack: " << std_stack_1.top() << " " << "s21_stack: " << s21_stack_1.top() << endl;
        std_stack_1.pop();
        s21_stack_1.pop();
    }
}

TEST(Test_s21_stack, s21_stack_test_stack_2) {
    s21_stack<int> s21_stack_1 {1, 2, 3, 4, 5};

    for (size_t i = 5; !s21_stack_1.empty(); i--) {
        ASSERT_EQ(i, s21_stack_1.top());
        // cout << "std_stack: " << std_stack_1.top() << " " << "s21_stack: " << s21_stack_1.top() << endl;
        s21_stack_1.pop();
    }
}

TEST(Test_s21_stack, s21_stack_test_operator_1) {
    s21_stack<int> s21_stack_1;
    s21_stack<int> s21_stack_2;
    for (size_t i = 0; i < 10; i++)
        s21_stack_1.push(i);
    s21_stack_2 = s21_stack_1;
    

    stack<int> std_stack_1;
    stack<int> std_stack_2;
    for (size_t i = 0; i < 10; i++)
        std_stack_1.push(i);
    std_stack_2 = std_stack_1;

    for (size_t i = s21_stack_1.get_size(); i > 0; i--) {
        // cout << "std_stack: " << std_stack_2.top() << " " << "s21_stack: " << s21_stack_2.top() << endl;
        ASSERT_EQ(std_stack_1.top(), s21_stack_1.top());
        std_stack_2.pop();
        s21_stack_2.pop();
    }
}

TEST(Test_s21_stack, s21_stack_test_swap) {
    s21_stack<int> s21_stack_1;
    s21_stack<int> s21_stack_2;
    for (int i = 0, y = 10; i < 10; i++, y--) {
        s21_stack_1.push(i);
        s21_stack_2.push(y);
    }
    s21_stack_1.swap(s21_stack_2);

    stack<int> std_stack_1;
    stack<int> std_stack_2;
    for (int i = 0, y = 10; i < 10; i++, y--) {
        std_stack_1.push(i);
        std_stack_2.push(y);
    }
    std_stack_1.swap(std_stack_2);

    for (size_t i = s21_stack_2.get_size(); i > 0; i--) {
        ASSERT_EQ(std_stack_2.top(), s21_stack_2.top());
        // cout << "std_stack 2: " << std_stack_2.top() << " " << "s21_stack 2: " << s21_stack_2.top() << endl;
        std_stack_2.pop();
        s21_stack_2.pop();
    }
    // cout << endl;

    for (size_t i = s21_stack_1.get_size(); i > 0; i--) {
        ASSERT_EQ(std_stack_1.top(), s21_stack_1.top());
        // cout << "std_stack 1: " << std_stack_1.top() << " " << "s21_stack 1: " << s21_stack_1.top() << endl;
        std_stack_1.pop();
        s21_stack_1.pop();
    }

}

TEST(Test_s21_stack, s21_stack_test_operator_eq_1) {
    s21_stack<int> s21_stack_1 {1, 2, 3, 4, 5, 6, 7};

    stack<int> std_stack_1;
    for (size_t i = 0; i < 8; i++)
        std_stack_1.push(i);
        
    // cout << std_stack_1.empty() << " " << s21_stack_1.empty() << endl;
    ASSERT_EQ(std_stack_1.empty(), s21_stack_1.empty());
}

TEST(Test_s21_stack, s21_stack_test_empty_2) {
    s21_stack<int> s21_stack_1;
    s21_stack<int> s21_stack_2;
    ASSERT_EQ(!s21_stack_1.empty(), !s21_stack_2.empty());
}

TEST(Test_s21_stack, s21_stack_test_size) {
    s21_stack<int> s21_stack_1;
    stack<int> std_stack_1;
    ASSERT_EQ(std_stack_1.size(), s21_stack_1.get_size());
}

/**********************/
/***** ___QUEUE___ ****/
/**********************/

TEST(Test_s21_queue, s21_queue_test_queue_1) {
    s21_queue<int> s21_queue_1;
    for (size_t i = 0; i < 10; i++)
        s21_queue_1.push(i);
    
    queue<int> std_queue_1;
    for (size_t i = 0; i < 10; i++)
        std_queue_1.push(i);

    while(!std_queue_1.empty()) {
        ASSERT_EQ(std_queue_1.front(), s21_queue_1.front());
        // cout << "std_queue: " << std_queue_1.front() << " " << "s21_queue: " << s21_queue_1.front() << endl;
        std_queue_1.pop();
        s21_queue_1.pop();
    }
}

TEST(Test_s21_queue, s21_queue_test_queue_2) {
    s21_queue<int> s21_queue_1 {5, 4, 3, 2, 1};

    for (size_t i = 5; !s21_queue_1.empty(); i--) {
        ASSERT_EQ(i, s21_queue_1.front());
        // cout << "std_stack: " << s21_queue_1.front() << " " << "s21_stack: " << s21_queue_1.front() << endl;
        s21_queue_1.pop();
    }
}

TEST(Test_s21_queue, s21_queue_test_operator_1) {
    s21_queue<int> s21_queue_1;
    s21_queue<int> s21_queue_2;
    for (size_t i = 0; i < 10; i++)
        s21_queue_1.push(i);
    s21_queue_2 = s21_queue_1;
    
    queue<int> std_queue_1;
    queue<int> std_queue_2;
    for (size_t i = 0; i < 10; i++)
        std_queue_1.push(i);
    std_queue_2 = std_queue_1;
    
    for (size_t i = s21_queue_1.get_size(); i > 0; i--) {
        // cout << "std_queue: " << std_queue_1.front() << " " << "s21_queue: " << s21_queue_1.front() << endl;
        ASSERT_EQ(std_queue_1.front(), s21_queue_1.front());
        std_queue_1.pop();
        s21_queue_1.pop();
    }

    for (size_t i = s21_queue_2.get_size(); i > 0; i--) {
        // cout << "std_queue: " << std_queue_2.front() << " " << "s21_queue: " << s21_queue_2.front() << endl;
        ASSERT_EQ(std_queue_2.front(), s21_queue_2.front());
        std_queue_2.pop();
        s21_queue_2.pop();
    }
}

TEST(Test_s21_queue, s21_queue_test_swap) {
    s21_queue<int> s21_queue_1;
    s21_queue<int> s21_queue_2;
    for (int i = 0, y = 10; i < 10; i++, y--) {
        s21_queue_1.push(i);
        s21_queue_2.push(y);
    }
    s21_queue_1.swap(s21_queue_2);

    queue<int> std_queue_1;
    queue<int> std_queue_2;
    for (int i = 0, y = 10; i < 10; i++, y--) {
        std_queue_1.push(i);
        std_queue_2.push(y);
    }
    std_queue_1.swap(std_queue_2);

    for (size_t i = s21_queue_2.get_size(); i > 0; i--) {
        ASSERT_EQ(std_queue_2.front(), s21_queue_2.front());
        // cout << "std_queue 2: " << std_queue_2.front() << " " << "s21_queue 2: " << s21_queue_2.front() << endl;
        std_queue_2.pop();
        s21_queue_2.pop();
    }
    // cout << endl;

    for (size_t i = s21_queue_1.get_size(); i > 0; i--) {
        ASSERT_EQ(std_queue_1.front(), s21_queue_1.front());
        // cout << "std_queue_1: " << std_queue_1.front() << " " << "s21_queue 1: " << s21_queue_1.front() << endl;
        std_queue_1.pop();
        s21_queue_1.pop();
    }

}

TEST(Test_s21_queue, s21_queue_test_empty_1) {
    s21_queue<int> s21_queue_1 {1, 2, 3, 4, 5, 6, 7};

    queue<int> std_queue_1;
    for (size_t i = 0; i < 8; i++)
        std_queue_1.push(i);

    // cout << std_queue_1.empty() << " " << s21_queue_1.empty() << endl;
    ASSERT_EQ(std_queue_1.empty(), s21_queue_1.empty());
}

TEST(Test_s21_queue, s21_queue_test_empty_2) {
    s21_queue<int> s21_queue_1;
    s21_queue<int> s21_queue_2;
    ASSERT_EQ(!s21_queue_1.empty(), !s21_queue_2.empty());
}

TEST(Test_s21_queue, s21_queue_test_size) {
    s21_queue<int> s21_queue_1;
    queue<int> std_queue_1;
    ASSERT_EQ(std_queue_1.size(), s21_queue_1.get_size());
}

/**********************/
/****** ___SET___ *****/
/**********************/


TEST(Test_s21_set, s21_set_test_set_1) {
    s21_set<int> s21_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};
    set<int> std_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};
    
    auto x = std_set_1.begin();
    for (auto &i : s21_set_1) {
        // cout << "s21_set: " << i << " == " << *x << endl;
        ASSERT_EQ(i, *x);
        x++;
    }

    auto y = s21_set_1.begin();
    for (auto &i : std_set_1) {
        // cout << "s21_set: " << *y << endl;
        ASSERT_EQ(i, *y);
        y++;
    }

    // s21_set<int> s21_set_1 {5, 3, 7, 2, 4, 6, 8};
    // s21_set_1.print(s21_set_1.get_element());
}

TEST(Test_s21_set, s21_set_test_iterator_1) {
    s21_set<int> s21_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};
    set<int> std_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};

    auto i = s21_set_1.end();
    for (auto y = std_set_1.end(); y != std_set_1.begin(); y--) {
        ASSERT_EQ(*i, *y);
        // cout << "s21_set: " << *y << " == " << *i << endl;
        i--;
    }
}

TEST(Test_s21_set, s21_set_test_operator) {
    s21_set<int> s21_set_1 {5, 3, 7, 2, 4, 6, 8};
    s21_set<int> s21_set_2 {10, 6, 12, 3, 13, 2, -4, 1, 18};
    s21_set_1 = s21_set_2;

    set<int> std_set_1 {5, 3, 7, 2, 4, 6, 8};
    set<int> std_set_2 {10, 6, 12, 3, 13, 2, -4, 1, 18};
    std_set_1 = std_set_2;


    auto x = std_set_1.begin();
    for (auto &i : s21_set_1) {
        // cout << "s21_set: " << i << endl;
        ASSERT_EQ(i, *x);
        x++;
    }
}

TEST(Test_s21_set, s21_set_test_constructor) {
    s21_set<int> s21_set_1 {5, 3, 7, 2, 4, 6, 8};
    s21_set<int> s21_set_2(s21_set_1);

    set<int> std_set_1 {5, 3, 7, 2, 4, 6, 8};
    set<int> std_set_2(std_set_1);
    

    auto x = s21_set_2.begin();
    for (auto &i : std_set_2) {
        // cout << "s21_set: " << *x << " " << i << endl;
        ASSERT_EQ(i, *x);
        x++;
    }
}

TEST(Test_s21_set, s21_set_test_swap) {
    s21_set<int> s21_set_1 {5, 3, 7, 2, 4, 6, 8};
    s21_set<int> s21_set_2 {10, 6, 12, 3, 13, 2, -4, 1, 18};
    s21_set_1.swap(s21_set_2);

    set<int> std_set_1 {5, 3, 7, 2, 4, 6, 8};
    set<int> std_set_2 {10, 6, 12, 3, 13, 2, -4, 1, 18};
    std_set_1.swap(std_set_2);


    auto x = std_set_1.begin();
    for (auto &i : s21_set_1) {
        // cout << "s21_set: " << i << endl;
        ASSERT_EQ(i, *x);
        x++;
    }
}

TEST(Test_s21_set, s21_set_test_merge) {
    s21_set<int> s21_set_1 {5, 3, 7, 2, 4, 6, 8}; // убрал 3
    s21_set<int> s21_set_2 {10, 6, 12, 13, 2, -4, 1, 18};
    s21_set_1.merge(s21_set_2);

    set<int> std_set_1 {5, 3, 7, 2, 4, 6, 8};  // убрал 3 
    set<int> std_set_2 {10, 6, 12, 13, 2, -4, 1, 18};
    std_set_1.merge(std_set_2);

    auto x = std_set_1.begin();
    for (auto &i : s21_set_1) {
        // cout << "s21_set: " << i << endl;
        ASSERT_EQ(i, *x);
        x++;
    }

    auto y = s21_set_1.begin();
    for (auto &i : std_set_1) {
        // cout << "s21_set: " << *y << " " << i << endl;
        ASSERT_EQ(i, *y);
        y++;
    }
}

TEST(Test_s21_set, s21_set_test_contains) {
    Key<int> test;
    test.data = 6;
    s21_set<int> s21_set_1 {5, 3, 7, 2, 4, 6, 8};
    s21_set_1.contains(test);
    ASSERT_TRUE(s21_set_1.contains(test));
}

TEST(Test_s21_set, s21_set_test_find_int) {
    s21_set<int> s21_set_1 {5, 3, 7, 2, 4, 6, 8};
    s21_set_1.find(6);

    set<int> std_set_1 {5, 3, 7, 2, 4, 6, 8};
    std_set_1.find(6);

    ASSERT_EQ(*(s21_set_1.find(6)), *(s21_set_1.find(6)));
}

TEST(Test_s21_set, s21_set_test_find_iterator) {
    Key<int> test;
    test.data = 4;
    s21_set<int> s21_set_1 {5, 3, 7, 2, 4, 6, 8};
    s21_set_1.find(test);

    ASSERT_EQ(4, *(s21_set_1.find(test)));
}

TEST(Test_s21_set, s21_set_test_erase_0) {
    
    s21_set<int> s21_set_1 {5, 3, 7, 2, 4, 6, 8};
    set<int> std_set_1 {5, 3, 7, 2, 4, 6, 8};
    auto x = s21_set_1.end();
    auto y = std_set_1.end();
    for (size_t i = 0; i < 4; i++) {
        x--; y--;
    }
    s21_set_1.erase(x);
    std_set_1.erase(y);

    auto it = std_set_1.begin();
    for (auto &i : s21_set_1) {
        // cout << "s21_set: " << i << " == " << *it << endl;
        ASSERT_EQ(i, *it);
        it++;
    }

    auto s21_it = s21_set_1.begin();
    for (auto &i : std_set_1) {
        // cout << "s21_set: " << *s21_it << endl;
        ASSERT_EQ(i, *s21_it);
        s21_it++;
    }
}

TEST(Test_s21_set, s21_set_test_erase_1) {
    
    s21_set<int> s21_set_1 {5, 3, 7, 2, 4, 6, 8};
    set<int> std_set_1 {5, 3, 7, 2, 4, 6, 8};
    auto x = s21_set_1.end();
    auto y = std_set_1.end();
    x--; y--;

    s21_set_1.erase(x);
    std_set_1.erase(y);

    auto it = std_set_1.begin();
    for (auto &i : s21_set_1) {
        // cout << "s21_set: " << i << " == " << *it << endl;
        ASSERT_EQ(i, *it);
        it++;
    }

    auto s21_it = s21_set_1.begin();
    for (auto &i : std_set_1) {
        // cout << "s21_set: " << *s21_it << endl;
        ASSERT_EQ(i, *s21_it);
        s21_it++;
    }
}

TEST(Test_s21_set, s21_set_test_erase_2) {
    s21_set<int> s21_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};
    set<int> std_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};
    auto x = s21_set_1.end();
    auto y = std_set_1.end();
    for (size_t i = 0; i < 6; i++) {
        x--; y--;
    }

    // std::cout << *x << std::endl;
    s21_set_1.erase(x);
    std_set_1.erase(y);

    auto it = std_set_1.begin();
    for (auto &i : s21_set_1) {
        // cout << "s21_set: " << i << " == " << *it << endl;
        ASSERT_EQ(i, *it);
        it++;
    }

    auto s21_it = s21_set_1.begin();
    for (auto &i : std_set_1) {
        // cout << "s21_set: " << *s21_it << endl;
        ASSERT_EQ(i, *s21_it);
        s21_it++;
    }
}

TEST(Test_s21_set, s21_set_test_erase_3) {
    s21_set<int> s21_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};
    set<int> std_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};
    auto x = s21_set_1.begin();
    auto y = std_set_1.begin();

    for (size_t i = 0; i < 8; i++) {
        x++; y++;
    }

    s21_set_1.erase(x);
    std_set_1.erase(y);

    auto it = std_set_1.begin();
    for (auto &i : s21_set_1) {
        // cout << "s21_set: " << i << " == " << *it << endl;
        ASSERT_EQ(i, *it);
        it++;
    }

    auto s21_it = s21_set_1.begin();
    for (auto &i : std_set_1) {
        // cout << "s21_set: " << *s21_it << endl;
        ASSERT_EQ(i, *s21_it);
        s21_it++;
    }
}

TEST(Test_s21_set, s21_set_test_erase_4) {
    s21_set<int> s21_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};
    set<int> std_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};
    auto x = s21_set_1.begin();
    auto y = std_set_1.begin();
    for (size_t i = 0; i < 3; i++) {
        x++; y++;
    }

    s21_set_1.erase(x);
    std_set_1.erase(y);

    auto it = std_set_1.begin();
    for (auto &i : s21_set_1) {
        // cout << "s21_set: " << i << " == " << *it << endl;
        ASSERT_EQ(i, *it);
        it++;
    }

    auto s21_it = s21_set_1.begin();
    for (auto &i : std_set_1) {
        // cout << "s21_set: " << *s21_it << endl;
        ASSERT_EQ(i, *s21_it);
        s21_it++;
    }
}

TEST(Test_s21_set, s21_set_test_max_size) {
    s21_set<int> s21_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};
    set<char> std_set_1 {10, 5, 15, 3, 7, 13, 17, 6, 8, 2, 4, 16, 18, 12, 14, -1, 1, -5, 11};

    ASSERT_EQ(s21_set_1.max_size(), s21_set_1.max_size());
}

/**********************/
/****** ___MAP___ *****/
/**********************/

TEST(Test_s21_map, s21_map_test_map_1) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    auto y = std_map_1.begin();
    for (auto i = s21_map_1.begin(); i != s21_map_1.end(); ++i, ++y) {
        // std::cout << (*i).first << " ( " << (*i).second << " )" << " == " << (*y).first << " ( " << (*y).second << " )" << std::endl;
        ASSERT_EQ((*i).first, (*y).first);
        ASSERT_EQ((*i).second, (*y).second);
    }

}

TEST(Test_s21_map, s21_map_test_map_2) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    auto y = std_map_1.end();
    for (auto i = s21_map_1.end(); i != s21_map_1.begin(); --i, --y) {
        if (i != s21_map_1.end()) {
            // std::cout << (*i).first << " ( " << (*i).second << " )" << " == " << (*y).first << " ( " << (*y).second << " )" << std::endl;
            ASSERT_EQ((*i).first, (*y).first);
            ASSERT_EQ((*i).second, (*y).second);
        }
    }
}

TEST(Test_s21_map, s21_map_test_constructor) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    s21_map<int, char> s21_map_2(s21_map_1);
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_2(std_map_1);

    auto y = std_map_2.begin();
    for (auto i = s21_map_2.begin(); i != s21_map_2.end(); ++i, ++y) {
        // std::cout << (*i).first << " ( " << (*i).second << " )" << " == " << (*y).first << " ( " << (*y).second << " )" << std::endl;
        ASSERT_EQ((*i).first, (*y).first);
        ASSERT_EQ((*i).second, (*y).second);
    }
}

TEST(Test_s21_map, s21_map_test_operator) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    s21_map<int, char> s21_map_2 {{10, '?'}, {5, '!'}, {15, '"'}, {3, ','}, {7, ':'}, {13, '-'}, {17, '='}};
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_2 {{10, '?'}, {5, '!'}, {15, '"'}, {3, ','}, {7, ':'}, {13, '-'}, {17, '='}};
    s21_map_1 = s21_map_2;
    std_map_1 = std_map_2;
    auto y = std_map_2.begin();
    for (auto i = s21_map_2.begin(); i != s21_map_2.end(); ++i, ++y) {
        // std::cout << (*i).first << " ( " << (*i).second << " )" << " == " << (*y).first << " ( " << (*y).second << " )" << std::endl;
        ASSERT_EQ((*i).first, (*y).first);
        ASSERT_EQ((*i).second, (*y).second);
    }
}

TEST(Test_s21_map, s21_map_test_swap) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    s21_map<int, char> s21_map_2  {{10, '?'}, {5, '!'}, {15, '"'}, {3, ','}, {7, ':'}, {13, '-'}, {17, '='}};
    
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_2 {{10, '?'}, {5, '!'}, {15, '"'}, {3, ','}, {7, ':'}, {13, '-'}, {17, '='}};

    s21_map_1.swap(s21_map_2);
    std_map_1.swap(std_map_2);

    auto y = std_map_1.begin();
    for (auto i = s21_map_1.begin(); i != s21_map_1.end(); ++i, ++y) {
        // std::cout << (*i).first << " ( " << (*i).second << " )" << " == " << (*y).first << " ( " << (*y).second << " )" << std::endl;
        ASSERT_EQ((*i).first, (*y).first);
        ASSERT_EQ((*i).second, (*y).second);
    }
}

TEST(Test_s21_map, s21_map_test_merge) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    s21_map<int, char> s21_map_2  {{10, '?'}, {5, '!'}, {15, '"'}, {3, ','}, {7, ':'}, {13, '-'}, {17, '='}};
    
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_2 {{10, '?'}, {5, '!'}, {15, '"'}, {3, ','}, {7, ':'}, {13, '-'}, {17, '='}};

    s21_map_1.merge(s21_map_2);
    std_map_1.merge(std_map_2);

    auto y = std_map_1.begin();
    for (auto i = s21_map_1.begin(); i != s21_map_1.end(); ++i, ++y) {
        // std::cout << (*i).first << " ( " << (*i).second << " )" << " == " << (*y).first << " ( " << (*y).second << " )" << std::endl;
        ASSERT_EQ((*i).first, (*y).first);
        ASSERT_EQ((*i).second, (*y).second);
    }
}


TEST(Test_s21_map, s21_map_test_operator_2) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    ASSERT_EQ(s21_map_1[5], std_map_1[5]);
}

TEST(Test_s21_map, s21_map_test_operator_3) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    Key_Map<int, char> test;
    test.data.first = 7;
    test.data.second = '*';

    ASSERT_EQ(s21_map_1[test], std_map_1[7]);
}

TEST(Test_s21_map, s21_map_test_insert_1) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};

    s21_map_1.insert(6, '~');
    s21_map_1.insert(9, '~');
    std_map_1.insert(std::make_pair(6, '~'));
    std_map_1.insert(std::make_pair(9, '~'));

    auto y = std_map_1.begin();
    for (auto i = s21_map_1.begin(); i != s21_map_1.end(); ++i, ++y) {
        // std::cout << (*i).first << " ( " << (*i).second << " )" << " == " << (*y).first << " ( " << (*y).second << " )" << std::endl;
        ASSERT_EQ((*i).first, (*y).first);
        ASSERT_EQ((*i).second, (*y).second);
    }
}

TEST(Test_s21_map, s21_map_test_insert_2) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};

    s21_map_1.insert_or_assign(6, '~');
    s21_map_1.insert_or_assign(9, '~');
    std_map_1[6] = '~';
    std_map_1[9] = '~';

    auto y = std_map_1.begin();
    for (auto i = s21_map_1.begin(); i != s21_map_1.end(); ++i, ++y) {
        // std::cout << (*i).first << " ( " << (*i).second << " )" << " == " << (*y).first << " ( " << (*y).second << " )" << std::endl;
        ASSERT_EQ((*i).first, (*y).first);
        ASSERT_EQ((*i).second, (*y).second);
    }
}

TEST(Test_s21_map, s21_map_test_contains) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};

    ASSERT_EQ(s21_map_1.contains(4), std_map_1.contains(4));
}

TEST(Test_s21_map, s21_map_test_erase_1) {
    s21_map<int, char> s21_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};
    map<int, char> std_map_1 {{5, '@'}, {3, '#'}, {7, '*'}, {2, '+'}, {4, '&'}, {6, ')'}, {8, '^'}};

    auto x = s21_map_1.end();
    auto j = std_map_1.end();
    for (size_t i = 0; i < 4; i++) {
        --x; --j;
    }
    s21_map_1.erase(x);
    std_map_1.erase(j);


    auto y = std_map_1.begin();
    for (auto i = s21_map_1.begin(); i != s21_map_1.end(); ++i, ++y) {
        // std::cout << (*i).first << " ( " << (*i).second << " )" << " == " << (*y).first << " ( " << (*y).second << " )" << std::endl;
        // ASSERT_EQ((*i).first, (*y).first);
        // ASSERT_EQ((*i).second, (*y).second);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
