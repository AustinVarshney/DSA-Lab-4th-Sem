#include<iostream>
#include<vector>
using namespace std;

int majorityEle(vector<int> vec, int n){
    int ans = vec[0], count = 1; 
    for(int i=1; i<n; i++){             //Loop-1
        if(count == 0){
            count = 1;
            ans = vec[i];
            continue;
        }
        if(vec[i] == ans){
            count++;
        } else{
            count--;
        }
    }
    
    int countOfAns = 0;
    for(int i=0; i<n; i++){             //Loop-2
        if(vec[i] == ans){
            countOfAns++;
        }
    }

    if(countOfAns >= n / 2 + 1){
        return ans;
    } else{
        return -1;
    }
}

int main(){
    vector<int> vec = {1,1,1,2,3,8,4,1};
    int n = vec.size();
    int ans = majorityEle(vec, n);
    cout<<"Answer is : "<<ans<<endl;
    return 0;
}