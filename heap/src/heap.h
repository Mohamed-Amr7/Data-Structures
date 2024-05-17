#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <stdexcept>
#include <functional>

template<typename T>
class Heap {
private:
    std::vector<T> heap;
    std::function<bool(T, T)> comparator;

    void swim(int k);
    void sink(int k);
    void swap(int i, int j);
    bool compare(int i, int j);

public:
    explicit Heap(std::function<bool(T, T)> comp = std::less<T>());
    explicit Heap(const std::vector<T>& elems, std::function<bool(T, T)> comp = std::less<T>());

    bool isEmpty() const;
    void clear();
    int size() const;
    const T& peek() const;
    T poll();
    bool contains(const T& elem) const;
    void add(const T& elem);
    bool remove(const T& elem);

    std::vector<T> toVector() const;
};

#include "heap.cpp"

#endif // HEAP_H
