#ifndef SINGLY_LINKED_LIST_SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_SINGLY_LINKED_LIST_H

#include <memory>

using namespace std;

template <typename T>
class Link {
private:
    T data;
    shared_ptr<Link> next_ptr;
public:
    T value();
    shared_ptr<Link<T>>& next();
    explicit Link<T>(T value = NULL) : data(value), next_ptr(nullptr) {}
};


template <typename T>
class List {
private:
    shared_ptr<Link<T>> begin;
    shared_ptr<Link<T>> end;
public:
    List();
    T back();
    T front();
    bool isEmpty();
    bool push_back(T new_elem);
    bool push_front(T new_elem);
    T pop_back();
    T pop_front();
    T erase(T old_elem);
    void display();
    void reverse();
    shared_ptr<Link<T>> find(int elem);
};

#include "singly_linked_list.cpp"
#endif //SINGLY_LINKED_LIST_SINGLY_LINKED_LIST_H
