#include "singly_linked_list.h"
#include <iostream>
#include <cassert>

void testIsEmpty() {
    List<int> list;
    assert(list.isEmpty());

    list.push_back(42);
    assert(!list.isEmpty());
}

void testPopBack() {
    List<int> list;
    assert(list.pop_back() == int{});

    list.push_back(42);
    list.push_back(24);
    assert(list.pop_back() == 24);
    assert(list.pop_back() == 42);
}

void testPopFront() {
    List<int> list;
    assert(list.pop_front() == int{});

    list.push_back(42);
    list.push_back(24);
    assert(list.pop_front() == 42);
    assert(list.pop_front() == 24);
}

void test(){
    testIsEmpty();
    testPopBack();
    testPopFront();
    std::cout << "All tests passed!" << std::endl;
}

