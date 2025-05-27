#include<iostream>
using namespace std;

class Queue{
    int cap = 0;
    int front = -1, rear = -1;
    int* arr;
public:
    Queue(int c){
        cap = c;
        arr = new int[c];
    }

    void push(int el){
        if((front == 0 && rear == cap-1) || front == rear+1){
            cout<<"Queue is full\n";
            return;
        }
        if(front == -1 && rear == -1){
            front = rear = 0;
            arr[rear] = el;
            return;
        }

        if(rear == cap-1){
            rear = 0;
        } else{
            rear++;
        }
        arr[rear] = el;
    }
    
    void pop(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty\n";
            return;
        }

        if(front == rear){
            cout<<arr[rear]<<" is deleted.\n";
            front = rear = -1;
            return;
        }

        if(front == cap-1){
            front = 0;
        }else{
            front++;
        }
    }

    void begin(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty\n";
            return;
        }
        cout<<arr[front]<<endl;
    }

    void isEmpty(){
        if(front == -1 && rear == -1){
            cout<<"true\n";
        }else{
            cout<<"false\n";
        }
    }

    ~Queue() {
        delete[] arr;
    }
};

int main(){
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    q.begin();  //1

    q.pop();
    q.begin();  //2

    q.pop();
    q.begin();  //3

    q.pop();
    q.begin();  //4

    q.push(5);
    q.push(6);

    q.begin();  //4

    q.isEmpty();

    q.push(7);
    q.push(8);

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    q.isEmpty();

    return 0;
}