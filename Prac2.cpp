#include<iostream>
using namespace std;

class Stack{
    int cap;
    int top = -1;
    int* arr;
public:
    Stack(int c){
        cap = c;
        arr = new int[c];
    }

    void push(int el){
        if(top == cap-1){
            cout<<"Stack is full\n";
            return;
        }
        top++;
        arr[top] = el;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack is empty\n";
            return;
        }
        cout<<arr[top]<<" is deleted\n";
        top--;
    }

    void topEl(){
        if(top == -1){
            cout<<"Stack is empty\n";
            return;
        }
        cout<<arr[top]<<endl;
    }

    void isEmpty(){
        if(top == -1){
            cout<<"Stack is empty\n";
            return;
        }
        cout<<"Stack is not empty\n";
    }

    ~Stack() {
        delete[] arr;
    }
};

int main(){
    Stack s(3);
    s.isEmpty();    // Stack is empty
    s.push(10);
    s.push(20);
    s.topEl();       // 20
    s.push(30);
    s.push(40);     // Stack is full
    s.pop();        // 30 is deleted
    s.topEl();       // 20
    s.pop();        // 20 is deleted
    s.pop();        // 10 is deleted
    s.pop();        // Stack is empty

    return 0;
}