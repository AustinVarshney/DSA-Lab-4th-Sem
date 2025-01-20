#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of Array : ";
    cin>>n;
    vector<int> arr(n,0);

    for(int i=0; i<n; i++){
        cout<<"Enter the "<<i+1<<"th value :";
        cin>>arr[i];
    }

    int st = 0, end = n-1;

    cout<<"Before sorting : "<<endl;
    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;

    while(st<=end){
        if(arr[st] == 0 && arr[end] == 0){
            st++;
        } else if(arr[st] == 1 && arr[end] == 1){
            end--;
        } else if(arr[st] == 0 && arr[end] == 1){
            st++;
            end--;
        } else if(arr[st] == 1 && arr[end]==0){
            swap(arr[st], arr[end]);
            st++;
            end--;
        }
    }

    cout<<"After sorting : "<<endl;
    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}