#ifndef DISJOINT_SET_UNION_H
#define DISJOINT_SET_UNION_H

#include <vector>
#include <stdexcept>

template<typename T>
class DisjointSetUnion {
private:
    int size;
    std::vector<int> sz;
    std::vector<T> id;
    int numComponents;

public:
    DisjointSetUnion(int size);
    int find(int p);
    bool connected(int p, int q);
    int componentSize(int p);
    int getSize();
    int components();
    void unify(int p, int q);
};

#include "disjoint_set_union.cpp"

#endif // DISJOINT_SET_UNION_H
