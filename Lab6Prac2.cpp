#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;     // Dynamic array to store elements
    int capacity;  // Maximum capacity
    int size;      // Current number of elements

public:
    MaxHeap(int cap) {
        capacity = cap;
        heap = new int[cap];
        size = 0;
    }

    // Get parent index
    int parent(int i) { return (i - 1) / 2; }

    // Get left child index
    int leftChild(int i) { return 2 * i + 1; }

    // Get right child index
    int rightChild(int i) { return 2 * i + 2; }

    // Insert a new element (Push)
    void push(int value) {
        if (size == capacity) {
            cout << "Heap is full!\n";
            return;
        }
        // Insert at the end
        size++;
        int i = size - 1;
        heap[i] = value;

        // Heapify Up (Bubble Up)
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Get the maximum element (Top)
    int top() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return -1;
        }
        return heap[0];
    }

    // Remove the maximum element (Pop)
    void pop() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return;
        }
        heap[0] = heap[size - 1];  // Replace root with last element
        size--;
        heapifyDown(0);  // Heapify down
    }

    // Heapify Down (to maintain heap property after pop)
    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Check if the heap is empty
    bool isEmpty() {
        return size == 0;
    }

    // Display elements
    void display() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap pq(10);

    pq.push(50);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(10);

    cout << "Priority Queue: ";
    pq.display(); // Output: 50 40 30 20 10

    cout << "Top element: " << pq.top() << endl; // Output: 50

    pq.pop();
    cout << "After pop, top element: " << pq.top() << endl; // Output: 40

    pq.display(); // Output: 40 20 30 10

    return 0;
}
