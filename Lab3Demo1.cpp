#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Class for Binary Search Tree
class BST {
private:
    Node* root;

    // Recursive function to insert a node
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Recursive function for in-order traversal
    void inOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Recursive function to search for a value
    bool searchNode(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return searchNode(node->left, value);
        } else {
            return searchNode(node->right, value);
        }
    }

public:
    BST() {
        root = nullptr;
    }

    // Public method to insert a value
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Public method for in-order traversal
    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    // Public method to search for a value
    bool search(int value) {
        return searchNode(root, value);
    }
};

// Main function
int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order Traversal: ";
    bst.inOrder();

    int key = 40;
    if (bst.search(key)) {
        cout << key << " found in the BST." << endl;
    } else {
        cout << key << " not found in the BST." << endl;
    }

    return 0;
}
