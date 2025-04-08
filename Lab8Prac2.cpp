#include <iostream>
#include <map>
using namespace std;

int main() {
    const int MAX = 20000;
    map<int, map<int, int>> graph;

    int size = 7;

    // Add weighted edges
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

    // // Access and print weights
    // for (auto& u : graph) {
    //     for (auto& v : u.second) {
    //         cout << "Edge from " << u.first << " to " << v.first
    //              << " has weight " << v.second << endl;
    //     }
    // }

    bool visited[size];
    for(int i=0; i<size; i++){
        visited[i] = false;
    }

    int Distance[size];
    for(int i=0; i<size; i++){
        Distance[i] = MAX;
    }

    int stIdx = 0;
    Distance[stIdx] = 0;

    for(int i=0; i<size; i++){
        //Finding the vertex which is unvisited
        int idx = -1;
        for(int j = 0; j < size; j++) {
            if(!visited[j] && (idx == -1 || Distance[j] < Distance[idx])) {
                idx = j;
            }
        }

        //Additional check
        if (idx == -1) break;

        //Marking the unvisited idx as visited
        visited[idx] = true;

        //Updating the distance
        for(auto& u : graph[idx]){
            if(visited[u.first] == false){
                if(Distance[u.first] > Distance[idx]+u.second){
                    Distance[u.first] = Distance[idx]+u.second;
                }
            }
        }
    }

    for(int i=0; i<size; i++){
        cout<<Distance[i]<<" ";
    }
    cout<<endl;

    return 0;
}