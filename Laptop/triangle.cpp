#include <iostream>
#include <vector>
using namespace std;


int triangleMinSumPath(int i,int j,int n,vector<vector<int>> &arr){
    if(i==n){
        return arr[i][j];
    }
    
    int down= arr[i][j] + triangleMinSumPath(i+1,j,n,arr);
    int diagonal=arr[i][j] + triangleMinSumPath(i+1,j+1,n,arr);
    
     int ans =min(down,diagonal);
     return ans;
}

int main(){
    
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }

    int i=0;
    int j=0;
    cout<<triangleMinSumPath(i,j,n-1,arr);
    return 0;
}