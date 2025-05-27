#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
public:
    Node* top;

    Stack() : top(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void print() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Merge another stack into this one in O(1)
    void merge(Stack& other) {
        if (!other.top) return;
        Node* temp = other.top;
        // Move the top of `other` stack to the top of `this` stack
        Node* last = temp;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = top;
        top = other.top;

        other.top = nullptr;  // Clear the other stack
    }
};

int main() {
    int n = 10;
    Stack evenStack, oddStack;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0)
            evenStack.push(i);
        else
            oddStack.push(i);
    }

    cout << "Even Stack: ";
    evenStack.print();

    cout << "Odd Stack: ";
    oddStack.print();

    // Merge evenStack into oddStack in O(1)
    oddStack.merge(evenStack);

    cout << "Merged Stack (odd + even): ";
    oddStack.print();

    return 0;
}
