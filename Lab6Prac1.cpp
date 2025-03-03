#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V; // Number of vertices
    int **adjMatrix; // Adjacency Matrix

public:
    // Constructor to initialize the adjacency matrix
    Graph(int vertices) {
        V = vertices;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V]{0}; // Initialize all elements to 0
        }
    }

    // Function to add an edge
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Remove for a directed graph
    }

    // Function to create a graph by taking user input
    void createGraph() {
        int edges;
        cout << "Enter the number of edges: ";
        cin >> edges;

        cout << "Enter edges (u v) format:\n";
        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        }
    }

    // Function to display the adjacency matrix
    void displayGraph() {
        cout << "Graph representation (Adjacency Matrix):\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Depth-First Search (DFS) Traversal
    void DFSUtil(int vertex, vector<bool> &visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < V; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // Breadth-First Search (BFS) Traversal
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int i = 0; i < V; i++) {
                if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Graph() {
        for (int i = 0; i < V; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);
    g.createGraph();
    g.displayGraph();

    int startNode;
    cout << "Enter starting node for DFS and BFS: ";
    cin >> startNode;

    g.DFS(startNode);
    g.BFS(startNode);

    return 0;
}
