#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int value){
        data = value;
        prev = next = NULL;
    }
};

Node* lastNodeFunc(Node*& node){
    queue<Node*> q;
    q.push(node);
    Node* current;

    while(!q.empty()){
        current = q.front();
        q.pop();

        if(current->prev){
            q.push(current->prev);
        }
        if(current->next){
            q.push(current->next);
        }
    }

    return current;
}

void deleteLastNodeFunc(Node* root, Node* lastNode){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* tempNode = q.front();
        q.pop();

        if(tempNode->prev){
            if(tempNode->prev == lastNode){
                tempNode->prev = NULL;
                delete lastNode;
                return;
            } else{
                q.push(tempNode->prev);
            }
        }
        
        if(tempNode->next){
            if(tempNode->next == lastNode){
                tempNode->next = NULL;
                delete lastNode;
                return;
            } else{
                q.push(tempNode->next);
            }
        }
    }
};

class binaryTree{
    Node* root;
public:
    binaryTree(){
        root = NULL;
    }

    Node*& inorderTra(Node*& node);
    Node*& inorderTraversal(){
        if(root == NULL){
            cout<<"Tree is empty.\n";
            return root;
        }

        inorderTra(root);
    }
    void insertEl(Node*& node, int value);
    void insertElement(int value){
        insertEl(root, value);
    }

    void deleteElement(int value){
        if(root == NULL){
            cout<<"Tree is empty. Nothing to delete.\n";
            return;
        }

        queue<Node*> q;
        q.push(root);
        Node* targetNode = NULL;
        Node* lastNode = lastNodeFunc(root);
        while(!q.empty()){
            Node* current = q.front();
            q.pop();

            if(current->data == value){
                targetNode = current;
                targetNode->data = lastNode->data;
                deleteLastNodeFunc(root, lastNode);
                cout<<"Element is deleted successfully.\n";
                cout<<endl;
                return;
            }
            if(current->prev){
                q.push(current->prev);
            } 
            if(current->next){
                q.push(current->next);
            } 
        }

        if(targetNode == NULL){
            cout<<"Node is not present in the tree.\n";
            cout<<endl;
        }
    }
};

void binaryTree::insertEl(Node*& node, int value){
    if(node == NULL){
        Node* newNode = new Node(value);
        node = newNode;
        return;
    }

    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        Node* currNode = q.front();
        q.pop();

        if(currNode->prev == NULL){
            Node* newNode = new Node(value);
            currNode->prev = newNode;
            return;
        } else{
            q.push(currNode->prev);
        }

        if(currNode->next == NULL){
            Node* newNode = new Node(value);
            currNode->next = newNode;
            return;
        } else{
            q.push(currNode->next);
        }
    }
}

Node*& binaryTree::inorderTra(Node*& node){
    if(node == NULL){
        return node;
    }

    inorderTra(node->prev);
    cout<<node->data<<" ";
    inorderTra(node->next);
    return node;
};

int main(){
    binaryTree bt;

    int choice;
    while(true){
        cout<<"1. Insert Element\n";
        cout<<"2. Delete Element\n";
        cout<<"3. Inorder Traversal\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice : ";
        cin>>choice;

        if(choice == 1){
            int value;
            cout<<"Enter the value you want to add : ";
            cin>>value;
            bt.insertElement(value);
            cout<<endl<<endl;
        } else if(choice == 2){
            int value;
            cout<<"Enter the value you want to delete : ";
            cin>>value;
            bt.deleteElement(value);
            cout<<endl<<endl;
        } else if(choice == 3){
            bt.inorderTraversal();
            cout<<endl<<endl;
        } else if(choice == 4){
            cout<<"Exitting...\n";
            cout<<endl<<endl;
            break;
        } else{
            cout<<"Enter valid choice.\n";
            cout<<endl<<endl;
        }
    }

    return 0;
}