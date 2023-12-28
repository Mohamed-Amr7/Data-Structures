#ifndef STACK_H
#define STACK_H

#include <memory>

template <typename T>
class Stack {
private:
    class Node {
    public:
        T data;
        std::shared_ptr<Node> next;
        Node();
        explicit Node(const T& val);
    };

    std::shared_ptr<Node> topPtr;
    void ensureNotEmpty();
    int _size = 0;

public:
    Stack();

    bool push(T value);
    T pop();
    T top() ;
    bool isEmpty() ;
    void clear();
    int size();
};

#include "stack.cpp"
#endif // STACK_H
