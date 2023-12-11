#include <stdexcept>
#include "binary_search_tree.h"

using namespace std;

template<class T>
BST<T>::Node::Node(T value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

template<class T>
T BST<T>::Node::getData() {
    return data;
}

template<class T>
shared_ptr<typename BST<T>::Node> BST<T>::Node::getLeft() {
    return left;
}

template<class T>
shared_ptr<typename BST<T>::Node> BST<T>::Node::getRight() {
    return right;
}

template<class T>
void BST<T>::Node::setLeft(shared_ptr<Node> left_ptr) {
    left = left_ptr;
}

template<class T>
void BST<T>::Node::setRight(shared_ptr<Node> right_ptr) {
    right = right_ptr;
}

template<class T>
BST<T>::BST() {
    root = nullptr;
    node_count = 0;
}

template<class T>
int BST<T>::size() {
    return node_count;
}

template<class T>
bool BST<T>::isEmpty() {
    return size() == 0;
}

template<class T>
T BST<T>::top() {
    if(isEmpty()) throw runtime_error("BST is empty!");
    return root->getData();
}

template<class T>
bool BST<T>::contains(shared_ptr<typename BST<T>::Node> node, T value) {
    // If the current node is null, then the value is not in the tree
    if (node == nullptr) {
        return false;
    }
    if (!(value < node->getData()) and !(node->getData() < value)) {
        return true;
    }
    else if (value < node->getData()) {
        return contains(node->getLeft(),value);
    } else{
        return contains(node->getRight(), node->getData());
    }
}

template<class T>
bool BST<T>::contains(T value) {
    return contains(root, value);
}

template<class T>
shared_ptr<typename BST<T>::Node> BST<T>::insert(shared_ptr<Node> node, T new_value) {
    if (node == nullptr) {
        // If the current node is null, create a new node with the given value.
        return make_shared<Node>(new_value);
    }

    if (new_value < node->getData()) {
        // Recursively insert into the left subtree and update the left pointer.
        node->setLeft(insert(node->getLeft(), new_value));
    } else {
        // Recursively insert into the right subtree and update the right pointer.
        node->setRight(insert(node->getRight(), new_value));
    }

    return node;
}

template<class T>
bool BST<T>::insert(T new_value) {
    if (contains(new_value)) {
        return false;
    } else {
        root = insert(root,new_value);
        ++node_count;
        return true;
    }
}

template<class T>
shared_ptr<typename BST<T>::Node> BST<T>::find_min(shared_ptr<Node> node) {
    // Find the leftmost node of a subtree
    while (node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}

template<class T>
shared_ptr<typename BST<T>::Node> BST<T>::find_max(shared_ptr<Node> node) {
    // Find the rightmost node of a subtree
    while (node->getRight() != nullptr) {
        node = node->getRight();
    }
    return node;
}
