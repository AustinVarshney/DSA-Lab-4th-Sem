#include<iostream>
using namespace std;

class Stack{
    int* arr;
    int size, cap;
public:
    Stack(int n){
        cap = n;
        size = 0;
        arr = new int[n];
    }

    void push(int x){
        if(size == cap){
            cout<<"Size is full.\n";
            return;
        }
        arr[size] = x;
        size++;
    }

    void pop(){
        if(size == 0){
            cout<<"Stack is empty.\n";
            return;
        }
        size--;
    }

    int top(){
        if(size == 0){
            return -1;
        }
        return arr[size-1];
    }

    bool empty(){
        return size == 0;
    }
};

int main(){
    Stack s(5);
    int choice;

    while(true){
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Top\n";
        cout<<"4. Is Empty\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice : \n";
        cin >> choice;

        if(choice == 1){
            int value;
            cout<<"Enter the value : ";
            cin>>value;
            s.push(value);
        } else if(choice == 2){
            s.pop();
        } else if(choice == 3){
            cout<<s.top()<<endl;
        } else if(choice == 4){
            cout<<s.empty()<<endl;
        } else if(choice == 5){
            cout<<"Exitting...\n";
            break;
        } else {
            cout<<"Wrong choice. Please Enter again.\n";
        }

        cout<<endl;
    }
    
    return 0;
}