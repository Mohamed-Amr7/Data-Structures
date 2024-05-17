#include "fenwick_tree.h"

template<typename T>
FenwickTree<T>::FenwickTree(int sz) : N(sz + 1), tree(sz + 1, 0) {}

template<typename T>
FenwickTree<T>::FenwickTree(const std::vector<T>& values) : N(values.size()), tree(values.size()) {
    if (values.empty()) throw std::invalid_argument("Values array cannot be empty!");

    for (int i = 0; i < values.size(); ++i) {
        tree[i] = values[i];
    }

    for (int i = 1; i < N; ++i) {
        int parent = i + lsb(i);
        if (parent < N) tree[parent] += tree[i];
    }
}

template<typename T>
int FenwickTree<T>::lsb(int i) {
    return i & -i;
}

template<typename T>
T FenwickTree<T>::prefixSum(int i) const {
    T sum = 0;
    while (i != 0) {
        sum += tree[i];
        i &= ~lsb(i);
    }
    return sum;
}

template<typename T>
T FenwickTree<T>::sum(int left, int right) const {
    if (right < left) throw std::invalid_argument("Make sure right is bigger than left");
    return prefixSum(right) - prefixSum(left - 1);
}

template<typename T>
T FenwickTree<T>::get(int i) const {
    return sum(i, i);
}

template<typename T>
void FenwickTree<T>::add(int i, T v) {
    while (i < N) {
        tree[i] += v;
        i += lsb(i);
    }
}

template<typename T>
void FenwickTree<T>::set(int i, T v) {
    add(i, v - get(i));
}
