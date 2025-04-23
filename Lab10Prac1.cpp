#include<iostream>
#include<queue>
using namespace std;

static int count = 0;

class Graph{
    int V;
    int** g;
    
public:
    Graph(int vertices){
        V = vertices;
        g = new int*[V];
        for(int i=0; i<V; i++){
            g[i] = new int[V];
            for(int j=0; j<V; j++){
                g[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v){
        g[u][v] = 1;
        g[v][u] = 1;
    }

    void display(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void BFS(int s){
        bool visited[V]{false};
        queue<int> q;
        
        q.push(s);
        visited[s] = true;
        count++;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            // cout<<node<<" ";

            
            for(int j=0; j<V; j++){
                if(!visited[j] && g[node][j] == 1){
                    q.push(j);
                    visited[j] = true;
                    count++;
                }
            }
        }

        // cout<<"Count is : "<<count<<endl;
    }

    bool isBridgeEdge(){
        count = 0;
        BFS(0);
        if(count == V){
            return false;
        } else{
            return true;
        }
    }

    int bridge(){
        for(int i=0; i<V; i++){
            for(int j=i; j<V; j++){
                if(g[i][j] == 1){
                    g[i][j] = 0;
                    g[j][i] = 0;
                    if(isBridgeEdge()){
                        cout<<i<<" <-> "<<j<<endl;
                        cout<<"Bridge is present\n";
                        return 1;
                    }
                    g[i][j] = 1;
                    g[j][i] = 1;
                }
            }
        }

        cout<<"Bridge is not present\n";
        return -1;
    }
};

int main(){
    Graph g(12);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,6);
    g.addEdge(4,5);
    g.addEdge(6,5);
    g.addEdge(7,5);
    g.addEdge(2,8);
    g.addEdge(9,8);
    g.addEdge(10,8);
    g.addEdge(11,9);
    g.addEdge(11,10);

    g.display();

    g.BFS(0);

    g.bridge();

    return 0;
}