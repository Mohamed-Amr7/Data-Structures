#ifndef QUEUE_H
#define QUEUE_H

#include <memory>

template <typename T>
class Queue {
private:
    class Node {
        T data;
        std::shared_ptr<Node> next;
        explicit Node(const T& val);
    };

    std::shared_ptr<Node> frontPtr;
    std::shared_ptr<Node> backPtr;
    void ensureNotEmpty();
    int _size = 0;

public:
    Queue();

    bool push(T value);
    T pop();
    T front() ;
    T back() ;
    bool isEmpty() ;
    void clear();
    int size();
};

#endif // QUEUE_H
