#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    void heapify_up(int index) {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            heapify_up(parent);
        }
    }
    void heapify_down(int index) {
        int left_child = (index * 2) + 1;
        int right_child = (index * 2) + 2;
        int largest = index;
        if (left_child < heap.size() && heap[left_child] > heap[largest]) {
            largest = left_child;
        }
        if (right_child < heap.size() && heap[right_child] > heap[largest]) {
            largest = right_child;
        }
        if (largest != index) {
            swap(heap[largest], heap[index]);
            heapify_down(largest);
        }
    }
public:
    MaxHeap() {}
    void insert(int value) {
        heap.push_back(value);
        heapify_up(heap.size() - 1);
    }
    int pop() {
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
        return root;
    }
    bool empty() {
        return heap.empty();
    }
};

class MaxPriorityQueue {
private:
    MaxHeap heap;
public:
    MaxPriorityQueue() {}
    void insert(int value) {
        heap.insert(value);
    }
    int pop() {
        return heap.pop();
    }
    bool empty() {
        return heap.empty();
    }
};

int main() {
    MaxPriorityQueue q;
    q.insert(5);
    q.insert(7);
    q.insert(2);
    q.insert(9);
    q.insert(4);

    while (!q.empty()) {
        cout << q.pop() << " ";
    }
    cout << endl;

    return 0;
}
