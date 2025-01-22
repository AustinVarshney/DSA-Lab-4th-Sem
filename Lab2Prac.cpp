#include<iostream>
using namespace std;

class LinkedList{
    int arr[100];
    int next[100];
    int head;
    int size;
public: 
    LinkedList(){
        head = -1;
        size = 0;
    }

    void addFirst(int value){
        if(head == -1){
            head = 0;
            arr[size] = value;
            next[size] = -1;
            size++;
            return;
        }
        int currIdx = size;
        while(currIdx!=0){
            arr[currIdx] = arr[currIdx-1];
            next[currIdx] = next[currIdx-1];
            currIdx--;
        }
        arr[currIdx] = value;
        next[currIdx] = currIdx+1;
        size++;
    }

    void addMiddle(int value, int key){
        if(key >= 0 && key <= size-1){
            int current = size;
            while(current != key){
                arr[current] = arr[current-1];
                next[current] = next[current-1];
                current--;
            }
            arr[current] = value;
            next[current] = current;
            size++;
        } else{
            cout<<"Please enter the valid index."<<endl;
        }
        
    }

    void addLast(int value){
        if(head == -1){
            head = 0;
        }
        arr[size] = value;
        next[size-1] = size;
        next[size] = -1;
        size++;
    }

    void print(){
        if(head == -1){
            cout<<"List is empty"<<endl;
            return;
        }
        int current = head;
        while(next[current] != -1){
            cout<<arr[current]<<" -> ";
            current++;
        }
        cout<<arr[current]<<" -> NULL"<<endl;
    }
};

int main(){
    LinkedList ll;
    
    ll.addFirst(10);
    ll.addFirst(20);
    ll.addFirst(30);
    ll.addFirst(40);

    // ll.addMiddle(01,0);
    
    // ll.addLast(40);
    // ll.addLast(60);

    // ll.addMiddle(50,2);
    // ll.addMiddle(100,2);
    // ll.addMiddle(12,7);

    ll.print();

    return 0;
}