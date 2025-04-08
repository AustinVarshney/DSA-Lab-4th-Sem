#include <iostream>
using namespace std;

int main() {
    int* arr = nullptr;
    int oldSize = 0;

    // Step 1: Allocate memory for 3 integers
    oldSize = 3;
    arr = new int[oldSize];

    // Step 2: Initial values
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    cout << "Initial array: ";
    for (int i = 0; i < oldSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Step 3: First Resize — increase size to 6
    int newSize = 6;
    int* newArr = new int[newSize];

    // Copy old values
    for (int i = 0; i < oldSize; ++i)
        newArr[i] = arr[i];

    // Add new values
    newArr[3] = 40;
    newArr[4] = 50;
    newArr[5] = 60;

    // Clean up and reassign
    delete[] arr;
    arr = newArr;
    oldSize = newSize;

    cout << "After first expansion: ";
    for (int i = 0; i < oldSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Step 4: Second Resize — increase size to 9
    newSize = 9;
    newArr = new int[newSize];

    // Copy current values
    for (int i = 0; i < oldSize; ++i)
        newArr[i] = arr[i];

    // Add more values
    newArr[6] = 70;
    newArr[7] = 80;
    newArr[8] = 90;

    // Clean up and reassign again
    delete[] arr;
    arr = newArr;
    oldSize = newSize;

    cout << "After second expansion: ";
    for (int i = 0; i < oldSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Final Cleanup
    delete[] arr;

    return 0;
}
