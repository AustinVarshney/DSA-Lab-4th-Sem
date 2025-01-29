#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
public:
    Node(int value){
        data = value;
        prev = next = NULL;
    }
};

class Queue{
    int size;
    Node** queue;
    int front, rear;
public:
    Queue(){
        size = 100;
        this->queue = new Node*[size];
        front = rear = -1;
    }

    void push(Node* value){
        if(front == -1){
            front = rear = 0;
            queue[rear] = value;
            return;
        }

        rear++;
        queue[rear] = value;
    }

    void pop(){
        if(front == -1){
            return;
        }

        if(front == rear){
            front = rear = -1;
            return;
        }
        front++;
    }

    Node* frontNode(){
        if(front == -1){
            return NULL;
        }
        return queue[front];
    }

    bool empty(){
        if(front == -1 && rear == -1){
            return true;
        }
        return false;
    }
};

Node* lastNodeFunc(Node*& root){
    // queue<Node*> q;
    Queue q;
    Node* currentNode;
    q.push(root);
    while(!q.empty()){
        currentNode = q.frontNode();
        q.pop();

        if(currentNode->prev){
            q.push(currentNode->prev);
        }
        if(currentNode->next){
            q.push(currentNode->next);
        }
    }

    return currentNode;
}

void deleteLastNodeFunc(Node*& root, Node*& lastNode){
    // queue<Node*> q;
    Queue q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.frontNode();
        q.pop();

        if(current->prev){
            if(current->prev == lastNode){
                current->prev = NULL;
                delete lastNode;
                return;
            } else{
                q.push(current->prev);
            }
        }
        
        if(current->next){
            if(current->next == lastNode){
                current->next = NULL;
                delete lastNode;
                return;
            } else{
                q.push(current->next);
            }
        }
    }
}

class binaryTree{
    Node* root;
public:
    binaryTree(){
        root = NULL;
    }

    void inorderTra(Node*& node);
    void inorderTraversal(){
        if(root == NULL){
            cout<<"Tree is empty.\n";
            return;
        }
        inorderTra(root);
    }

    void insertEl(Node*& root, int value);
    void insertElement(int value){
        insertEl(root, value);
    }

    void deleteElement(int value){
        if(root == NULL){
            cout<<"Tree is empty.\n";
            return;
        }

        // queue<Node*> q;
        Queue q;
        q.push(root);
        Node* targetNode = NULL;
        Node* lastNode = lastNodeFunc(root);
        while(!q.empty()){
            Node* currNode = q.frontNode();
            q.pop();

            if(currNode->data == value){
                targetNode = currNode;
                targetNode->data = lastNode->data;
                deleteLastNodeFunc(root, lastNode);
                cout<<"Element is deleted successfully.\n";
                return;
            }

            if(currNode->prev) q.push(currNode->prev);
            if(currNode->next) q.push(currNode->next);
        }
    }
};

void binaryTree::insertEl(Node*& node, int value){
    if(node == NULL){
        Node* newNode = new Node(value);
        node = newNode;
        return;
    }

    // queue<Node*> q;
    Queue q;
    q.push(node);
    while(!q.empty()){
        Node* currNode = q.frontNode();
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

void binaryTree::inorderTra(Node*& node){
    if(node == NULL){
        return;
    }
    inorderTra(node->prev);
    cout<<node->data<<" ";
    inorderTra(node->next);
}

int main(){
    binaryTree bt;
    int choice;

    while(true){
        cout<<"1. Add Element\n";
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
            cout<<endl;
        } else if(choice == 2){
            int value;
            cout<<"Enter the value you want to delete : ";
            cin>>value;
            bt.deleteElement(value);
            cout<<endl;
        } else if(choice == 3){
            bt.inorderTraversal();
            cout<<endl;
        } else if(choice == 4){
            cout<<"Exitting...\n";
            break;
        } else{
            cout<<"Wrong choice.\n";
            cout<<endl;
        }
    }

    return 0;
}