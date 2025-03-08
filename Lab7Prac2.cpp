#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

class Graph{
    int V;
    int matrix[100][100];

public:
    Graph(int vertices){
        V = vertices;
    }

    void addEdge(int u, int v){
        matrix[u][v] = 1;
    }

    void display(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void transpose(){
        for(int i=0; i<V; i++){
            for(int j=i; j<V; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        cout<<"After transposing, we get : \n";
        display();
    }
};

int main(){
    ifstream inputfile("input7-2.txt");
    freopen("output7-2.txt", "w", stdout);

    if (!inputfile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    Graph g(5); // Assuming graph size 5 (can be modified based on input file)

    while (getline(inputfile, line)) {
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "ADD") { // Example: ADD 0 1
            int u, v;
            ss >> u >> v;
            g.addEdge(u, v);
        }
        else if (command == "DISPLAY") { // Example: DISPLAY
            g.display();
        }
        else if (command == "TRANSPOSE") { // Example: TRANSPOSE
            g.transpose();
        }
        else {
            cout << "Unknown command: " << line << endl;
        }
    }

    inputfile.close();

    return 0;
}