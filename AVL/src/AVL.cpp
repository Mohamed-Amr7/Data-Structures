#include <stdexcept>
#include <iostream>
#include <queue>
#include "AVL.h"

using namespace std;

template<class T>
AVL<T>::Node::Node(const T &value) : data(value), height(0), balance_factor(0), left(nullptr), right(nullptr) {}

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
    if (node->right != nullptr) rightHeight = node->right->height;

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

template<class T>
shared_ptr<typename AVL<T>::Node> AVL<T>::leftRotation(shared_ptr<Node> node) {
    shared_ptr<Node> newParent = node->right;
    node->right = newParent->left;
    newParent->left = node;
    update(node);
    update(newParent);
    return newParent;
}
template<class T>
shared_ptr<typename AVL<T>::Node> AVL<T>::rightRotation(shared_ptr<AVL::Node> node){
    shared_ptr<Node> newParent = node->left;
    node->left = newParent->right;
    newParent->right = node;
    update(node);
    update(newParent);
    return newParent;
}


template<class T>
AVL<T>::Node AVL<T>::find_min(shared_ptr<Node> node) {
    // Find the leftmost node of a subtree
    while (node->left != nullptr) {
        node = node->left;
    }
    return *node;
}

template<class T>
shared_ptr<typename AVL<T>::Node> AVL<T>::remove(shared_ptr<Node> node, T old_value) {
    if (node == nullptr) {
        return nullptr; // Base case: element not found.
    }

    // Finding phase
    if (old_value < node->data) {
        // Recursively remove from the left subtree and update the left pointer.
        node->left = remove(node->left, old_value);
    } else if (node->data < old_value) {
        // Recursively remove from the right subtree and update the right pointer.
        node->right = remove(node->right, old_value);
    } else {
        // Element found, perform removal.

        // In case there is only a Right subtree or no subtree at all.
        if (node->left == nullptr) {
            return node->right;
        }
            // In case there is only a left subtree.
        else if (node->right == nullptr) {
            return node->left;
        } else {
            // Find the minimum value in the right subtree, which serves as the replacement for the current node's data.
            Node tmp = find_min(node->right);
            node->data = tmp.data;

            // Recursively remove the leftmost right-subtree node after updating the current node's data.
            // Multiple nodes sharing the same data temporarily isn't an issue as we start searching from the node's right subtree.
            node->right = remove(node->right, tmp.data);
        }
    }
    update(node);

    return balance(node);
}


template<class T>
bool AVL<T>::remove(T old_value) {
    if (contains(old_value)) {
        root = remove(root, old_value);
        --node_count;
        return true;
    }
    return false;
}


template<class T>
shared_ptr<typename AVL<T>::Node> AVL<T>::clear(shared_ptr<Node> node) {
    if (node != nullptr) {
        // Recursively clear the left and right subtrees.
        node->left = clear(node->left);
        node->right = clear(node->right);
        return nullptr;
    }
    return nullptr; // Return nullptr to update the parent's pointer.
}

template<class T>
void AVL<T>::clear() {
    root = clear(root);
    node_count = 0;
}


