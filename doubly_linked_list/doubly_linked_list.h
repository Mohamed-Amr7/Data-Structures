#ifndef DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H

#include <memory>

using namespace std;

template <typename T>
class Link {
private:
    T data;
    shared_ptr<Link<T>> next_ptr;
    shared_ptr<Link<T>> prev_ptr;
public:
    T value();
    shared_ptr<Link<T>>& getNextPtr();
    shared_ptr<Link<T>>& getPrevPtr();
    void setNextPtr(shared_ptr<Link<T>>);
    void setPrevPtr(shared_ptr<Link<T>>);
    explicit Link<T>(T value = T{}) : data(value), next_ptr(nullptr), prev_ptr(nullptr) {}
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
    void displayReversed();
    void reverse();
    shared_ptr<Link<T>> find(int elem);
};



#include "doubly_linked_list.cpp"
#endif //DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
