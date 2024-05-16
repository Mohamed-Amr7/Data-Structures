#include "segment_tree.h"

template<typename T>
SegTree<T>::SegTree(int n, const std::vector<T>& v, T id, T (*comb)(T a, T b))
        : IDENTITY(id), combine(comb) {
    if (__builtin_popcount(n) != 1) {
        size = 1 << (std::__lg(n) + 1);
    } else {
        size = n;
    }
    tree.resize(size * 2);
    build(v, n);
}

template<typename T>
void SegTree<T>::build(const std::vector<T>& v, int n) {
    for (int i = 0; i < n; ++i) tree[i + size] = v[i]; // leaf nodes
    for (int i = n; i < size; ++i) tree[i + size] = IDENTITY;
    for (int i = size - 1; i; --i) tree[i] = combine(tree[i * 2], tree[(i * 2) + 1]); // build up to the roots
}

template<typename T>
void SegTree<T>::update(int point, T val, int node, int start, int end) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (point <= mid) {
            update(point, val, 2 * node, start, mid);
        } else {
            update(point, val, 2 * node + 1, mid + 1, end);
        }
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}

template<typename T>
T SegTree<T>::query(int ql, int qr, int node, int start, int end) {
    if (ql <= start && qr >= end) {
        return tree[node];
    }
    if (qr < start || ql > end) {
        return IDENTITY;
    }
    int mid = (start + end) / 2;
    return combine(query(ql, qr, 2 * node, start, mid),
                   query(ql, qr, 2 * node + 1, mid + 1, end));
}

template<typename T>
T SegTree<T>::query(int ql, int qr) {
    return query(ql, qr, 1, 0, size - 1);
}

template<typename T>
void SegTree<T>::update(int point, T val) {
    update(point, val, 1, 0, size - 1);
}