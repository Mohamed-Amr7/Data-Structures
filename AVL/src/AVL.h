#ifndef AVL_H
#define AVL_H

#include <memory>
#include <vector>

using namespace std;

template<class T>
class AVL {
private:
    class Node {
    public:
        T data;
        int balance_factor;
        int height;
        shared_ptr<Node> left;
        shared_ptr<Node> right;

        explicit Node(const T &value);
    };

    shared_ptr<Node> root; // Pointer to the root of the AVL.
    int node_count = 0; // Number of elements in the AVL.

    shared_ptr<Node> insert(shared_ptr<Node> node, T new_value);

    void update(shared_ptr<Node> node);

    shared_ptr<Node> balance(shared_ptr<Node> node);

    // Balancing Cases
    shared_ptr<Node> leftLeftCase(shared_ptr<Node> node);

    shared_ptr<Node> leftRightCase(shared_ptr<Node> node);

    shared_ptr<Node> rightLeftCase(shared_ptr<Node> node);

    shared_ptr<Node> rightRightCase(shared_ptr<Node> node);

    shared_ptr<Node> leftRotation(shared_ptr<Node> node);

    shared_ptr<Node> rightRotation(shared_ptr<Node> node);

    shared_ptr<Node> remove(shared_ptr<Node> node, T old_value);

    bool contains(shared_ptr<Node> node, T value);

    Node find_min(shared_ptr<Node> node);   // Helper method to find the leftmost node

    shared_ptr<Node> clear(shared_ptr<Node> node);

    // Recursive functions that takes a vector by reference
    // and places the elements in correct traversing order
    void inorderTraversal(shared_ptr<Node> node, vector<T> &result);

    void preorderTraversal(shared_ptr<Node> node, vector<T> &result);

    void postorderTraversal(shared_ptr<Node> node, vector<T> &result);

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

    AVL();

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

#include "AVL.cpp"

#endif //AVL_H
