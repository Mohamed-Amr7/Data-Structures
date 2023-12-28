template<typename T>
Stack<T>::Node::Node(const T& val) : data(val), next(nullptr) {}

template<typename T>
Stack<T>::Node::Node() : data(T{}), next(nullptr) {}

template <typename T>
Stack<T>::Stack() : topPtr(nullptr){}

template <typename T>
T Stack<T>::top() {
    ensureNotEmpty();
    return topPtr->data;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return topPtr == nullptr;
}

template <typename T>
void Stack<T>::ensureNotEmpty() {
    if (isEmpty()) {
        throw std::invalid_argument("Stack is empty.");
    }
}

template <typename T>
int Stack<T>::size() {
    return _size;
}

template <typename T>
void Stack<T>::clear() {
    topPtr = nullptr;
    _size = 0;
}

template <typename T>
bool Stack<T>::push(T val) {
    auto new_node = std::make_shared<Node>(val);
    new_node->next = topPtr;
    topPtr = new_node;
    _size++;
    return true;
}

template <typename T>
T Stack<T>::pop() {
    ensureNotEmpty();
    T ret_val = topPtr->data;
    topPtr = topPtr->next;
    _size--;
    return ret_val;
}

