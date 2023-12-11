#include "binary_search_tree.h"
#include <cassert>

void testIsEmpty() {
    BST<int> testTree;
    assert(testTree.isEmpty());

    testTree.insert(42);
    assert(!testTree.isEmpty());
}

void testTop() {
    BST<int> testTree;

    testTree.insert(42);
    assert(testTree.top() == 42);

    testTree.insert(23);
    assert(testTree.top() == 42);
}

void testSize() {
    BST<int> testTree;
    assert(testTree.size() == 0);

    testTree.insert(42);
    assert(testTree.size() == 1);

    testTree.insert(23);
    assert(testTree.size() == 2);
}

void testInsert() {
    BST<int> testTree;
    assert(testTree.insert(42));
    assert(!testTree.insert(42));

    testTree.insert(23);
    testTree.insert(56);
    assert(testTree.insert(12));
}
void testHeight(){}
void testRemove(){}

void testContains() {
    BST<int> testTree;
    assert(!testTree.contains(42));

    testTree.insert(42);
    assert(testTree.contains(42));

    testTree.insert(23);
    testTree.insert(56);
    assert(testTree.contains(23));
    assert(!testTree.contains(99));
}

void runAllTests() {
    testIsEmpty();
    testTop();
    testSize();
    testInsert();
    testContains();
    testHeight();
    testRemove();
    printf("All Tests Passed!");
}
