#include<iostream>
using namespace std;

const int MAX = 100;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int adj[MAX][MAX] = {0};
    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // directed graph
    }

    // Compute adj^2
    int adj2[MAX][MAX] = {0};
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            for (int k = 0; k < V; ++k) {
                adj2[i][j] += adj[i][k] * adj[k][j];
            }
        }
    }

    // Construct G(V, E^2)
    cout << "\nEdges in G(V, E^2) (length-2 paths as edges):" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (adj2[i][j] > 0) {
                cout << i << " -> " << j << endl;
            }
        }
    }

    return 0;
}
