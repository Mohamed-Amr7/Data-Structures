#include "binary_search_tree.h"
#include <iostream>
#include <memory>

using namespace std;

template<class T>
BST<T>::BST() {
    root = nullptr;
    node_count = 0;
}

template<class T>
BST<T>::Node::Node(T value) {
    data = value;
    left = nullptr;
    right = nullptr;
}
