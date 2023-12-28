#include "Queue.h"


template<typename T>
Queue<T>::Node::Node(const T& val) : data(val), next(nullptr) {}

template<typename T>
Queue<T>::Node::Node() : data(T{}), next(nullptr) {}

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

template <typename T>
bool Queue<T>::push(T val) {
    auto new_node = std::make_shared<Node>(val);
    if (isEmpty()) {
        frontPtr = new_node;
        backPtr = new_node;
    } else {
        backPtr->next = new_node;
        backPtr = new_node;
    }
    _size++;
    return true;
}

template <typename T>
T Queue<T>::pop() {
    ensureNotEmpty();
    int ret_val = frontPtr->data;
    frontPtr = frontPtr->next;
    if (!frontPtr) {
        backPtr = nullptr;
    }
    _size--;
    return ret_val;
}

