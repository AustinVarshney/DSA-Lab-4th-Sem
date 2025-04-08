#include<iostream>
using namespace std;

const int MAX = 100;
const int INF = 20000;

int main(){
    // int n=3;
    int n=5;

    int graph[MAX][MAX];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    // graph[0][1] = 10;
    // graph[1][2] = -20;
    // graph[0][2] = 5;


    // graph[0][1] = 10;
    // graph[1][2] = 20;
    // graph[2][1] = -15;


    graph[0][1] = 3;
    graph[0][2] = 5;
    graph[1][3] = 1;
    graph[2][3] = -3;
    graph[2][4] = 2;
    graph[3][4] = -2;


    int Distance1[n];
    int Distance2[n];
    for(int i=0; i<n; i++){
        Distance1[i] = INF;
    }

    int stIdx = 0;
    Distance1[stIdx] = 0;

    for(int k=0; k<n-1; k++){   //Relaxing the edges of the graph n-1 times
        //Relaxing the edges of the graph
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){ 
                if((i!=j) && (graph[i][j] != INF)){
                    if(Distance1[i] != INF && Distance1[i]+graph[i][j] < Distance1[j]){
                        Distance1[j] = Distance1[i] + graph[i][j];
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        Distance2[i] = Distance1[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){ 
            if((i!=j) && (graph[i][j] != INF)){
                if(Distance2[i]+graph[i][j] < Distance2[j]){
                    Distance2[j] = Distance2[i] + graph[i][j];
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        if(Distance1[i] != Distance2[i]){
            cout<<"-ve Cycle detects";
            return 1;
        }
    }

    cout<<"Distance Array is : ";
    for(int i=0; i<n; i++){
        cout<<Distance1[i]<<" ";
    }
    cout<<endl;

    return 0;
}