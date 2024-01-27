#include "AVL.h"
#include <cassert>

void testIsEmpty() {
    AVL<int> avlTree;
    assert(avlTree.isEmpty());

    avlTree.insert(42);
    assert(!avlTree.isEmpty());
}

void testTop() {
    AVL<int> avlTree;

    avlTree.insert(42);
    assert(avlTree.top() == 42);

    avlTree.insert(23);
    assert(avlTree.top() == 42);
}

void testSize() {
    AVL<int> avlTree;
    assert(avlTree.size() == 0);

    avlTree.insert(42);
    assert(avlTree.size() == 1);

    avlTree.insert(23);
    assert(avlTree.size() == 2);
}

void testInsert() {
    AVL<int> avlTree;
    assert(avlTree.insert(42));
    assert(!avlTree.insert(42));

    avlTree.insert(23);
    avlTree.insert(56);
    assert(avlTree.insert(12));
}

void testContains() {
    AVL<int> avlTree;
    assert(!avlTree.contains(42));

    avlTree.insert(42);
    assert(avlTree.contains(42));

    avlTree.insert(23);
    avlTree.insert(56);
    assert(avlTree.contains(23));
    assert(!avlTree.contains(99));
}

void testHeight(){
    AVL<int> avlTree;

    avlTree.insert(10);
    avlTree.insert(5);
    avlTree.insert(15);
    avlTree.insert(3);
    avlTree.insert(8);

    assert(avlTree.height() == 2);
    avlTree.insert(20);
    avlTree.insert(25);
    avlTree.insert(30);
    assert(avlTree.height() == 3);
}

void testClear(){
    AVL<int> avlTree;
    avlTree.insert(5);
    avlTree.insert(3);
    avlTree.insert(4);
    avlTree.insert(2);
    avlTree.insert(7);
    avlTree.insert(6);
    avlTree.insert(8);
    avlTree.clear();
    assert(avlTree.isEmpty());
}

void testRemove() {
    AVL<int> avlTree;
    assert(!avlTree.remove(99));
    avlTree.insert(42);
    avlTree.insert(23);
    avlTree.insert(56);
    assert(!avlTree.remove(99));
    assert(avlTree.remove(42));
    assert(avlTree.remove(56));
    assert(avlTree.remove(23));

    avlTree.insert(42);
    avlTree.insert(23);
    avlTree.insert(56);
    avlTree.insert(12);
    avlTree.insert(37);
    assert(avlTree.remove(23));
    assert(!avlTree.contains(23));
    assert(avlTree.contains(42));
    assert(avlTree.contains(56));
    assert(avlTree.contains(12));
    assert(avlTree.contains(37));
    assert(avlTree.remove(42));
    assert(!avlTree.contains(42));
    assert(avlTree.remove(12));
    assert(!avlTree.contains(12));
    assert(avlTree.contains(56));
    assert(avlTree.contains(37));
}

void runAllTests() {
    testIsEmpty();
    testTop();
    testSize();
    testInsert();
    testContains();
    testHeight();
    testClear();
    testRemove();
}

int main(){
    runAllTests();
}
