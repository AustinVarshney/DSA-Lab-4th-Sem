#include <iostream>
using namespace std;

class LinkedList {
    int arr[100];    // Array to store node data
    int next[100];   // Array to store "next" indices
    int head;        // Index of the head node
    int size;        // Current size of the list

public:
    // Constructor to initialize the list
    LinkedList() {
        head = -1; // List is empty
        size = 0;  // No elements in the list
    }

    // Add a node at the beginning of the list
    void addFirst(int value) {
        arr[size] = value;      // Store the value in the array
        next[size] = head;      // Link the new node to the current head
        head = size;            // Update the head to the new node
        size++;                 // Increase the size of the list
    }

    // Add a node at the end of the list
    void addLast(int value) {
        arr[size] = value;  // Store the value in the array
        next[size] = -1;    // By default, the new node points to nothing

        if (head == -1) {
            // If the list is empty, the new node becomes the head
            head = size;
        } else {
            // Traverse to the last node
            int current = head;
            while (next[current] != -1) {
                current = next[current];
            }
            // Update the last node's "next" index
            next[current] = size;
        }
        size++;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == -1) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        // Special case: deleting the head node
        if (arr[head] == value) {
            head = next[head]; // Update the head to the next node
            cout << "Deleted node with value: " << value << endl;
            return;
        }

        // Traverse the list to find the node to delete
        int current = head;
        while (next[current] != -1 && arr[next[current]] != value) {
            current = next[current];
        }

        // If the value was not found
        if (next[current] == -1) {
            cout << "Value " << value << " not found in the list." << endl;
            return;
        }

        // Delete the node by skipping it in the "next" array
        next[current] = next[next[current]];
        cout << "Deleted node with value: " << value << endl;
    }

    // Display the list
    void display() {
        if (head == -1) {
            cout << "List is empty." << endl;
            return;
        }

        int current = head;
        while (current != -1) {
            cout << arr[current] << " -> ";
            current = next[current];
        }
        cout << "null" << endl;
    }
};

int main() {
    LinkedList list;

    // Add nodes at the beginning
    list.addFirst(30);
    list.addFirst(20);
    list.addFirst(10);

    // Add a node at the end
    list.addLast(40);

    list.addFirst(60);

    // Display the list
    list.display();

    // Delete nodes
    list.deleteNode(20); // Deleting a middle node
    list.display();

    list.deleteNode(60); // Deleting the head node
    list.display();

    list.deleteNode(100); // Attempting to delete a non-existent node
    list.display();

    return 0;
}