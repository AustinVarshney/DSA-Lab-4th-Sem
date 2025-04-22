#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <fstream>
#include <climits>
#include <sstream>
using namespace std;

class Node
{
public:
    int data;
    int wt;
    Node *next;

    Node(int data, int wt)
    {
        this->wt = wt;
        this->data = data;
        this->next = NULL;
    }

    Node(int data, int wt, Node *next) : data(data), wt(wt), next(next) {}
};

class LinkedList
{
    Node *tail = NULL;

public:
    Node *head = NULL;
    void addLast(int data, int wt)
    {
        Node *newNode = new Node(data, wt);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void display()
    {
        Node *temp = head;
        if (!temp)
        {
            cout << "No edges";
        }

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

class Edge
{
public:
    int src;
    int dest;
    // int wt;

    Edge(int src, int dest, int wt)
    {
        this->src = src;
        this->dest = dest;
        // this->wt = wt;
    }
};

class Graph
{
    int V;
    LinkedList *adjList;

public:
    Graph(int V)
    {
        this->V = V;
        adjList = new LinkedList[V];
    }

    void addEdge(int u, int v, int wt)
    {
        if (u >= V || v >= V)
        {
            cout << "Invalid Edge" << endl;
            return;
        }
        adjList[u].addLast(v, wt);
        adjList[v].addLast(u, wt);
    }

    void bfs(int src)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        queue<int> q;
        q.push(src);
        visited[src] = true;

        cout << "BFS Traversal : ";
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            Node *temp = adjList[curr].head;
            while (temp != NULL)
            {
                int neigh = temp->data;

                if (!visited[neigh])
                {
                    visited[neigh] = true;
                    q.push(neigh);
                }

                temp = temp->next;
            }
        }
        cout << endl;
        delete[] visited;
    }

    void dfsUtil(int src, bool visited[])
    {
        visited[src] = true;
        cout << src << " ";

        Node *temp = adjList[src].head;
        while (temp != NULL)
        {
            int neigh = temp->data;
            if (!visited[neigh])
            {
                dfsUtil(neigh, visited);
            }
            temp = temp->next;
        }
    }

    void dfs(int src)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        cout << "DFS Traversal : ";
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsUtil(i, visited);
            }
        }
        delete[] visited;
        cout << endl;
    }

    bool hasPath(int src, int dest, bool visited[])
    {
        if (src == dest)
        {
            return true;
        }

        visited[src] = true;
        Node *temp = adjList[src].head;
        while (temp != NULL)
        {

            int neigh = temp->data;
            if (!visited[neigh] && hasPath(neigh, dest, visited))
            {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    bool cycleDetect(int src, bool visited2[], int par)
    {
        visited2[src] = true;

        Node *temp = adjList[src].head;
        while (temp != NULL)
        {
            int neigh = temp->data;
            if (visited2[neigh] && neigh != par)
            {
                return true;
            }
            else if (!visited2[neigh])
            {
                if (cycleDetect(neigh, visited2, src))
                {
                    return true;
                }
            }

            temp = temp->next;
        }
        return false;
    }

    bool isBipartite()
    {
        bool *visited = new bool[V]{false};
        int *color = new int[V];
        for (int i = 0; i < V; i++)
        {
            color[i] = -1;
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (!isBipartiteUtil(i, visited, color, 0))
                {
                    delete[] visited;
                    delete[] color;
                    return false;
                }
            }
        }

        delete[] visited;
        delete[] color;
        return true;
    }

    bool isBipartiteUtil(int src, bool visited[], int color[], int currColor)
    {
        visited[src] = true;
        color[src] = currColor;

        Node *temp = adjList[src].head;
        while (temp != NULL)
        {
            int neigh = temp->data;
            if (color[neigh] == -1)
            {
                if (!isBipartiteUtil(neigh, visited, color, 1 - currColor))
                {
                    return false;
                }
            }
            else
            {
                if (color[neigh] == color[src])
                {
                    return false;
                }
            }
            temp = temp->next;
        }

        return true;
    }

    bool cycleDetectDirected()
    {
        bool *visited = new bool[V]{false};
        int *s = new int[V];

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (!cycleDetectDirectedUtil(visited, s, i))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool cycleDetectDirectedUtil(bool visited[], int s[], int src)
    {
        visited[src] = true;
        s[src] = true;

        Node *temp = adjList[src].head;
        while (temp != NULL)
        {
            int neigh = temp->data;
            if (s[neigh])
            {
                return true;
            }

            if (!visited[neigh] && cycleDetectDirectedUtil(visited, s, neigh))
            {
                return true;
            }
            temp = temp->next;
        }

        s[src] = false;
        return false;
    }

    void topologicalSort()
    {
        bool *visited = new bool[V];
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topologicalSortUtil(visited, i, s);
            }
        }

        cout << "Topological Sort : ";
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        delete[] visited;
        cout << endl;
    }

    void topologicalSortUtil(bool visited[], int src, stack<int> &s)
    {
        visited[src] = true;

        Node *temp = adjList[src].head;
        while (temp != NULL)
        {
            int neigh = temp->data;
            if (!visited[neigh])
            {
                topologicalSortUtil(visited, neigh, s);
            }

            temp = temp->next;
        }
        s.push(src);
    }

    void callInDeg(int inDeg[])
    {
        for (int i = 0; i < V; i++)
        {
            Node *temp = adjList[i].head;
            while (temp != NULL)
            {
                inDeg[temp->data]++;
                temp = temp->next;
            }
        }
    }

    void kahnAlgo()
    {
        int *inDeg = new int[V]{0};
        callInDeg(inDeg);

        cout << "Indegree : ";
        for (int i = 0; i < V; i++)
        {
            cout << inDeg[i] << " ";
        }
        cout << endl;

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (inDeg[i] == 0)
            {
                q.push(i);
            }
        }

        cout << "Kahn's Algo TopoSort : ";
        while (!q.empty())
        {
            int curr = q.front();
            cout << curr << " ";
            q.pop();

            Node *temp = adjList[curr].head;
            while (temp != NULL)
            {
                int neigh = temp->data;
                --inDeg[neigh];

                if (inDeg[neigh] == 0)
                {
                    q.push(neigh);
                }
                temp = temp->next;
            }
        }
        cout << endl;
        delete[] inDeg;
    }

    void allPath(int src, int dest, string path)
    {
        if (src == dest)
        {
            cout << path + to_string(dest) << endl;
        }

        Node *temp = adjList[src].head;
        while (temp != NULL)
        {
            int neigh = temp->data;
            allPath(neigh, dest, path + to_string(src));

            temp = temp->next;
        }
    }

    class Pair
    {
    public:
        int vertex;
        int dist;
        int parent;

        Pair(int vertex, int weight) : vertex(vertex), dist(weight) {}

        Pair(int vertex, int dist, int parent)
        {
            this->parent = parent;
            this->vertex = vertex;
            this->dist = dist;
        }

        bool operator<(const Pair &other) const
        {
            return this->dist > other.dist; // change maxHeap -> minHeap
        }
    };

    struct AdjList
    {
        Node *head;
    };

    void dijkstra(int src)
    {
        int *dist = new int[V];
        dist[src] = 0;
        for (int i = 0; i < V; i++)
        {
            if (i != src)
            {
                dist[i] = INT_MAX;
            }
        }

        bool *visited = new bool[V]{false};
        priority_queue<Pair> q;
        q.push(Graph::Pair(src, 0));

        while (!q.empty())
        {
            Pair curr = q.top();
            q.pop();
            int u = curr.vertex;

            if (!visited[u])
            {
                visited[u] = true;

                Node *temp = adjList[curr.vertex].head;
                while (temp != NULL)
                {
                    int v = temp->data;
                    int wt = temp->wt;
                    if (dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                        q.push(Graph::Pair(v, dist[v]));
                    }

                    temp = temp->next;
                }
            }
        }

        cout << "Dijkstra algo : ";
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " -> " << dist[i] << endl;
        }
        delete[] dist;
        delete[] visited;
    }

    void bellmanFord(int src)
    {
        int *dist = new int[V];
        dist[src] = 0;

        for (int i = 0; i < V; i++)
        {
            if (src != i)
            {
                dist[i] = INT_MAX;
            }
        }

        for (int i = 0; i < V - 1; i++)
        {
            for (int u = 0; u < V; u++)
            {
                Node *temp = adjList[u].head;
                while (temp != NULL)
                {
                    int v = temp->data;
                    int wt = temp->wt;

                    if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                    {
                        dist[v] = wt + dist[u];
                    }

                    temp = temp->next;
                }
            }
        }

        for (int u = 0; u < V; u++)
        {
            Node *temp = adjList[u].head;
            while (temp != NULL)
            {
                int v = temp->data;
                int wt = temp->wt;

                if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    cout << "Negative weight cycle detected!" << endl;
                    delete[] dist;
                    return;
                }

                temp = temp->next;
            }
        }

        cout << "Bellmand Ford Algo : ";
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " -> " << dist[i] << endl;
        }
    }

    void primsAlgo(int src)
    {
        AdjList adjList2[V];
        bool *visited = new bool[V]{false};
        priority_queue<Pair> pq;
        pq.push({src, 0, -1});

        int finalCost = 0;

        while (!pq.empty())
        {
            Pair curr = pq.top();
            pq.pop();

            int u = curr.vertex;
            int wt = curr.dist;
            int parent = curr.parent;

            if (!visited[curr.vertex])
            {
                visited[curr.vertex] = true;

                finalCost += curr.dist;

                if (parent != -1)
                {
                    Node *newNode1 = new Node{u, wt, adjList2[parent].head};
                    adjList2[parent].head = newNode1;

                    Node *newNode2 = new Node{parent, wt, adjList2[u].head};
                    adjList2[u].head = newNode2;
                }

                Node *temp = adjList[curr.vertex].head;
                while (temp != NULL)
                {
                    int neigh = temp->data;
                    int wt = temp->wt;
                    if (!visited[neigh])
                    {
                        pq.push({neigh, wt, u});
                    }

                    temp = temp->next;
                }
            }
        }

        cout << "Cost of MST : " << finalCost << endl;
        delete[] visited;
    }

    void display()
    {
        for (int i = 0; i < V; i++)
        {
            Node *temp = adjList[i].head;
            cout << i << " -> ";
            adjList[i].display();
            cout << endl;
        }
    }
};

