#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class linkedList{
    Node* head;
    int size;

public:
    linkedList(){
        head = NULL;
        size = 0;
    }

    //Insertion at Begin
    void addFront(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }

    //Insertion at Middle By Value
    void addMiddleByValue(int val, int value){
        Node* newNode = new Node(val);
        if(head == NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        Node* temp = head;
        if(temp->data == value){
            newNode->next = head;
            head = newNode;
            size++;
            return;
        }
        Node* prevNode = head;
        temp = temp->next;
        while(temp->data != value && temp->next != NULL){
            prevNode = temp;
            temp = temp->next;
        }

        if(temp->next == NULL && temp->data != value){
            cout<<"Value "<<value<<" does not exist in the list.\n";
        } else{
            newNode->next = temp;
            prevNode->next = newNode;
            size++;
        }
    }

    //Insertion at Middle By Position
    void addMiddleByPosition(int value, int pos){
        if(pos <=0 || pos > size){
            cout<<"Position is not valid for Insertion.\n";
            return;
        }
        
        Node* newNode = new Node(value);
        if(pos == 1){
            newNode->next = head;
            head = newNode;
            size++;
            return;
        }

        int count = 2;
        Node* prevNode = head;
        Node* temp = head->next;
        while(count != pos){
            prevNode = temp;
            temp = temp->next;
            count++;
        }
        newNode->next = temp;
        prevNode->next = newNode;
        size++;
    }    

    //Insertion at End
    void addLast(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            size++;
            return;
        }

        if(head->next == NULL){
            newNode->next = head;
            head = newNode;
            size++;
            return;
        }

        Node* prevNode = head;
        Node* temp = head->next;
        while(temp != NULL){
            prevNode = temp;
            temp = temp->next;
        }
        newNode->next = temp;
        prevNode->next = newNode;
        size++;
    }

    //Deletion at Begin
    void deleteFront(){
        if(head == NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        if(head->next == NULL){
            Node* temp = head;
            head = NULL;
            cout<<"Deleted value is "<<temp->data<<endl;
            delete temp;
            size--;
            return;
        }

        Node* temp = head;
        head = head->next;
        cout<<"Deleted value is "<<temp->data<<endl;
        delete temp;
        size--;
    }

    //Deletion at Middle By Value
    void deleteByValue(int value){
        if(head == NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        if(head->data == value){
            Node* temp = head;
            if(head->next == NULL){
                head = NULL;
            } else{
                head = head->next;
            }
            cout<<"Deleted value is "<<temp->data<<endl;
            delete temp;
            size--;
            return;
        }

        Node* temp = head->next;
        Node* prevNode = head;
        while(temp->next != NULL && temp->data != value){
            prevNode = temp;
            temp = temp->next;
        }

        if(temp->next == NULL && temp->data != value){
            cout<<"Value does not exist in the list.\n";
        } else{
            prevNode->next = temp->next;
            cout<<"Deleted value is "<<temp->data<<endl;
            delete temp;
            size--;
        }
    }

    //Deletion at Middle by Position
    void deleteByPosition(int pos){
        if(head == NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        if(pos <=0 || pos > size){
            cout<<"Position is not valid for Insertion.\n";
            return;
        }

        if(pos == 1){
            Node* temp = head;
            if(head->next == NULL){
                head = NULL;
            } else{
                head = head->next;
            }
            cout<<"Deleted value is "<<temp->data<<endl;
            delete temp;
            size--;
            return;
        }

        int count = 2;
        Node* prevNode = head;
        Node* temp = head->next;
        while(count != pos){
            prevNode = temp;
            temp = temp->next;
            count++;
        }
        prevNode->next = temp->next;
        cout<<"Deleted value is "<<temp->data<<endl;
        delete temp;
        size--;
    }

    //Deletion at End
    void deleteEnd(){
        if(head == NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        if(head->next == NULL){
            Node* temp = head;
            head = NULL;
            cout<<"Deleted value is "<<temp->data<<endl;
            delete temp;
            size--;
            return;
        }

        Node* prevNode = head;
        Node* temp = head->next;
        while(temp->next != NULL){
            prevNode = temp;
            temp = temp->next;
        }
        prevNode->next = NULL;
        cout<<"Deleted value is "<<temp->data<<endl;
        delete temp;
        size--;
    }

    //Searching over List
    void search(int value){
        if(head == NULL){
            cout<<"Linked List is empty\n";
            return;
        }

        Node* temp = head;
        while(temp->data != value && temp->next != NULL){
            temp = temp->next;
        }

        if(temp->next == NULL && temp->data != value){
            cout<<"Value "<<value<<" does not exist in the List.\n";
        } else{
            cout<<"Value "<<value<<" exist in the List.\n";
        }
    }

    //Display Elements
    void display(){
        if(head == NULL){
            cout<<"Linked List is empty\n";
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<temp->data<<" -> NULL\n";
    }
};

int main(){
    linkedList ll;

    int choice;
    
    while(true){
        cout<<"1. Display\n";
        cout<<"2. Add at Begin\n";
        cout<<"3. Add at Middle By Value\n";
        cout<<"4. Add at Middle By Position\n";
        cout<<"5. Add at End\n";
        cout<<"6. Delete at Begin\n";
        cout<<"7. Delete at Middle By Value\n";
        cout<<"8. Delete at Middle By Position\n";
        cout<<"9. Delete at End\n";
        cout<<"10. Search an element\n";
        cout<<"11. Exit\n";
        cout<<"Enter the choice : ";
        cin>>choice;
        if(choice == 1){
            ll.display();
            cout<<endl;
        } else if(choice == 2){
            int value;
            cout<<"Enter the value you want to add : ";
            cin>>value;
            ll.addFront(value);
            cout<<endl;
        } else if(choice == 3){
            int val, value;
            cout<<"Enter the value you want to add : ";
            cin>>val;
            cout<<"Enter the value for its addition : ";
            cin>>value;
            ll.addMiddleByValue(val, value);
            cout<<endl;
        } else if(choice == 4){
            int value, position;
            cout<<"Enter the value you want to add : ";
            cin>>value;
            cout<<"Enter the position for its addition : ";
            cin>>position;
            ll.addMiddleByPosition(value, position);
            cout<<endl;
        } else if(choice == 5){
            int value;
            cout<<"Enter the value you want to add : ";
            cin>>value;
            ll.addLast(value);
            cout<<endl;
        } else if(choice == 6){
            ll.deleteFront();
            cout<<endl;
        } else if(choice == 7){
            int value;
            cout<<"Enter the value you want to delete : ";
            cin>>value;
            ll.deleteByValue(value);
            cout<<endl;
        } else if(choice == 8){
            int position;
            cout<<"Enter the position you want to delete : ";
            cin>>position;
            ll.deleteByPosition(position);
            cout<<endl;
        } else if(choice == 9){
            ll.deleteEnd();
            cout<<endl;
        } else if(choice == 10){
            int value;
            cout<<"Enter the value you want to search : ";
            cin>>value;
            ll.search(value);
            cout<<endl;
        } else if(choice == 11){
            cout<<"Exit\n";
            break;
        } else{
            cout<<"Please Enter a valid choice.\n";
            cout<<endl;
        }
    }

/*
    ll.addFront(2);
    ll.addFront(1);
    ll.addLast(3);

    ll.display();

    ll.search(1);
    ll.search(2);
    ll.search(3);
    ll.search(4);

    ll.addMiddleByValue(4,1);
    ll.display();
    ll.addMiddleByValue(5,3);
    ll.display();
    ll.addMiddleByValue(6,1);
    ll.display();

    ll.addMiddleByPosition(10,1);
    ll.addMiddleByPosition(11,1);
    ll.addMiddleByPosition(12,1);
    ll.addMiddleByPosition(13,-5);
    ll.addMiddleByPosition(14,15);
    ll.display();

    ll.deleteFront();
    ll.deleteFront();
    ll.deleteFront();
    ll.display();

    ll.deleteEnd();
    ll.deleteEnd();
    ll.display();

    ll.deleteByValue(4);
    ll.display();

    ll.deleteByPosition(1);
    ll.deleteByPosition(1);
    ll.display();
*/

    return 0;
}