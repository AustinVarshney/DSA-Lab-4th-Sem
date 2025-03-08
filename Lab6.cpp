#include<iostream>
using namespace std;

class Graph{
    int V;
    char adjList[100][100];

public:
    Graph(int vertices){
        V = vertices;
        for(int i=0; i<V; i++){
            char str;
            cout<<"Enter the "<<i+1<<"th character : ";
            cin>>str;
            adjList[i][0] = str;
        }
    }

    void addEdge(char string1, char string2){
        int node1, node2;

        for(int i=0; i<V; i++){
            if(adjList[i][0] == string1){
                node1 = i;
            }
        }

        for(int i=0; i<V; i++){
            if(adjList[i][0] == string2){
                node2 = i;
            }
        }
        
        int node1EndIdx = 0;
        for(int j=1; j<=V; j++){
            node1EndIdx++;
            if(adjList[node1][j] == 0){
                break;
            }
        }

        adjList[node1][node1EndIdx] = string2;
    }

    void display(){
        for(int i=0; i<V; i++){
            cout<<adjList[i][0]<<" -> ";
            for(int j=1; j<V; j++){
                if(adjList[i][j] == 0){
                    break;
                }
                cout<<adjList[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    Graph g(5);
    g.addEdge('A','B');
    g.addEdge('A','D');
    g.addEdge('B','C');
    g.addEdge('D','C');
    g.addEdge('D','E');

    g.display();
    return 0;
}