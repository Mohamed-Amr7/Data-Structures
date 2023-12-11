#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H

#include <memory>

using namespace std;

template<class T>
class BST {
private:
    class Node {
    public:
        T data;
        unique_ptr<Node> left;
        unique_ptr<Node> right;

        explicit Node(T value);
    };

    unique_ptr<Node> root; // Pointer to the root of the BST.
    int node_count = 0; // Number of elements in the BST.

    bool insert(unique_ptr<Node> &node, T new_value);

    bool remove(unique_ptr<Node> &parent, unique_ptr<Node> &node, T old_value);

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
