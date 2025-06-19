#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumNonAdj(vector<int> &arr,int index){
    if(index==0)return arr[index];
    if(index<0)return 0;
    //take
    int left=arr[index] + maxSumNonAdj(arr,index-2);
    //not take
    int right=0 + maxSumNonAdj(arr,index-1);
    return max(left,right);
}
int maxSumNonAdjRec(vector<int> &arr,int index,vector<int> &dp){
    if(index==0)return arr[index];
    if(index<0)return 0;

    //check
    if(dp[index]!=-1)return dp[index];
    //take
    int left=arr[index] + maxSumNonAdjRec(arr,index-2,dp);
    //not take
    int right=0 + maxSumNonAdjRec(arr,index-1,dp);
    return dp[index] =  max(left,right);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //cout<<maxSumNonAdj(arr,n-1);
    vector<int> dp(n+1,-1);
    cout<<maxSumNonAdjRec(arr,n-1,dp);
    return 0;
}