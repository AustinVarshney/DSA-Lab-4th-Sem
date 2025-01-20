#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    int next; // Index of the next node

    Node(int val = 0, int nextIndex = -1){
        data = val;
        next = nextIndex;
    }
};

class LinkedList {
private:
    vector<Node> nodes;
    int head;

public:
    LinkedList(){
        head = -1;
    }

    void insertAtEnd(int value) {
        nodes.emplace_back(value, -1);
        if (head == -1) {
            head = 0;
        } else {
            int temp = head;
            while (nodes[temp].next != -1) {
                temp = nodes[temp].next;
            }
            nodes[temp].next = nodes.size() - 1;
        }
    }

    void display() {
        int temp = head;
        while (temp != -1) {
            cout << nodes[temp].data << " ";
            temp = nodes[temp].next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    list.display();
    return 0;
}
