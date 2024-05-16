#ifndef SEG_TREE_H
#define SEG_TREE_H

#include <vector>
#include <algorithm>

template<typename T>
class SegTree {
private:
    int size;
    std::vector<T> tree;
    T IDENTITY;
    T (*combine)(T a, T b);

//    void build(const std::vector<T>& v, int node, int start, int end);
    void build(const std::vector<T> &v, int n);
    void update(int point, T val, int node, int start, int end);
    T query(int ql, int qr, int node, int start, int end);

public:
    SegTree(int n, const std::vector<T>& v, T id, T (*comb)(T a, T b));
    T query(int ql, int qr);
    void update(int point, T val);

};

#include "segment_tree.cpp"
#endif // SEG_TREE_H
