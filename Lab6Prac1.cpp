#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int V;           // Number of vertices
    int **adjMatrix; // Adjacency Matrix

public:
    // Constructor to initialize the adjacency matrix
    Graph(int vertices)
    {
        V = vertices;
        adjMatrix = new int *[V];
        for (int i = 0; i < V; i++)
        {
            adjMatrix[i] = new int[V]{0}; // Initialize all elements to 0
        }
    }

    // Function to add an edge
    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Remove for a directed graph
    }

    // Function to create a graph by taking user input
    void createGraph()
    {
        int edges;
        cout << "Enter the number of edges: ";
        cin >> edges;

        cout << "Enter edges (u v) format:\n";
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        }
    }

    // Function to display the adjacency matrix
    void displayGraph()
    {
        cout << "Graph representation (Adjacency Matrix):\n";
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Depth-First Search (DFS) Traversal
    void DFSUtil(int vertex, vector<bool> &visited)
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[vertex][i] == 1 && !visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // Cycle Detection in an Undirected Graph using DFS
    bool isCyclicUtil(int vertex, bool visited[], int parent)
    {
        visited[vertex] = true;

        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[vertex][i] == 1)
            {
                if (!visited[i])
                {
                    if (isCyclicUtil(i, visited, vertex))
                        return true;
                }
                else if (i != parent)
                {
                    // If visited and not parent, it's a cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclic()
    {
        bool *visited = new bool[V]{false};

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (isCyclicUtil(i, visited, -1))
                {
                    delete[] visited;
                    return true;
                }
            }
        }

        delete[] visited;
        return false;
    }

    void DFSForAllCycles(int vertex, bool visited[], int parent, int path[], int pathIdx)
    {
        visited[vertex] = true;
        path[pathIdx] = vertex;
        pathIdx++;

        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[vertex][i] == 1)
            {
                if (!visited[i])
                {
                    DFSForAllCycles(i, visited, vertex, path, pathIdx);
                }
                else if (i != parent)
                {
                    // Cycle detected
                    cout << "Cycle detected: ";
                    // Print cycle from 'i' to current vertex in path
                    for (int j = pathIdx - 1; j >= 0; j--)
                    {
                        cout << path[j] << " ";
                        if (path[j] == i)
                            break;
                    }
                    cout << i << endl;
                }
            }
        }
    }

    void detectAllCycles()
    {
        bool *visited = new bool[V]{false};
        int *path = new int[V];

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFSForAllCycles(i, visited, -1, path, 0);
            }
        }

        delete[] visited;
        delete[] path;
    }

    bool isBipartiteDFS(int node, int color[], int currentColor)
    {
        color[node] = currentColor;

        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[node][i] == 1)
            {
                if (color[i] == -1)
                {
                    if (!isBipartiteDFS(i, color, 1 - currentColor))
                        return false;
                }
                else if (color[i] == color[node])
                {
                    return false; // Adjacent node has same color — not bipartite
                }
            }
        }

        return true;
    }

    bool isBipartite()
    {
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!isBipartiteDFS(i, color, 0))
                    return false;
            }
        }

        return true;
    }

    // Breadth-First Search (BFS) Traversal
    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int i = 0; i < V; i++)
            {
                if (adjMatrix[vertex][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Graph()
    {
        for (int i = 0; i < V; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main()
{
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

    cout << "\nDetecting all cycles:\n";
    g.detectAllCycles();

    // g.isCyclic();

    return 0;
}
