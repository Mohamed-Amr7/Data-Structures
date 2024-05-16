#include "disjoint_set_union.h"
#include <cassert>

void testInitialization() {
    DisjointSetUnion<int> dsu(10);
    assert(dsu.getSize() == 10);
    assert(dsu.components() == 10);
}

void testUnionAndFind() {
    DisjointSetUnion<int> dsu(10);
    dsu.unify(0, 1);
    dsu.unify(1, 2);
    dsu.unify(3, 4);
    assert(dsu.connected(0, 2));
    assert(!dsu.connected(0, 3));
    assert(dsu.connected(3, 4));
    assert(!dsu.connected(1, 3));
}

void testComponentSize() {
    DisjointSetUnion<int> dsu(10);
    dsu.unify(0, 1);
    dsu.unify(1, 2);
    dsu.unify(3, 4);
    assert(dsu.componentSize(0) == 3);
    assert(dsu.componentSize(3) == 2);
}

void testComponents() {
    DisjointSetUnion<int> dsu(10);
    assert(dsu.components() == 10);
    dsu.unify(0, 1);
    dsu.unify(1, 2);
    assert(dsu.components() == 8);
    dsu.unify(3, 4);
    assert(dsu.components() == 7);
}

void runAllTests(){
    testInitialization();
    testUnionAndFind();
    testComponentSize();
    testComponents();
}

int main() {
    runAllTests();
    return 0;
}
