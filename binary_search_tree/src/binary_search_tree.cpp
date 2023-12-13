#include <stdexcept>
#include <iostream>
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
void BST<T>::Node::setData(T new_data) {
    data = new_data;
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
    if (isEmpty()) throw runtime_error("BST is empty!");
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
    } else if (value < node->getData()) {
        return contains(node->getLeft(), value);
    } else {
        return contains(node->getRight(), value);
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
        root = insert(root, new_value);
        ++node_count;
        return true;
    }
}

template<class T>
BST<T>::Node BST<T>::find_min(shared_ptr<Node> node) {
    // Find the leftmost node of a subtree
    while (node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return *node;
}

template<class T>
shared_ptr<typename BST<T>::Node> BST<T>::remove(shared_ptr<Node> node, T old_value) {
    if (node == nullptr) {
        return nullptr; // Base case: element not found.
    }

    // Finding phase
    if (old_value < node->getData()) {
        // Recursively remove from the left subtree and update the left pointer.
        node->setLeft(remove(node->getLeft(), old_value));
    } else if (node->getData() < old_value) {
        // Recursively remove from the right subtree and update the right pointer.
        node->setRight(remove(node->getRight(), old_value));
    } else {
        // Element found, perform removal.

        // In case there is only a Right subtree or no subtree at all.
        if (node->getLeft() == nullptr) {
            return node->getRight();
        }
            // In case there is only a left subtree.
        else if (node->getRight() == nullptr) {
            return node->getLeft();
        } else {
            // Find the minimum value in the right subtree, which serves as the replacement for the current node's data.
            Node tmp = find_min(node->getRight());
            node->setData(tmp.getData());

            // Recursively remove the leftmost right-subtree node after updating the current node's data.
            // Multiple nodes sharing the same data temporarily isn't an issue as we search from the node's right subtree.
            node->setRight(remove(node->getRight(), tmp.getData()));
        }
    }

    return node;
}

template<class T>
bool BST<T>::remove(T old_value) {
    if (contains(old_value)) {
        root = remove(root, old_value);
        --node_count;
        return true;
    }
    return false;
}

template<class T>
int BST<T>::height(shared_ptr<Node> node) {
    if (node == nullptr) return 0;
    return max(height(node->getRight()), height(node->getLeft())) + 1;
}

template<class T>
int BST<T>::height() {
    return height(root);
}


template<class T>
shared_ptr<typename BST<T>::Node> BST<T>::clear(shared_ptr<Node> node) {
    if (node != nullptr) {
        // Recursively clear the left and right subtrees.
        node->setLeft(clear(node->getLeft()));
        node->setRight(clear(node->getRight()));
        return nullptr;
    }
    return nullptr; // Return nullptr to update the parent's pointer.
}

template<class T>
void BST<T>::clear() {
    root = clear(root);
    node_count = 0;
}

template<class T>
vector<T> BST<T>::traverse(TraverseType type) {
    switch (type) {
        case INORDER:
            return inorderTraversal(root);
        case PREORDER:
            return preorderTraversal(root);
        case POSTORDER:
            return postorderTraversal(root);
        case LEVELORDER:
            return levelOrderTraversal(root);
        default:
            cerr << "Invalid traversal type!" << endl;
            return vector<T>{};
    }
}

template<class T>
void BST<T>::inorderTraversal(shared_ptr<Node> node, vector<T>& result) {
    if (node != nullptr) {
        // Inorder traversal follows the pattern of left subtree, current node, and then right subtree.
        // This sequence ensures that nodes are visited in ascending order for a binary search tree.
        inorderTraversal(node->getLeft(), result);
        result.push_back(node->getData());
        inorderTraversal(node->getRight(), result);
    }
}

// Wrapper function
template<class T>
vector<T> BST<T>::inorderTraversal() {
    vector<T> result;
    inorderTraversal(root, result);
    return result;
}

template<class T>
void BST<T>::preorderTraversal(shared_ptr<Node> node, vector<T>& result) {
    if (node != nullptr) {
        // Preorder traversal starts with processing the current node, followed by the left subtree and then the right subtree.
        // This order is useful for creating a copy of the tree or evaluating expressions.
        result.push_back(node->getData());
        preorderTraversal(node->getLeft(), result);
        preorderTraversal(node->getRight(), result);
    }
}

// Wrapper function
template<class T>
vector<T> BST<T>::preorderTraversal() {
    vector<T> result;
    preorderTraversal(root, result);
    return result;
}
