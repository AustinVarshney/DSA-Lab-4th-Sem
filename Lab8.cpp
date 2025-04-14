#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX = 100;

//Adding the edge
void addEdge(int idx1, int idx2, int graph[100][100], int size){
    graph[idx1][idx2] = 1;
    graph[idx2][idx1] = 1;
}

//Displaying the arrays
void displayArr1(int* arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void displayArr2(char* arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void displayGraph(int graph[100][100], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Finding the idx from the array
int findIdx1(int* arr, int size, int num){
    for(int i=0; i<size; i++){
        if(arr[i] == num - 48){
            return i;
        }
    }
    return -1;
}

int findIdx2(char* arr, int size, char c){
    for(int i=0; i<size; i++){
        if(arr[i] == c){
            return i;
        }
    }
    return -1;
}

int main(){ 
    ifstream inputFile("input8.txt");

    if(!inputFile){
        cerr<<"Input file not found"<<endl;
        return 1;
    }

    int v1, v2, e1, e2;

    int graph1[MAX][MAX];
    int graph2[MAX][MAX];

    int* arr1;
    char* arr2;

    string line;
    while(getline(inputFile, line)){
        if(line[0] == 'V' && line[1] == '1'){
            int len = line.length();
            int start = 4;
            v1 = ((len - 5) / 2) + 1;
            for(int i=0; i<v1; i++){
                for(int j=0; j<v1; j++){
                    graph1[i][j] = 0;
                }
            }

            arr1 = new int[v1];
            for(int i=0; i<v1; i++){
                arr1[i] = line[start] - 48;
                start += 2;
            }            

        } else if(line[0] == 'E' && line[1] == '1'){
            int len = line.length();
            e1 = ((len - 5) / 6) + 1;
            int start = 5;
            for(int i=0; i<e1; i++){
                int u = line[start], v=line[start+2];
                start += 6;
                int idx1 = findIdx1(arr1, v1, u), idx2 = findIdx1(arr1, v1, v);
                addEdge(idx1, idx2, graph1, v1);
            }

            displayGraph(graph1, v1);

        } else if(line[0] == 'V' && line[1] == '2'){
            int len = line.length();
            int start = 4;
            v2 = ((len - 5) / 2) + 1;
            for(int i=0; i<v2; i++){
                for(int j=0; j<v2; j++){
                    graph2[i][j] = 0;
                }
            }

            arr2 = new char[v2];
            for(int i=0; i<v2; i++){
                arr2[i] = line[start];
                start += 2;
            }

        } else if(line[0] == 'E' && line[1] == '2'){
            int len = line.length();
            e2 = ((len - 5) / 6) + 1;
            int start = 5;
            for(int i=0; i<e2; i++){
                char u = line[start], v=line[start+2];
                start += 6;
                int idx1 = findIdx2(arr2, v2, u), idx2 = findIdx2(arr2, v2, v);
                addEdge(idx1, idx2, graph2, v2);
            }

            displayGraph(graph2, v2);
            
        }
    }

    delete[] arr1;
    delete[] arr2;

    return 0;
}