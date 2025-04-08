#include<iostream>
using namespace std;

const int MAX = 100;
const int INF = 20000;

int main(){
    int n=4;

    int graph[MAX][MAX];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }


    graph[0][2] = 2;
    graph[0][3] = 4;
    graph[1][0] = 3;
    graph[1][3] = 10;
    graph[2][3] = 1;
    graph[3][0] = 6;
    graph[3][1] = 4;

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}