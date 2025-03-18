#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class linkedlist{
    Node* start;
public:
    linkedlist(){
        start = NULL;
    }

    void addNode(int val){
        Node* newlink = new Node;
        newlink->data = val;
        newlink->next = start;
        start = newlink;
    }

    void display(){
        Node* currentNode;
        currentNode = start;
        while(currentNode != NULL){
            cout<<currentNode->data<<" ";
            currentNode = currentNode->next;
        }
    }
};

class Graph{
    int v;

    linkedlist adjList[10];
    int adjMat[10][10];
    int dupAdjMat[10][10];

public:
    Graph(int v){
        this->v = v;
        for(int a=0; a<10; a++){
            for(int j=0; j<10; j++){
                adjMat[a][j] = 0;
                dupAdjMat[a][j] = 0;
            }
        }
    }

    void addEdge(int u, int v){
        adjList[u].addNode(v);
        adjMat[u][v] = 1;
    }

    void display(){
        cout<<"Adjacency List"<<endl;
        for(int i=0; i<v; i++){
            cout<<i<<" -> ";
            adjList[i].display();
            cout<<endl;
        }

        cout<<"Adjacency Matrix : "<<endl;
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(adjMat[i][j] == 1){
                    cout<<i<<" -> "<<j<<endl;
                }
            }
        }
    }

    void transpose(){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(i != j){
                    if(adjMat[i][j] == 1){
                        dupAdjMat[i][j] = 0;
                        dupAdjMat[j][i] = 1;
                    }
                }
            }
        }

        cout<<"Transpose Graph"<<endl;
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(dupAdjMat[i][j] == 1){
                    cout<<i<<" -> "<<j<<endl;
                }
            }
        }
    }
};

int main(){
    cout<<"1. Add Edge"<<endl;
    cout<<"2. Display"<<endl;
    cout<<"3. Transpose"<<endl;
    int choice;
    
    while(true){
        int vertex;
        cout<<"Enter the vertex : ";
        cin>>vertex;
        Graph g1(vertex);

        while(true){
            cout<<"Enter the choice : ";
            cin>>choice;

            if(choice == 1){
                bool var = true;
                while(var){
                    int src, des;
                    cout<<"Enter the source : "<<endl;
                    cin>>src;
                    cout<<"Enter the destination : "<<endl;
                    cin>>des;
                    g1.addEdge(src, des);
                    int x;
                    cout<<"Want to enter again ? ";
                    cin>>x;
                    if(x == 0){
                        var = false;
                    }                
                }
            } else if(choice == 2){
                g1.display();
            } else if(choice == 3){
                g1.transpose();
            } 
        }
    }
    return 0;
}