#include "disjoint_set_union.h"

template<typename T>
DisjointSetUnion<T>::DisjointSetUnion(int size) : size(size), numComponents(size) {
    if (size <= 0) throw std::invalid_argument("Size can't be less than or equal 0");

    sz.resize(size);
    id.resize(size);

    for (int i = 0; i < size; ++i) {
        id[i] = i;
        sz[i] = 1;
    }
}

template<typename T>
int DisjointSetUnion<T>::find(int p) {
    int root = p;
    while (root != id[root]) root = id[root];

    while (p != root) {
        int next = id[p];
        id[p] = root;
        p = next;
    }

    return root;
}

template<typename T>
bool DisjointSetUnion<T>::connected(int p, int q) {
    return find(p) == find(q);
}

template<typename T>
int DisjointSetUnion<T>::componentSize(int p) {
    return sz[find(p)];
}

template<typename T>
int DisjointSetUnion<T>::getSize() {
    return size;
}

template<typename T>
int DisjointSetUnion<T>::components() {
    return numComponents;
}

template<typename T>
void DisjointSetUnion<T>::unify(int p, int q) {
    if (connected(p, q)) return;

    int root1 = find(p);
    int root2 = find(q);

    if (sz[root1] < sz[root2]) {
        sz[root2] += sz[root1];
        id[root1] = root2;
        sz[root1] = 0;
    } else {
        sz[root1] += sz[root2];
        id[root2] = root1;
        sz[root2] = 0;
    }

    numComponents--;
}
