#include<iostream>
using namespace std;

class binaryTree{
    int* tree;
    int size;
    int root;
public:
    binaryTree(int size){
        this->size = size;
        this->tree = new int[size];
        root = -1;
        for (int i = 0; i < size; i++) {
            this->tree[i] = -1;
        }
    }

    void insertElement(int value){
        if(root == -1){
            root = 0;
            tree[root] = value;
            return;
        }

        if(root == size - 1){
            cout<<"Tree size is full.\n";
            return;
        }   

        root++;
        tree[root] = value;
    }

    void deleteElement(int value){
        if(root == -1){
            cout<<"Tree is empty.\n";
            return;
        }

        if(root == 0 && tree[root] == value){
            tree[root] = -1;
            root = -1;
            return;
        }

        for(int i = 0; i<=root; i++){
            if(tree[i] == value){
                tree[i] = -1;
                return;
            }
        }

        cout<<"Element not present in the tree.\n";
    }

    void levelOrderTraversal(){
        if(root == -1){
            cout<<"Tree is empty.\n";
            return;
        }
        for(int i=0; i<=root; i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }

    void inorderHelper(int index){
        if(index >= size){
            return;
        }
        inorderHelper(2*index+1);
        cout<<tree[index]<<" ";
        inorderHelper(2*index+2);
    }

    void inorderTraversal(){
        if(root == -1){
            cout<<"Tree is empty.\n";
            return;
        }
        inorderHelper(0);
        cout<<endl;
    }
};

int main(){
    binaryTree bt(5);
    int choice;

    while(true){
        cout<<"1. Insert Element.\n";
        cout<<"2. Delete Element.\n";
        cout<<"3. Level Order traversal.\n";
        cout<<"4. Inorder traversal.\n";
        cout<<"5. Exit.\n";
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
            bt.levelOrderTraversal();
            cout<<endl;
        } else if(choice == 4){
            bt.inorderTraversal();
            cout<<endl;
        } else if(choice == 5){
            cout<<"Exitting...\n";
            cout<<endl;
            break;
        } else{
            cout<<"Wrong choice.\n";
            cout<<endl;
        }
    }

    return 0;
}