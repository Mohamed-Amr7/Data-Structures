#include "heap.h"
#include <iostream>
#include <cassert>

void testMinHeap() {
    Heap<int> minHeap;
    minHeap.add(3);
    minHeap.add(1);
    minHeap.add(6);
    minHeap.add(5);
    minHeap.add(2);
    minHeap.add(4);

    assert(minHeap.size() == 6);
    assert(minHeap.peek() == 1);
    assert(minHeap.poll() == 1);
    assert(minHeap.peek() == 2);
    assert(minHeap.size() == 5);

    minHeap.remove(3);
    assert(minHeap.size() == 4);
    assert(!minHeap.contains(3));
    std::vector<int> v = minHeap.toVector();
    for (const auto &elem: v) std::cout << elem << " ";
    std::cout << std::endl;
}

void testMaxHeap() {
    Heap<int> maxHeap([](int a, int b) { return a > b; });
    maxHeap.add(3);
    maxHeap.add(1);
    maxHeap.add(6);
    maxHeap.add(5);
    maxHeap.add(2);
    maxHeap.add(4);

    assert(maxHeap.size() == 6);
    assert(maxHeap.peek() == 6);
    assert(maxHeap.poll() == 6);
    assert(maxHeap.peek() == 5);
    assert(maxHeap.size() == 5);

    maxHeap.remove(3);
    assert(maxHeap.size() == 4);
    assert(!maxHeap.contains(3));
    std::vector<int> v = maxHeap.toVector();
    for (const auto &elem: v) std::cout << elem << " ";
    std::cout << std::endl;
}

int main() {
    testMinHeap();
    testMaxHeap();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
