#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class Graph{
    int V;
    int adjMat[10][10];
public:
    Graph(int vertices){
        V = vertices;
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                adjMat[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, int num){
        adjMat[u][v] = num;
    }

    void display(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cout<<adjMat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void ifPathExists(int s, int d, int& c, int* arr){
        if(adjMat[s][d] == 1){
            c = 1;
            cout<<s<<" "<<d<<endl;
            return;
        }

        
        for(int i=0; i<V; i++){
            if(s != i){
                if(adjMat[s][i] == 1){
                    if(arr[i] == 1){
                        return;
                    }
                    arr[i] = 1;
                    if(c==1){
                        return;
                    }
                    cout<<s<<" "<<i<<endl;
                    ifPathExists(i, d, c, arr);
                }
            }
        }
    }
};

int main(){
    ifstream inputFile("input7.txt");

    if(!inputFile){
        cerr<<"Error with Input file.\n";
        return 1;
    }

    Graph g(5);

    int u=0;
    string line;

    while(getline(inputFile, line)){
        stringstream ss(line);
        int num = 0;
        for(int v=0; v<5; v++){
            ss>>num;
            g.addEdge(u,v,num);
        }
        u++;
    }

    g.display();

    int src, dest;
    cout<<"Enter the source : ";
    cin>>src;
    cout<<"Enter the destination : ";
    cin>>dest;

    int check=0;
    int arr[5]{0};
    g.ifPathExists(src, dest, check, arr);

    if(check == 1){
        cout<<"Path Exists.\n";
    } else{
        cout<<"Path Does not exists.\n";
    }

    return 0;
}