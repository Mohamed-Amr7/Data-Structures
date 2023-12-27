#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <vector>

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

        void setData(T new_data);

        shared_ptr<Node> getLeft();

        shared_ptr<Node> getRight();

        void setLeft(shared_ptr<Node> left_ptr);

        void setRight(shared_ptr<Node> right_ptr);
    };

    shared_ptr<Node> root; // Pointer to the root of the BST.
    int node_count = 0; // Number of elements in the BST.

    shared_ptr<Node> insert(shared_ptr<Node> node, T new_value);

    shared_ptr<Node> remove(shared_ptr<Node> node, T old_value);

    bool contains(shared_ptr<Node> node, T value);

    int height(shared_ptr<Node> node);

    Node find_min(shared_ptr<Node> node);   // Helper method to find the leftmost node

    shared_ptr<Node> clear(shared_ptr<Node> node);

    // Recursive functions that takes a vector by reference
    // and places the elements in correct traversing order
    void inorderTraversal(shared_ptr<Node> node, vector<T>& result);

    void preorderTraversal(shared_ptr<Node> node, vector<T>& result);

    void postorderTraversal(shared_ptr<Node> node, vector<T>& result);

    // Wrapper functions for the recursive functions
    vector<T> inorderTraversal();

    vector<T> preorderTraversal();

    vector<T> postorderTraversal();

    vector<T> levelOrderTraversal(shared_ptr<Node> node);

public:
    enum TraverseType {
        INORDER,
        PREORDER,
        POSTORDER,
        LEVELORDER
    };

    BST();

    bool isEmpty();

    T top();

    int size();

    int height();

    bool insert(T new_value);

    bool remove(T old_value);

    bool contains(T value);

    void clear();

    std::vector<T> traverse(TraverseType type);
};

#include "binary_search_tree.cpp"

#endif //BINARY_SEARCH_TREE_H
