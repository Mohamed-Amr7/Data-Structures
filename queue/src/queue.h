#ifndef QUEUE_H
#define QUEUE_H

#include <memory>

template <typename T>
class Queue {
private:
    class Node {
        T data;
        std::shared_ptr<Node> next;
        explicit Node(const T& val) : data(val), next(nullptr) {}
    };

    std::shared_ptr<Node> frontPtr;
    std::shared_ptr<Node> backPtr;

public:
    Queue();

    bool push(T value);
    T pop();
    T front() ;
    T back() ;
    bool isEmpty() const;
    void clear();
};

#endif // QUEUE_H
