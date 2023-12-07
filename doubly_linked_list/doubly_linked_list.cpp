#include "doubly_linked_list.h"
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
shared_ptr<Link<T>> &Link<T>::getPrevPtr() {
    return prev_ptr;
}
template<typename T>
void Link<T>::setNextPtr( shared_ptr<Link<T>> nextPtr) {
    this->next_ptr = nextPtr;
}

template<typename T>
void Link<T>::setPrevPtr(shared_ptr<Link<T>> prevPtr) {
    this->prev_ptr = prevPtr;
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
        begin->setNextPtr(new_link);
        new_link->setPrevPtr(begin);
        end = new_link;
    } else {
        end->setNextPtr(new_link);
        new_link->setPrevPtr(end);
        end = new_link;
    }
    return true;
}

template<typename T>
bool List<T>::push_front(T new_elem) {
    auto new_link = make_shared<Link<T>>(new_elem);
    if (isEmpty()) {
        begin->setNextPtr(new_link);
        new_link->setPrevPtr(begin);
        end = new_link;
    } else {
        new_link->setNextPtr(begin->getNextPtr());
        begin->getNextPtr()->setPrevPtr(new_link);
        begin->setNextPtr(new_link);
        new_link->setPrevPtr(begin);
    }
    return true;
}

template<typename T>
T List<T>::pop_back() {
    if (isEmpty()) return T{};
    T value;
    // If there is only one element in the list, pop it and update end
    if (begin->getNextPtr()->getNextPtr() == nullptr) {
        value = begin->getNextPtr()->value();
        end = nullptr;
        begin->setNextPtr(end);
    }else {
        // Pop the last element and update end
        value = end->value();
        auto secondToLast = end->getPrevPtr();
        end = secondToLast;
        end->setNextPtr(nullptr);
    }
    return value;
}


template<typename T>
T List<T>::pop_front() {
    if (isEmpty()) return T{};

    T value = begin->getNextPtr()->value();
    begin = begin->getNextPtr();
    begin->setPrevPtr(nullptr);

    // If the list becomes empty after popping, update end to nullptr
    if (begin->getNextPtr() == nullptr) {
        end = nullptr;
    }
    return value;
}

template<typename T>
void List<T>::reverse() {
    if (isEmpty() or begin->getNextPtr()->getNextPtr() == nullptr) {
        return;
    }

    shared_ptr<Link<T>> prev = nullptr;
    auto current = begin->getNextPtr();
    end = begin->getNextPtr();
    auto next = current->getNextPtr();

    while (current != nullptr) {
        next = current->getNextPtr();
        current->setNextPtr(prev);
        current->setPrevPtr(next);
        prev = current;
        current = next;
    }
    prev->setPrevPtr(begin);
    begin->setNextPtr(prev);
    begin->setPrevPtr(nullptr);
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
void List<T>::displayReversed() {
    if (isEmpty()) {
        cout << "List is Empty!";
        return;
    }
    shared_ptr<Link<T>> t = end;
    while (t->getPrevPtr() != nullptr) {
        cout << t->value() << " ";
        t = t->getPrevPtr();
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
        current->setNextPtr(current->getNextPtr()->getNextPtr());
        if (current->getNextPtr() == nullptr) {
            end = current;
        }
        return erasedValue;
    }

    return T{};  // Element not found, return a default-constructed value
}
template<typename T>
shared_ptr<Link<T>> List<T>::find(int elem) {
    auto current = begin->getNextPtr();
    while (current != nullptr and current->value() != elem) {
        current = current->getNextPtr();
    }
    return current;
}
