#include<iostream>
#include<cstdlib> //For rand(), srand()
#include<ctime>     //For time()
using namespace std;

void randomNums(int* arr, int size){
    for(int i=0; i<size; i++){
        srand(time(0));
        int j = rand()%5;

        swap(arr[i], arr[j]);
    }

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n = 5;
    int* arr = new int[n];

    for(int i=0; i<n; i++){
        arr[i] = i+1;
    }

    randomNums(arr, n);

    
    
    return 0;
}