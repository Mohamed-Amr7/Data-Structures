#include "dynamic_array.h"
template <typename T>

DynamicArray<T>::DynamicArray() : _size(0), capacity(16) {
    array = std::make_shared<T[]>(capacity);
}

template <typename T>
bool DynamicArray<T>::pushBack(const T value) {
    if (_size == capacity) {
        enlarge();
    }
    array[_size++] = value;
    return true;
}

template <typename T>
T DynamicArray<T>::popBack() {
    if (_size > 0) {
        T value = array[_size--];

        if (_size < capacity / 4) {
            shrink();
        }
        return value;
    }
    return {};
}

template <typename T>
T DynamicArray<T>::back() {
    return array[_size - 1];
}

template <typename T>
T DynamicArray<T>::front() {
    return array[0];
}

template <typename T>
void DynamicArray<T>::resize(int newCapacity) {
    if (newCapacity > capacity) {
        // Enlarge the array
        std::shared_ptr<T[]> newArray = std::make_shared<T[]>(newCapacity);
        for (int i = 0; i < _size; i++) {
            newArray[i] = array[i];
        }
        array = newArray;
        capacity = newCapacity;
    } else if (newCapacity < capacity) {
        // Shrink the array
        if (_size > newCapacity) {
            _size = newCapacity;
        }
        std::shared_ptr<T[]> new_array = std::make_shared<T[]>(newCapacity);
        for (int i = 0; i < _size; i++) {
            new_array[i] = array[i];
        }
        array = new_array;
        capacity = newCapacity;
    }
}

template <typename T>
void DynamicArray<T>::shrink() {
    int newCapacity = std::max(2, capacity / 2);
    resize(newCapacity);
}

template <typename T>
void DynamicArray<T>::enlarge() {
    int newCapacity = capacity * 2;
    resize(newCapacity);
}