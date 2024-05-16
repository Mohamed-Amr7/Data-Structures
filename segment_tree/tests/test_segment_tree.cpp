#include "segment_tree.h"
#include <cassert>
#include <iostream>

void testQuery() {
    std::vector<int> v = {1, 3, 2, 7, 9, 11};
    SegTree<int> testTree(v.size(), v, INT_MAX, [](int a, int b) { return std::min(a, b); });
    assert(testTree.query(0, 3) == 1);
    assert(testTree.query(1, 4) == 2);
    assert(testTree.query(2, 5) == 2);

    SegTree<int> testTree2(v.size(), v, 0, [](int a, int b) { return a + b; });
    assert(testTree2.query(0, 3) == 13);
    assert(testTree2.query(1, 4) == 21);
    assert(testTree2.query(2, 5) == 29);
}

void testUpdate() {
    std::vector<int> v = {1, 3, 2, 7, 9, 11};
    SegTree<int> testTree(v.size(), v, INT_MAX, [](int a, int b) { return std::min(a, b); });
    testTree.update(2, 5); // Update index 2 to value 5
    assert(testTree.query(1, 4) == 3); // Query range [1, 4] after update

    SegTree<int> testTree2(v.size(), v, 0, [](int a, int b) { return a + b; });
    testTree2.update(2, 5); // Update index 2 by adding 5
    assert(testTree2.query(1, 4) == 24); // Query range [1, 4] after update
}

int main(){
    testQuery();
    testUpdate();
}