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
        shared_ptr<Node> left;
        shared_ptr<Node> right;
    public:
        explicit Node(T value);
        T getData();
        shared_ptr<Node> getLeft();
        shared_ptr<Node> getRight();

        void setLeft(shared_ptr<Node> left_ptr);
        void setRight(shared_ptr<Node> right_ptr);
    };

    shared_ptr<Node> root; // Pointer to the root of the BST.
    int node_count = 0; // Number of elements in the BST.

    shared_ptr<Node> insert(shared_ptr<Node> node, T new_value);

    shared_ptr<Node> remove(shared_ptr<Node> &parent, shared_ptr<Node> &node, T old_value);

    bool contains(shared_ptr<Node> node, T value);

    int height(shared_ptr<Node> &node);

    shared_ptr<Node> find_max(shared_ptr<Node> node);   // Helper method to find the rightmost node

    shared_ptr<Node> find_min(shared_ptr<Node> node);   // Helper method to find the leftmost node


public:
    BST();

    bool isEmpty();

    T top();

    int size();

    int height();

    bool insert(T new_value);

    bool remove(T old_value);

    bool contains(T value);
};

#include "binary_search_tree.cpp"

#endif //BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
