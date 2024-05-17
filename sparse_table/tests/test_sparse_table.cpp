#include "sparse_table.h"
#include <iostream>
#include <cassert>

void testSparseTable() {
    std::vector<long> values = {1, 2, -3, 2, 4, -1, 5};

    // Test for minimum operation
    SparseTable<long> minSparseTable(values, [](long a, long b) { return std::min(a, b); });
    assert(minSparseTable.query(2, 3) == -3);
    assert(minSparseTable.query(0, 6) == -3);

    // Test for maximum operation
    SparseTable<long> maxSparseTable(values, [](long a, long b) { return std::max(a, b); });
    assert(maxSparseTable.query(2, 3) == 2);
    assert(maxSparseTable.query(0, 6) == 5);

    // Test for sum operation
    SparseTable<long> sumSparseTable(values, [](long a, long b) { return a + b; });
    assert(sumSparseTable.query(2, 3) == -1);
    assert(sumSparseTable.query(0, 6) == 10);

    // Test for product operation
    SparseTable<long> multSparseTable(values, [](long a, long b) { return a * b; });
    assert(multSparseTable.query(2, 3) == -6);
    assert(multSparseTable.query(0, 3) == -12);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testSparseTable();
    return 0;
}