int main()
{
    ifstream inputfile("input.txt");
    if (!inputfile)
    {
        cerr << "File does not exist" << endl;
        return 1;
    }

    int Vertices = 0, Edges = 0;
    int u = 0;
    Graph *g = nullptr;

    string keyword;
    while (inputfile >> keyword)
    {
        if (keyword == "vertices")
        {
            inputfile >> Vertices;
            g = new Graph(Vertices);
        }
        else if (keyword == "edges")
        {
            inputfile >> Edges;
            for (int i = 0; i < Edges; i++)
            {
                int u, v, wt;
                inputfile >> u >> v >> wt;
                g->addEdge(u, v, wt);
            }
        }
    }

    if (g)
    {
        g->display();
        g->primsAlgo(0);
    }
    // g.bfs(0);
    // g.dfs(0);

    // bool *visited = new bool[Vertices]{false};
    // cout << "Path exists : " << (g.hasPath(0, 3, visited) ? "Yes" : "No") << endl;
    // delete[] visited;

    // bool *visited2 = new bool[Vertices]{false};
    // cout << "Cycle Detected : " << (g.cycleDetect(0, visited2, -1) ? "Yes" : "No") << endl;
    // delete[] visited2;

    // cout << "IS Bipartitie : " << (g.isBipartite() ? "Yes" : "No") << endl;

    // cout << "isCycle in Directed Graph : " << (g.cycleDetectDirected() ? "Yes" : "No") << endl;
    // g.topologicalSort();
    // g.kahnAlgo();
    // g.allPath(5, 1, "");

    // g.dijkstra(0);

    // g.bellmanFord(0);

    return 0;
}