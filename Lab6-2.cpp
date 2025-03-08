#include<iostream>
using namespace std;

class Graph{
    int V;
    int adjList[100][100];
    int mat[100][100];

public:
    Graph(int vertices){
        V = vertices;
        int data;
        for(int i=0; i<V; i++){
            cout<<"Enter the "<<i+1<<"th data : ";
            cin>>data;
            adjList[i][0] = data;
        }

        for(int i=0; i<V; i++){
            adjList[i][1] = 0;
        }
        cout<<endl;
    }

    void addEdge(int n1, int n2){
        int p1 = -1, p2 = -1;

        //For finding the index of first value
        for(int i=0; i<V; i++){
            if (adjList[i][0] == n1){
                p1 = i;
            }
        }

        //For finding the index of second value
        for(int i=0; i<V; i++){
            if (adjList[i][0] == n2){
                p2 = i;
            }
        }

        int idx = adjList[p1][1]+2;
        adjList[p1][idx] = n2;
        adjList[p1][1]++;

        mat[p1][p2] = 1;
    }

    void display(){
        for(int i=0; i<V; i++){
            cout<<adjList[i][0]<<" -> ";
            for(int j=2; j<V+2; j++){
                if(adjList[i][j] == 0){
                    break;
                }
                cout<<adjList[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void displayMat(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void transpose(){
        for(int i=0; i<V; i++){
            for(int j=i; j<V; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        cout<<"After transposing, we get : \n";
        displayMat();

        for(int i=0; i<V; i++){
            for(int j=1; j<V+2; j++){
                adjList[i][j] = 0;
            }
        }

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(mat[i][j] == 1){
                    int idx = adjList[i][1] + 2;
                    adjList[i][idx] = adjList[j][0];
                    adjList[i][1]++;
                }
            }
        }

        display();
    }
};

int main(){
    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.addEdge(1,5);

    g.display();

    cout<<"Original Matrix : "<<endl;
    g.displayMat();

    g.transpose();
    return 0;
}