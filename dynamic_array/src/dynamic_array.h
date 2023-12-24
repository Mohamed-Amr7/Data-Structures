#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <memory>

template <typename T>
class DynamicArray {
public:
    DynamicArray();

    void pushBack(const T& value);
    void popBack();
    T& back();
    T& front();
    void insert(int index, const T& value);
    void clear();
    bool isEmpty() const;
    void reverse();
    int find(const T& value) const;

private:
    std::shared_ptr<T[]> array;
    int size;
    int capacity;

    void resize();
};

#endif //DYNAMICARRAY_H