#include <iostream>
using namespace std;

const int MAX = 100;
const int INF = 20000;

int main() {
    int n = 7;

    int graph[MAX][MAX];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            graph[i][j] = (i == j) ? 0 : INF;

    // Adding weighted edges manually (or take from user)
    graph[0][1] = 10;
    graph[1][0] = 10;

    graph[0][2] = 80;
    graph[2][0] = 80;

    graph[1][2] = 6;
    graph[2][1] = 6;

    graph[2][3] = 70;
    graph[3][2] = 70;

    graph[1][4] = 20;
    graph[4][1] = 20;

    graph[4][5] = 50;
    graph[5][4] = 50;

    graph[4][6] = 10;
    graph[6][4] = 10;

    graph[5][6] = 5;
    graph[6][5] = 5;

    bool visited[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    int Distance[n];
    for(int i=0; i<n; i++){
        Distance[i] = INF;
    }

    int stIdx = 1;
    Distance[stIdx] = 0;

    for(int i=0; i<n; i++){
        //Finding the vertex which is unvisited
        int idx = -1;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && (idx == -1 || Distance[j] < Distance[idx])) {
                idx = j;
            }
        }

        //Additional check
        if (idx == -1) break;

        //Marking the unvisited idx as visited
        visited[idx] = true;

        for(int j=0; j<n; j++){
            if((Distance[j]>Distance[idx]+graph[idx][j]) && visited[j] == false){
                Distance[j] = Distance[idx]+graph[idx][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<Distance[i]<<" ";
    }
    cout<<endl;

    return 0;
}