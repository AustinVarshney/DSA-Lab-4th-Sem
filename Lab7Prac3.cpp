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

    void display(ostream& out){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                out<<matrix[i][j]<<" ";
            }
            out<<endl;
        }
        out<<endl;
    }

    void transpose(ofstream& out){
        for(int i=0; i<V; i++){
            for(int j=i; j<V; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        out<<"After transposing, we get : \n";
        display(out);
    }
};

int main(){
    ifstream inputfile("input7-3.txt");
    ofstream outputfile("output7-3.txt");
    // freopen("output7-3.txt", "w", stdout);

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
            g.display(outputfile);
        }
        else if (command == "TRANSPOSE") { // Example: TRANSPOSE
            g.transpose(outputfile);
        }
        else {
            cout << "Unknown command: " << line << endl;
        }
    }

    inputfile.close();

    return 0;
}