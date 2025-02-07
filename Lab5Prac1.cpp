#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = next = NULL;
    }
};

class binarySearchTree {
    Node* root;

public:
    binarySearchTree() {
        root = NULL;
    }

    void addEle(Node*& node, int value);
    void addElement(int value) {
        addEle(root, value);
    }

    void inorderTraversal(); // Iterative version (updated)
    
    void deleteEle(Node*& node, int value);
    void deleteElement(int value) {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        deleteEle(root, value);
    }
};

// Recursive function to insert a node
void binarySearchTree::addEle(Node*& node, int value) {
    if (node == NULL) {
        node = new Node(value);
        return;
    }

    if (value < node->data) {
        addEle(node->prev, value);
    } else if (value > node->data) {
        addEle(node->next, value);
    } else {
        cout << "Element already exists.\n";
    }
}

// **Iterative Inorder Traversal**
void binarySearchTree::inorderTraversal() {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return;
    }

    stack<Node*> s;
    Node* current = root;

    while (current != NULL || !s.empty()) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            s.push(current);
            current = current->prev;  // Move left
        }

        // Current is NULL at this point, pop the top node
        current = s.top();
        s.pop();

        cout << current->data << " ";  // Print the node value

        // Move to the right subtree
        current = current->next;
    }
    cout << endl;
}

// Recursive function to delete a node
void binarySearchTree::deleteEle(Node*& node, int value) {
    if (node == NULL) {
        cout << "Value does not exist in the BST.\n";
        return;
    }

    if (value < node->data) {
        deleteEle(node->prev, value);
    } else if (value > node->data) {
        deleteEle(node->next, value);
    } else {
        if (node->prev == NULL && node->next == NULL) {  // Case 1: No child
            delete node;
            node = NULL;
        } else if (node->prev == NULL || node->next == NULL) {  // Case 2: One child
            Node* temp = node;
            node = (node->prev != NULL) ? node->prev : node->next;
            delete temp;
        } else {  // Case 3: Two children
            Node* successor = node->next;
            while (successor->prev != NULL) {
                successor = successor->prev;
            }
            node->data = successor->data;
            deleteEle(node->next, successor->data);
        }
    }
}

// **Main function**
int main() {
    binarySearchTree bst;
    int choice;

    while (true) {
        cout << "1. Add Element\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Delete Element\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            int value;
            cout << "Enter the value you want to add: ";
            cin >> value;
            bst.addElement(value);
            cout << endl;
        } else if (choice == 2) {
            bst.inorderTraversal();
            cout << endl;
        } else if (choice == 3) {
            int value;
            cout << "Enter the value you want to delete: ";
            cin >> value;
            bst.deleteElement(value);
            cout << endl;
        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Please enter a valid choice.\n";
        }
    }
    return 0;
}
