#include "queue.h"
#include <assert.h>

void testPush() {
    Queue<int> queue;
    assert(queue.isEmpty());
    queue.push(10);
    assert(!queue.isEmpty());
    assert(queue.front() == 10);
    assert(queue.back() == 10);
    queue.push(3);
    assert(queue.front() == 10);
    assert(queue.back() == 3);
}

void testPop() {
    Queue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    assert(queue.size() == 3);
    assert(queue.pop() == 10);
    assert(queue.size() == 2);
    queue.push(5);
    assert(queue.size() == 3);
    assert(queue.pop() == 20);
    assert(queue.pop() == 30);
    assert(queue.size() == 1);
}
void testPopEmptyQueue(){
    Queue<int>queue;
    bool exceptionThrown = false;
    try {
        queue.pop();
    } catch (std::invalid_argument& e) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

};
void testIsEmpty() {
    Queue<int> queue;
    assert(queue.isEmpty());
    queue.push(10);
    assert(!queue.isEmpty());
}

void testClear() {
    Queue<int> queue;
    queue.push(10);
    queue.push(20);
    assert(queue.size() == 2);
    queue.clear();
    assert(queue.isEmpty());
    assert(queue.size() == 0);
}

int main() {
    testPush();
    testPop();
    testPopEmptyQueue();
    testIsEmpty();
    testClear();
    return 0;
}