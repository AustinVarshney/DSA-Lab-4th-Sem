#include<iostream>
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

class binarySearchTree{
    Node* root;
public:
    binarySearchTree(){
        root = NULL;
    }    

    void addEle(Node*& node, int value);
    void addElement(int value){
        addEle(root, value);
        return;
    }

    void inorderTra(Node*& node);
    void inorderTraversal(){
        if(root == NULL){
            cout<<"Tree is empty.\n";
            return;
        }
        inorderTra(root);
    }

    void deleteEle(Node*& node, int value);
    void deleteElement(int value){
        if(root == NULL){
            cout<<"Tree is empty.\n";
            return;
        }

        deleteEle(root, value);
    }
};  

void binarySearchTree::addEle(Node*& node, int value){
    if(node == NULL){
        Node* newlink = new Node(value);
        newlink->prev = NULL;
        newlink->next = NULL;
        node = newlink;
        return;
    }

    if(node->data < value){
        addEle(node->next, value);
    } else if(node->data > value){
        addEle(node->prev, value);
    } else{
        cout<<"Element already exists.\n";
        return;
    }
}

void binarySearchTree::deleteEle(Node*& node, int value){
    if(node == NULL){
        cout<<"Value does not exist in the BST.\n";
        return;
    }

    if(node->data < value){
        deleteEle(node->next, value);
    } else if(node->data > value){
        deleteEle(node->prev, value);
    } else{
        if(node->prev == NULL && node->next == NULL){               //For 0 child
            Node* temp = node;
            delete temp;
            node = NULL;
            return;
        } else if(node->prev == NULL || node->next == NULL){        //For 1 child
            Node* nextNode = node->prev == NULL ? node->next : node->prev;
            Node* temp = node;
            delete temp;
            node = nextNode;
            return;
        } else{                                                     //For 2 child
            Node* successor = node->next;
            while(successor->prev != NULL){
                successor = successor->prev;
            }
            node->data = successor->data;
            deleteEle(node->next, successor->data);
            return;
        }
    }
}

void binarySearchTree::inorderTra(Node*& node){
    if(node == NULL){
        return;
    }
    inorderTra(node->prev);
    cout<<node->data<<" ";
    inorderTra(node->next);
}


int main(){
    binarySearchTree bst;

    int choice;

    while(true){
        cout<<"1. Add Element\n";
        cout<<"2. Inorder Traversal\n";
        cout<<"3. Delete Element\n";
        cout<<"4. Exit\n";
        cout<<"Enter Choice : ";
        cin>>choice;

        if(choice == 1){
            int value;
            cout<<"Enter the value you want to add : ";
            cin>>value;
            bst.addElement(value);
            cout<<endl;
        } else if(choice == 2){
            bst.inorderTraversal();
            cout<<endl<<endl;
        } else if(choice == 3){
            int value;
            cout<<"Enter the value you want to delete : ";
            cin>>value;
            bst.deleteElement(value);
            cout<<endl<<endl;
        } else if(choice == 4){
            cout<<"Exitting...\n";
            break;
        } else{
            cout<<"Please Enter a valid choice.\n";
            cout<<endl;
        }
    }
    return 0;
}