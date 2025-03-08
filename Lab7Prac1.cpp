#include <iostream>
#include <fstream> // For file handling
#include <string>
using namespace std;

int main() {
    ifstream inputFile("input.txt");  // Open file for reading
    ofstream outputFile("output.txt"); // Open file for writing

    // Check if the input file is open
    if (!inputFile) {
        cerr << "Error: Unable to open input file!" << endl;
        return 1; // Exit with error
    }

    string line;
    
    // Read file line by line
    while (getline(inputFile, line)) {
        cout << "Read: " << line << endl; // Display on console
        outputFile << line << endl; // Write to output file
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Data processed and stored in output.txt!" << endl;

    return 0;
}
