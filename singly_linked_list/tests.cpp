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
    list.push_back(42);
    list.push_back(24);
    
    assert(list.pop_back() == 24);
    assert(list.pop_back() == 42);
}

void testPopFront() {
    List<int> list;
    list.push_back(42);
    list.push_back(24);

    assert(list.pop_front() == 42);
    assert(list.pop_front() == 24);
}

void testErase() {
    List<int> list;
    assert(list.erase(42) == int{});

    list.push_back(42);
    list.push_back(24);
    list.push_back(36);

    assert(list.erase(24) == 24);
    assert(list.pop_front() == 42);
    assert(list.pop_front() == 36);

    list.push_back(42);
    list.push_back(24);
    list.push_back(36);

    assert(list.erase(24) == 24);
    assert(list.erase(42) == 42);
    assert(list.erase(36) == 36);
    assert(list.isEmpty());

}
void testReverse() {
    List<int> list;
    list.push_back(42);
    list.push_back(24);
    list.push_back(36);

    list.reverse();

    assert(list.pop_front() == 36);
    assert(list.pop_front() == 24);
    assert(list.pop_front() == 42);
}
void testFind() {
    List<int> list;
    assert(list.find(42) == nullptr);

    list.push_back(42);
    list.push_back(24);
    list.push_back(36);

    assert(list.find(24)->value() == 24);
    assert(list.find(36)->value() == 36);
    assert(list.find(42)->value() == 42);
    assert(list.find(50) == nullptr);
}

void runAllTests(){
    testIsEmpty();
    testPopBack();
    testPopFront();
    testErase();
    testReverse();
    testFind();
    cout << "All tests passed!" << endl;
}

