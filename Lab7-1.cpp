#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Graph{
    int V;
    int** adjMat;

public:
    Graph(int vertices){
        V = vertices;
        adjMat = new int*[V];

        for (int i = 0; i < V; ++i) {
            adjMat[i] = new int[V];
        }

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                adjMat[i][j] = 0;
            }
        }
    }

    void display(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cout<<adjMat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void addEdge(int idx1, int idx2){
        adjMat[idx1][idx2] = 1;
    }

    bool isDirected(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adjMat[i][j] == 1){
                    if(adjMat[j][i] == 1){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int VIdx(char c, char* arr, int Len){
    for(int i=0; i<Len; i++){
        if(arr[i] == c){
            return i;
        }
    }
}

int main(){
    ifstream inputFile("input7'.txt");

    if(!inputFile){
        cerr<<"Input File does not exist"<<endl;
        return 1;
    }

    string Vertices;
    inputFile>>Vertices;
    int VLen = Vertices.length();

    Graph g(VLen);

    char arr[VLen];

    for(int i=0; i<VLen; i++){
        arr[i] = Vertices[i];
    }

    string edges;
    inputFile>>edges;

    while(edges.length() != 0){
        int idx1 = VIdx(edges[0], arr, VLen);
        int idx2 = VIdx(edges[1], arr, VLen);
        g.addEdge(idx1, idx2);

        edges = "";
        inputFile>>edges;
    }

    cout<<"Matrix is : "<<endl;
    g.display();

    if(g.isDirected()){
        cout<<"Graph is Directed\n";
    }else{
        cout<<"Graph is not Directed\n";
    }
    
    return 0;
}