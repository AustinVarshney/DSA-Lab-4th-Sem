#include <iostream>
#include <map>
using namespace std;

int main() {                                    //How to add the weights with their edges
    map<int, map<int, int>> graph;

    // Add weighted edges
    graph[0][1] = 3;
    graph[0][2] = 5;
    graph[1][2] = 1;
    graph[2][3] = 2;

    // Access and print weights
    for (auto& u : graph) {
        for (auto& v : u.second) {
            cout << "Edge from " << u.first << " to " << v.first
                 << " has weight " << v.second << endl;
        }
    }

    return 0;
}


// #include <iostream>
// using namespace std;

// const int MAX = 100;
// const int INF = 1e9; // Representing no connection

// int main() {
//     int n; // number of vertices
//     cout << "Enter number of vertices: ";
//     cin >> n;

//     // Create and initialize adjacency matrix
//     int graph[MAX][MAX];

//     for (int i = 0; i < n; ++i)
//         for (int j = 0; j < n; ++j)
//             graph[i][j] = (i == j) ? 0 : INF;  // 0 for same vertex, INF otherwise

//     // Adding weighted edges manually (or take from user)
//     // Example: edge from 0 to 1 with weight 4
//     graph[0][1] = 4;
//     graph[0][2] = 2;
//     graph[1][2] = 5;
//     graph[1][3] = 10;
//     graph[2][3] = 3;

//     // Display adjacency matrix
//     cout << "\nAdjacency Matrix:\n";
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (graph[i][j] == INF) cout << "INF ";
//             else cout << graph[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

