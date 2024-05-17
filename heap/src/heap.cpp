#include "heap.h"

template<typename T>
Heap<T>::Heap(std::function<bool(T, T)> comp) : comparator(comp) {}

template<typename T>
Heap<T>::Heap(const std::vector<T>& elems, std::function<bool(T, T)> comp) : heap(elems), comparator(comp) {
    for (int i = size() / 2 - 1; i >= 0; --i) {
        sink(i);
    }
}

template<typename T>
bool Heap<T>::isEmpty() const {
    return heap.empty();
}

template<typename T>
void Heap<T>::clear() {
    heap.clear();
}

template<typename T>
int Heap<T>::size() const {
    return heap.size();
}

template<typename T>
const T& Heap<T>::peek() const {
    if (isEmpty()) throw std::runtime_error("Heap is empty");
    return heap.front();
}

template<typename T>
T Heap<T>::poll() {
    if (isEmpty()) throw std::runtime_error("Heap is empty");
    T root = heap.front();
    swap(0, size() - 1);
    heap.pop_back();
    sink(0);
    return root;
}

template<typename T>
bool Heap<T>::contains(const T& elem) const {
    for (const T& item : heap) {
        if (item == elem) return true;
    }
    return false;
}

template<typename T>
void Heap<T>::add(const T& elem) {
    heap.push_back(elem);
    swim(size() - 1);
}

template<typename T>
bool Heap<T>::remove(const T& elem) {
    for (int i = 0; i < size(); ++i) {
        if (heap[i] == elem) {
            swap(i, size() - 1);
            heap.pop_back();
            sink(i);
            if (heap[i] == elem) swim(i);
            return true;
        }
    }
    return false;
}

template<typename T>
void Heap<T>::swim(int k) {
    while (k > 0 && compare(k, (k - 1) / 2)) {
        swap(k, (k - 1) / 2);
        k = (k - 1) / 2;
    }
}

template<typename T>
void Heap<T>::sink(int k) {
    int size = heap.size();
    while (true) {
        int left = 2 * k + 1;
        int right = 2 * k + 2;
        int smallest = left;
        if (right < size && compare(right, left)) smallest = right;
        if (left >= size || compare(k, smallest)) break;
        swap(k, smallest);
        k = smallest;
    }
}

template<typename T>
void Heap<T>::swap(int i, int j) {
    T temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

template<typename T>
bool Heap<T>::compare(int i, int j)  {
    return comparator(heap[i], heap[j]);
}

template<typename T>
std::vector<T> Heap<T>::toVector() const {
    return heap;
}
