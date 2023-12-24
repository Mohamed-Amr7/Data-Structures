#include "dynamic_array.h"
#include <cassert>

void testPushPopBack() {
    DynamicArray<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);

    assert(arr.back() == 3);
    assert(arr.front() == 1);

    arr.popBack();
    assert(arr.back() == 2);
    assert(arr.front() == 1);
}
void testReverse(){}
void testInsert() {}

void testClear() {
    DynamicArray<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);

    arr.clear();
    assert(arr.isEmpty());
}

void testContains() {
    DynamicArray<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);

    assert(arr.contains(2));
    assert(!arr.contains(4));
}

void testResize() {
    DynamicArray<int> arr;

    assert(arr.size() == 0);
    assert(arr.isEmpty());

    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);

    assert(arr.size() == 3);
    assert(!arr.isEmpty());
    arr.resize(2);
    assert(arr.size() == 2);
    assert(!arr.isEmpty());

    arr.resize(5);


    assert(arr.size() == 2);
    assert(!arr.isEmpty());

    arr.clear();
    assert(arr.isEmpty());
    arr.pushBack(5);
    assert(arr.size() == 1);
}

int main() {
    testPushPopBack();
    testInsert();
    testClear();
    testReverse();
    testContains();
    testResize();
    return 0;
}
