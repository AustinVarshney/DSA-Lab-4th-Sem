#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Graph{
    int V;
    int matrix[100][100];

public:
    Graph(int vertices){
        V = vertices;
    }

    void addEdge(int u, int v){
        matrix[u][v] = 1;
    }

    void display(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void transpose(){
        for(int i=0; i<V; i++){
            for(int j=i; j<V; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        cout<<"After transposing, we get : \n";
        display();
    }
};

int main(){
    freopen("output6-1.txt", "w", stdout); // Redirect cout to output.txt (All outputs will be stored there)

    Graph g(5);
    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(0,3);
    // g.addEdge(3,2);
    // g.addEdge(3,4);
    // g.addEdge(0,4);

    // g.display();

    // g.transpose();
    #include "input6-1.h"   //Inserting the function calls from another file to here. 

    return 0;
}