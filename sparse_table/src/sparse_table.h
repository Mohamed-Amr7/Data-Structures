#ifndef SPARSE_TABLE_H
#define SPARSE_TABLE_H

#include <vector>
#include <cmath>
#include <functional>
#include <stdexcept>

template<typename T>
class SparseTable {
public:
    // Constructor that takes the input array and the operation function
    SparseTable(const std::vector<T> &values, std::function<T(T, T)> op);

    // Query the range [l, r] for the specified operation
    T query(int l, int r) const;

private:
    int n;      // Number of elements in the input array
    int P;      // Maximum power of 2 needed
    std::vector<int> log2;      // Fast log base 2 lookup table
    std::vector<std::vector<T>> dp;     // Sparse table values
    std::function<T(T, T)> operation;   // Operation function

    // Initialize the sparse table with the given values
    void build(const std::vector<T> &values);
};

#include "sparse_table.cpp"

#endif // SPARSE_TABLE_H
