#include "singly_linked_list.h"
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
T Link<T>::value() {
    return data;
}

template<typename T>
shared_ptr<Link<T>> &Link<T>::getNextPtr() {
    return next_ptr;
}
template<typename T>
void Link<T>::setNextPtr(shared_ptr<Link<T>>next) {
    next_ptr = next;
}

template<typename T>
List<T>::List() {
    begin = make_shared<Link<T>>();
    end = nullptr;
}

template<typename T>
T List<T>::back() {
    return end->value();
}

template<typename T>
T List<T>::front() {
    return begin->getNextPtr()->value();
}

template<typename T>
bool List<T>::isEmpty() {
    return end == nullptr;
}

template<typename T>
bool List<T>::push_back(T new_elem) {
    auto new_link = make_shared<Link<T>>(new_elem);
    if (isEmpty()) {
        begin->setNextPtr(make_shared<Link<T>>(new_elem));
        end = begin->getNextPtr();
    } else {
        end->setNextPtr(new_link);
        end = end->getNextPtr();
    }
    return true;
}

template<typename T>
bool List<T>::push_front(T new_elem) {
    auto new_link = make_shared<Link<T>>(new_elem);
    if (isEmpty()) {
        begin->setNextPtr(new_link);
        end = begin->getNextPtr();
    } else {
        new_link->setNextPtr(begin->getNextPtr());
        begin->setNextPtr(new_link);
    }
    return true;
}

template<typename T>
T List<T>::pop_back() {
    if (isEmpty()) throw runtime_error("List is Empty!");

    T value;
    // If there is only one element in the list, pop it and update end
    if (begin->getNextPtr()->getNextPtr() == nullptr) {
        value = begin->getNextPtr()->value();
        end = nullptr;
        begin->setNextPtr(nullptr);
    } else {
        // Traverse the list to find the second-to-last element
        auto current = begin->getNextPtr();
        while (current->getNextPtr() != end) {
            current = current->getNextPtr();
        }
        // Pop the last element and update end
        value = current->getNextPtr()->value();
        current->setNextPtr(nullptr);
        end = current;
    }

    return value;
}


template<typename T>
T List<T>::pop_front() {
    if (isEmpty()) throw runtime_error("List is Empty!");

    T value = begin->getNextPtr()->value();
    auto tmp = begin;
    begin = begin->getNextPtr();
    tmp = nullptr;

    // If the list becomes empty after popping, update end to nullptr
    if (begin->getNextPtr() == nullptr) {
        end = nullptr;
    }
    return value;
}

template<typename T>
void List<T>::display() {
    if (isEmpty()) {
        cout << "List is Empty!";
        return;
    }
    shared_ptr<Link<T>> f = begin;
    while (f->getNextPtr() != nullptr) {
        cout << f->getNextPtr()->value() << " ";
        f = f->getNextPtr();
    }
    cout << endl;
}

template<typename T>
T List<T>::erase(T elem) {
    if (isEmpty()) return T{};

    // Handle the case where the element to be erased is the first one
    if (begin->getNextPtr()->value() == elem) {
        return pop_front();
    }

    // Traverse the list to find the element to be erased
    auto current = begin->getNextPtr();
    while (current->getNextPtr() != nullptr and current->getNextPtr()->value() != elem) {
        current = current->getNextPtr();
    }

    // If the element is found, erase it and return the erased element
    if (current->getNextPtr() != nullptr) {
        T erasedValue = current->getNextPtr()->value();
        current->getNextPtr() = current->getNextPtr()->getNextPtr();
        if (current->getNextPtr() == nullptr) {
            end = current;
        }
        return erasedValue;
    }

    return T{};  // Element not found, return a default-constructed value
}

template<typename T>
void List<T>::reverse() {
    if (isEmpty() or begin->getNextPtr()->getNextPtr() == nullptr) {
        return;
    }

    shared_ptr<Link<T>> prev = nullptr;
    end = begin->getNextPtr();
    auto current = begin->getNextPtr();
    auto next = current->getNextPtr();

    while (current != nullptr) {
        next = current->getNextPtr();
        current->setNextPtr(prev);
        prev = current;
        current = next;
    }

    begin->setNextPtr(prev);
}

template<typename T>
shared_ptr<Link<T>> List<T>::find(int elem) {
    auto current = begin->getNextPtr();
    while (current != nullptr and current->value() != elem) {
        current = current->getNextPtr();
    }
    return current;
}
