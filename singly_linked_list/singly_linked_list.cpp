#include "singly_linked_list.h"
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
T Link<T>::value() {
    return data;
}

template <typename T>
shared_ptr<Link<T>>& Link<T>::next() {
    return next_ptr;
}

template <typename T>
List<T>::List() {
    begin = std::make_shared<Link<T>>();
    end = nullptr;
}

template <typename T>
bool List<T>::isEmpty() {
    return end == nullptr;
}

template <typename T>
bool List<T>::push_back(T new_elem) {
    auto new_link = make_shared<Link<T>>(new_elem);
    if (isEmpty()) {
        begin->next() = make_shared<Link<T>>(new_elem);
        end = begin->next();
    } else {
        end->next() = new_link;
        end = end->next();
    }
    return true;
}

template <typename T>
bool List<T>::push_front(T new_elem) {
    auto new_link = make_shared<Link<T>>(new_elem);
    if (isEmpty()) {
        begin->next() = new_link;
        end = begin->next();
    } else {
        new_link->next() = begin->next();
        begin->next() = new_link;
    }
    return true;
}

template <typename T>
T List<T>::pop_back() {
    if (isEmpty()) return T{};
    T value;

    // If there is only one element in the list, pop it and update end
    if (begin->next()->next() == nullptr) {
        value = begin->next()->value();
        begin->next() = end = nullptr;
    } else {
        // Traverse the list to find the second-to-last element
        auto current = begin->next();
        while (current->next() != end) {
            current = current->next();
        }
        // Pop the last element and update end
        value = current->next()->value();
        current->next() = nullptr;
        end = current;
    }

    return value;
}



template <typename T>
T List<T>::pop_front() {
    if(isEmpty()) return T{};
    T value = begin->next()->value();
    begin = begin->next();
    if (begin->next() == nullptr) end = nullptr;
    return value;
}

template <typename T>
void List<T>::display() {
    if (isEmpty()) {
        cout << "List is Empty!";
        return;
    }
    shared_ptr<Link<T>> f = begin;
    while (f->next() != nullptr) {
        cout << f->next()->value() << " ";
        f = f->next();
    }
    cout << endl;
}
