#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency List

public:
    // Constructor to initialize adjacency list
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    // Function to add an edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove for a directed graph
    }

    // Function to create graph by taking input from user
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

    // Function to display the adjacency list
    void displayGraph() {
        cout << "Graph representation (Adjacency List):\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";
            for(int j=0; j<adjList[i].size(); j++)
                cout << adjList[i][j] << " ";
            cout << endl;
        }
    }

    // Depth-First Search (DFS) Traversal
    void DFSUtil(int vertex, vector<bool> &visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
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

            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Topological Sorting (Kahn's Algorithm for Directed Graphs)
    void topologicalSort() {
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++) {
            // for (int neighbor : adjList[i]) {
            //     inDegree[neighbor]++;
            // }
            for(int j=0; j<adjList[i].size(); j++){
                inDegree[adjList[i][j]]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        cout << "Topological Sort: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            // for (int neighbor : adjList[node]) {
            //     if (--inDegree[neighbor] == 0) {
            //         q.push(neighbor);
            //     }
            // }
            for(int j=0; j<adjList[node].size(); j++){
                inDegree[adjList[node][j]]--;
                if(inDegree[adjList[node][j]] == 0){
                    q.push(adjList[node][j]);
                }
            }
        }
        cout << endl;
    }

    // Cycle Detection (Using DFS)
    bool hasCycleUtil(int v, vector<bool> &visited, int parent) {
        visited[v] = true;

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                if (hasCycleUtil(neighbor, visited, v))
                    return true;
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    bool hasCycle() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i] && hasCycleUtil(i, visited, -1))
                return true;
        }
        return false;
    }

    // Check if a path exists between two vertices (Using BFS)
    bool isPathExists(int start, int end) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == end)
                return true;

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
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

    // Check for cycle
    if (g.hasCycle())
        cout << "Cycle exists in the graph.\n";
    else
        cout << "No cycle in the graph.\n";

    // Check if a path exists between two nodes
    int u, v;
    cout << "Enter two vertices to check if a path exists: ";
    cin >> u >> v;
    if (g.isPathExists(u, v))
        cout << "Path exists between " << u << " and " << v << ".\n";
    else
        cout << "No path exists between " << u << " and " << v << ".\n";

    return 0;
}
