#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H

#include <memory>

using namespace std;

template<class T>
class BST {
private:
    class Node {
    private:
        T data;
        unique_ptr<Node> left;
        unique_ptr<Node> right;
    public:
        explicit Node(T value);
        T getData();
        unique_ptr<Node> getLeft();
        unique_ptr<Node> getRight();

        void setLeft(unique_ptr<Node> left_ptr);
        void setRight(unique_ptr<Node> right_ptr);
    };

    unique_ptr<Node> root; // Pointer to the root of the BST.
    int node_count = 0; // Number of elements in the BST.

    unique_ptr<Node> insert(unique_ptr<Node> &node, T new_value);

    unique_ptr<Node> remove(unique_ptr<Node> &parent, unique_ptr<Node> &node, T old_value);

    bool contains(unique_ptr<Node> &node, T value);

    int height(unique_ptr<Node> &node);

    Node find_max(unique_ptr<Node> &node);   // Helper method to find the rightmost node

    Node find_min(unique_ptr<Node> &node);   // Helper method to find the leftmost node


public:
    BST();

    bool isEmpty();

    int size();

    int height();

    bool insert(T new_value);

    bool remove(T old_value);

    bool contains(T value);
};

#include "binary_search_tree.cpp"

#endif //BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
