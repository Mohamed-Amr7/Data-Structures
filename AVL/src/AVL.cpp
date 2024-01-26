#include <stdexcept>
#include <iostream>
#include <queue>
#include "AVL.h"

using namespace std;

template<class T>
AVL<T>::Node::Node(const T& value) : data(value), height(1), balance_factor(0), left(nullptr), right(nullptr) {}

template<class T>
AVL<T>::AVL() {
    root = nullptr;
    node_count = 0;
}

template<class T>
int AVL<T>::size() {
    return node_count;
}

template<class T>
bool AVL<T>::isEmpty() {
    return size() == 0;
}

template<class T>
T AVL<T>::top() {
    if (isEmpty()) throw runtime_error("AVL tree is empty!");
    return root->data;
}

template<class T>
bool AVL<T>::contains(shared_ptr<typename AVL<T>::Node> node, T value) {
    // If the current node is null, then the value is not in the tree
    if (node == nullptr) {
        return false;
    }
    if (!(value < node->data) and !(node->data < value)) {
        return true;
    } else if (value < node->data) {
        return contains(node->left, value);
    } else {
        return contains(node->right, value);
    }
}

template<class T>
bool AVL<T>::contains(T value) {
    return contains(root, value);
}
