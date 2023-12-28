#include "stack.h"
#include <cassert>

void testPush() {
    Stack<int> stack;
    assert(stack.isEmpty());
    stack.push(10);
    assert(!stack.isEmpty());
    assert(stack.top() == 10);
    stack.push(3);
    assert(stack.top() == 3);
}

void testPop() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    assert(stack.size() == 3);
    assert(stack.pop() == 30);
    assert(stack.size() == 2);
    stack.push(5);
    assert(stack.size() == 3);
    assert(stack.pop() == 5);
    assert(stack.pop() == 20);
    assert(stack.size() == 1);
}
void testPopEmptyStack(){
    Stack<int>stack;
    bool exceptionThrown = false;
    try {
        stack.pop();
    } catch (std::invalid_argument& e) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

};
void testIsEmpty() {
    Stack<int> stack;
    assert(stack.isEmpty());
    stack.push(10);
    assert(!stack.isEmpty());
}

void testClear() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    assert(stack.size() == 2);
    stack.clear();
    assert(stack.isEmpty());
    assert(stack.size() == 0);
}

int main() {
    testPush();
    testPop();
    testPopEmptyStack();
    testIsEmpty();
    testClear();
    return 0;
}