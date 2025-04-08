#include <iostream>
using namespace std;

const int MAX = 100;
const int INF = 20000;

int main()
{
    int n = 7;

    int graph[MAX][MAX];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            graph[i][j] = (i == j) ? 0 : INF;

    graph[0][1] = 10;
    graph[1][0] = 10;

    graph[0][2] = 18;
    graph[2][0] = 18;

    graph[1][2] = 6;
    graph[2][1] = 6;

    graph[2][3] = 70;
    graph[3][2] = 70;

    graph[1][4] = 20;
    graph[4][1] = 20;

    graph[4][5] = 10;
    graph[5][4] = 10;

    graph[4][6] = 10;
    graph[6][4] = 10;

    graph[5][6] = 5;
    graph[6][5] = 5;

    bool visited[n]{false};

    int Distance_TV[n];
    for(int i=0; i<n; i++){
        Distance_TV[i] = INF;
    }

    int Nbr_TV[n];
    for(int i=0; i<n; i++){
        Nbr_TV[i] = -1;
    }

    int* TE = nullptr;
    int oldSize = 0;

    int stIdx = 0;

    for(int j=0; j<n; j++){
        Nbr_TV[j] = 0;
        Distance_TV[j] = graph[0][j];
    }

    for(int i=1; i<n; i++){
        int idx = -1;
        for(int j=0; j<n; j++){
            if(!visited[j] && (idx == -1 || Distance_TV[j] < Distance_TV[idx])){
                idx = j;
            }
        }
        if (idx == -1) break;

        visited[idx] = true;

        int newSize = oldSize + 1;
        int* newArr = new int[newSize];
        for (int i = 0; i < oldSize; ++i)
            newArr[i] = TE[i];

        newArr[newSize - 1] = graph[idx][Nbr_TV[idx]];
        delete[] TE;
        TE = newArr;
        oldSize = newSize;

        for(int j=0; j<n; j++){
            if((Distance_TV[j]>graph[idx][j]) && visited[j] == false){
                Distance_TV[j] = graph[idx][j];
                Nbr_TV[j] = idx;
            }
        }
    }

    cout<<"Distance array : ";
    for(int i=0; i<n; i++){
        cout<<Distance_TV[i]<<" ";
    }
    cout<<endl;

    cout<<"Nbr_TV array : ";
    for(int i=0; i<n; i++){
        cout<<Nbr_TV[i]<<" ";
    }
    cout<<endl;

    delete[] TE;

    return 0;
}