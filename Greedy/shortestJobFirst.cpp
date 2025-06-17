#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Shortest job first 

the shudling policy to shudule the shortest job first 
INPUT 4 3 7 1 2
*/

int sjf(vector<int> arr,int n){
    int waitingTime=0;
    int t=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        waitingTime+=t;
        t+=arr[i];
    }
    return (waitingTime/n);
}

int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<sjf(arr,n);
    return 0;
}