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
void testInsert(){}
void testClear(){}
void testReverse(){}
void testContains(){}

int main() {
    testPushPopBack();
    testInsert();
    testClear();
    testReverse();
    testContains();
    return 0;
}
