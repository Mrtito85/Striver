#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubsequence(vector<int> &arr,int index,int prev,int n){
    if(index==n)return 0;

    //nottake
    int len=longestIncreasingSubsequence(arr,index+1,prev,n);
    if(prev==-1 || arr[index]>=arr[prev]){
        len=max(len,1+ longestIncreasingSubsequence(arr,index+1,index,n));
    }
    return len;
}
//N-1 INDEX IS NOT POSSIBLE SO THAT WE MAP -1 TO 0 AND 1  TO 2 AND N-1 TO N
int longestIncreasingSubsequenceMem(vector<int> &arr,int index,int prev,int n,vector<vector<int>> &dp){
    if(index==n)return 0;
    if(dp[index][prev+1]!=-1)return dp[index][prev+1];
    //nottake
    int len=longestIncreasingSubsequenceMem(arr,index+1,prev,n,dp);
    if(prev==-1 || arr[index]>=arr[prev]){
        len=max(len,1+ longestIncreasingSubsequenceMem(arr,index+1,index,n,dp));
    }
    return dp[index][prev+1] = len;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int prev=-1;
    int index=0;
    cout<<longestIncreasingSubsequence(arr,index,prev,n)<<endl;
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    cout<<longestIncreasingSubsequenceMem(arr,index,prev,n,dp)<<endl;

    return 0;

}