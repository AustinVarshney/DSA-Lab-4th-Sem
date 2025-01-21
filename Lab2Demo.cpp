#include <iostream>
#include <vector>
using namespace std;

// Node structure
class Node {
public:
    int data;   // Data in the node
    int next;   // Index of the next node (-1 indicates the end)

    Node(int val = 0, int nextIndex = -1) : data(val), next(nextIndex) {}
};

// Linked List class
class LinkedList {
    vector<Node> nodes; // Array of nodes
    int head;           // Index of the head node

public:
    // Constructor
    LinkedList() : head(-1) {}

    // Insert a new node at the end of the list
    void insertAtEnd(int value) {
        nodes.emplace_back(value, -1); // Create a new node
        if (head == -1) { // If the list is empty
            head = 0;     // New node becomes the head
        } else {
            int temp = head;
            while (nodes[temp].next != -1) { // Traverse to the last node
                temp = nodes[temp].next;
            }
            nodes[temp].next = nodes.size() - 1; // Link the last node to the new node
        }
    }

    // Insert a new node at the start of the list
    void insertAtStart(int value) {
        nodes.emplace_back(value, head); // Create a new node pointing to the current head
        head = nodes.size() - 1;         // Update the head to the new node
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == -1) { // If the list is empty
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        // Special case: Deleting the head node
        if (nodes[head].data == value) {
            head = nodes[head].next; // Update head to the next node
            return;
        }

        // Traverse to find the node to delete
        int temp = head;
        while (nodes[temp].next != -1 && nodes[nodes[temp].next].data != value) {
            temp = nodes[temp].next;
        }

        if (nodes[temp].next == -1) { // Value not found
            cout << "Value " << value << " not found in the list.\n";
        } else {
            // Remove the node by updating the link
            nodes[temp].next = nodes[nodes[temp].next].next;
        }
    }

    // Display the list
    void display() {
        if (head == -1) {
            cout << "List is empty.\n";
            return;
        }

        int temp = head;
        while (temp != -1) {
            cout << nodes[temp].data << " ";
            temp = nodes[temp].next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "After inserting at the end: ";
    list.display();

    list.insertAtStart(5);
    cout << "After inserting at the start: ";
    list.display();

    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();

    list.deleteNode(100);
    cout << "After attempting to delete 100: ";
    list.display();

    return 0;
}
