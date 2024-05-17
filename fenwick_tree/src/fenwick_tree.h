#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <vector>
#include <stdexcept>

template<typename T>
class FenwickTree {
public:
    // Constructors
    explicit FenwickTree(int sz);
    explicit FenwickTree(const std::vector<T>& values);

    // Public methods
    T sum(int left, int right) const;
    T get(int i) const;
    void add(int i, T v);
    void set(int i, T v);

private:
    int N;
    std::vector<T> tree;

    // Private methods
    static int lsb(int i);
    T prefixSum(int i) const;
};

#include "fenwick_tree.cpp"

#endif // FENWICK_TREE_H
