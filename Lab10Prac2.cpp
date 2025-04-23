#include<iostream>
#include<queue>
using namespace std;

static int count = 0;

class Graph{
    int V;
    int** g;
    int** g2;
    
public:
    Graph(int vertices){
        V = vertices;
        g = new int*[V];
        g2 = new int*[V];
        for(int i=0; i<V; i++){
            g[i] = new int[V];
            g2[i] = new int[V];
            for(int j=0; j<V; j++){
                g[i][j] = 0;
                g2[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v){
        g[u][v] = 1;
        g[v][u] = 1;
        g2[u][v] = 1;
        g2[v][u] = 1;
    }

    void displayG1(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void displayG2(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cout<<g2[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void copyGraph(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                g2[i][j] = g[i][j];
            }
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
                if(!visited[j] && g2[node][j] == 1){
                    q.push(j);
                    visited[j] = true;
                    count++;
                }
            }
        }

        // cout<<"Count is : "<<count<<endl;
    }

    bool isArtPoint(int src){
        count = 0;
        BFS(src);
        if(count == V-1){
            return false;
        }else{
            return true;
        }
    }

    int ArtPoint(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(g[i][j] == 1){
                    g2[i][j] = 0;
                    g2[j][i] = 0;
                }
            }
    
            if(isArtPoint(i+1)){
                cout<<i<<" is the Art Point\n";
                return 1;
            }
    
            copyGraph();
        }

        return -1;
    }
};

int main(){
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(4,1);
    g.addEdge(1,6);
    g.addEdge(3,5);
    g.addEdge(5,4);

    g.displayG2();

    // g.BFS(0);

    g.ArtPoint();

    return 0;
}