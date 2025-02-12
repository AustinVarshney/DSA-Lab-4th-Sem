#include<iostream>
#include<vector>
using namespace std;

int maximumOccurenceMaxIdx(vector<int> vec, int value){
    int st = 0, end = vec.size()-1;
    int maxIdx;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(vec[mid] < value){
            st = mid+1;
        } else if(vec[mid] > value){
            end = mid-1;
        } else{
            if(mid == vec.size()-1){
                maxIdx = mid;
                return mid;
            } else{
                if(vec[mid+1] == value){
                    maxIdx = mid;
                    st = mid+1;
                } else{
                    maxIdx = mid;
                    return mid;
                }
            }
        }
    }

    return maxIdx;
}

int maximumOccurenceMinIdx(vector<int> vec, int value){
    int st = 0, end = vec.size()-1;
    int minIdx = -1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(vec[mid] < value){
            st = mid+1;
        } else if(vec[mid] > value){
            end = mid-1;
        } else{
            if(mid == 0){
                minIdx = 0;
                return mid;
            } else{
                if(vec[mid-1] == value){
                    minIdx = mid;
                    end = mid-1;
                } else{
                    minIdx = mid;
                    return mid;
                }
            }
        }
    }

    return minIdx;
}

int main(){
    vector<int> vec = {0,0,0,1,2,2,2,2,2,2,2,5,6};
    int value = 2;
    int minIdx = maximumOccurenceMinIdx(vec, value);
    

    if(minIdx == -1){
        cout<<"Element is not present.\n";
    } else{
        int maxIdx = maximumOccurenceMaxIdx(vec, value);
        cout<<"Result is : "<<maxIdx - minIdx + 1<<endl;
    }
    return 0;
}