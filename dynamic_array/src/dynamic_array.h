#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <memory>

template <typename T>
class DynamicArray {
private:
    std::shared_ptr<T[]> array;
    int capacity;
    void shrink();
    int _size;
    void enlarge();

public:
    DynamicArray();

    int size();
    T front();
    T back();
    T popBack();
    bool pushBack(const T value);
    bool insert(int index, const T value);
    bool isEmpty() const;
    bool contains(const T value) const;
    void reverse();
    void clear();
    void resize(int newCapacity);
};

#include "dynamic_array.cpp"
#endif //DYNAMICARRAY_H