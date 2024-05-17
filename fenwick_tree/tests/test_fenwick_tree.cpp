#include "fenwick_tree.h"
#include <cassert>
#include <iostream>
#include <vector>

void testSumQuery() {
    std::vector<long> v = {0, 1, 2, -3, 2, 4, -1, 5}; // The initial 0 is for 1-based indexing
    FenwickTree<long> fenwickTree(v);

    assert(fenwickTree.sum(1, 7) == 10);
    assert(fenwickTree.sum(2, 4) == 1);
    assert(fenwickTree.sum(1, 3) == 0);
}

void testGetQuery() {
    std::vector<long> v = {0, 1, 2, -3, 2, 4, -1, 5};
    FenwickTree<long> fenwickTree(v);

    assert(fenwickTree.get(1) == 1);
    assert(fenwickTree.get(3) == -3);
    assert(fenwickTree.get(5) == 4);
}

void testAddValue() {
    std::vector<long> v = {0, 1, 2, -3, 2, 4, -1, 5};
    FenwickTree<long> fenwickTree(v);

    fenwickTree.add(3, 5); // Add 5 to index 3
    assert(fenwickTree.get(3) == 2);
    assert(fenwickTree.sum(1, 7) == 15);

    std::cout << "testAddValue passed." << std::endl;
}

void testSetValue() {
    std::vector<long> v = {0, 1, 2, -3, 2, 4, -1, 5};
    FenwickTree<long> fenwickTree(v);

    fenwickTree.set(4, 6); // Set index 4 to 6
    assert(fenwickTree.get(4) == 6);
    assert(fenwickTree.sum(1, 7) == 14);

    std::cout << "testSetValue passed." << std::endl;
}

void runAllTests(){
    testSumQuery();
    testGetQuery();
    testAddValue();
    testSetValue();
}

int main() {
    runAllTests();
    std::cout << "All tests passed." << std::endl;
    return 0;
}
