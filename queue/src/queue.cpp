#include "Queue.h"

template <typename T>
Queue<T>::Queue() : frontPtr(nullptr), backPtr(nullptr) {}

template <typename T>
T Queue<T>::front() {
    ensureNotEmpty();
    return frontPtr->data;
}

template <typename T>
T Queue<T>::back() {
    ensureNotEmpty();
    return backPtr->data;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return frontPtr == nullptr;
}

template <typename T>
void Queue<T>::ensureNotEmpty() {
    if (isEmpty()) {
        throw std::invalid_argument("Queue is empty.");
    }
}
template <typename T>
int Queue<T>::size() {
    return _size;
}

template <typename T>
void Queue<T>::clear() {
    frontPtr = nullptr;
    backPtr = nullptr;
    _size = 0;
}