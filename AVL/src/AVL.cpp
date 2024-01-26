#include <stdexcept>
#include <iostream>
#include <queue>
#include "AVL.h"

using namespace std;

template<class T>
AVL<T>::Node::Node(const T &value) : data(value), height(1), balance_factor(0), left(nullptr), right(nullptr) {}

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
int AVL<T>::height() {
    return root->height;
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

template<class T>
shared_ptr<typename AVL<T>::Node> AVL<T>::insert(shared_ptr<Node> node, T new_value) {
    if (node == nullptr) {
        // If the current node is null, create a new node with the given value.
        return make_shared<Node>(new_value);
    }

    if (new_value < node->data) {
        // Recursively insert into the left subtree and update the left pointer.
        node->left = insert(node->left, new_value);
    } else {
        // Recursively insert into the right subtree and update the right pointer.
        node->right = insert(node->right, new_value);
    }

    update(node); // update balance factor and height
    return balance(node); // balance the AVL tree
}

template<class T>
bool AVL<T>::insert(T new_value) {
    if (contains(new_value)) {
        return false;
    } else {
        root = insert(root, new_value);
        ++node_count;
        return true;
    }
}

template<class T>
void AVL<T>::update(shared_ptr<Node> node) {
    int leftHeight = -1;
    int rightHeight = -1;
    if (node->left != nullptr) leftHeight = node->left->height;
    if (node->right != nullptr) leftHeight = node->right->height;

    node->height = 1 + max(leftHeight, rightHeight); // Update node height.
    node->balance_factor = rightHeight - leftHeight; // Update balance factor.
}

template<class T>
shared_ptr<typename AVL<T>::Node> AVL<T>::balance(shared_ptr<Node> node) {

    switch (node->balance_factor) {
        // Right Heavy subtree.
        case 2:
            if (node->balance_factor == 2) {
                if (node->right->balance_factor >= 0) {
                    return rightRightCase(node);
                } else {
                    return rightLeftCase(node);
                }
            }
            break;

        // Left Heavy subtree.
        case -2:
            if (node->left->balance_factor <= 0) {
                return leftLeftCase(node);
            } else {
                return leftRightCase(node);
            }
            break;
        default:
            return node;
    }
}

template<class T>
shared_ptr<typename AVL<T>::Node> AVL<T>::leftLeftCase(shared_ptr<Node> node) {
    return rightRotation(node);
}
template<class T>
shared_ptr<typename AVL<T>::Node> AVL<T>::leftRightCase(shared_ptr<Node> node) {
    node->left = leftRotation(node->left);
    return leftLeftCase(node);
}

template<class T>
shared_ptr<typename AVL<T>::Node> AVL<T>::rightRightCase(shared_ptr<Node> node) {
    return leftRotation(node);
}

template<class T>
shared_ptr<typename AVL<T>::Node> AVL<T>::rightLeftCase(shared_ptr<Node> node) {
    node->right = rightRotation(node->right);
    return rightRightCase(node);
}
