#include <iostream>
#include <vector>

using namespace std;
int countSubsetOfSumK(vector<int> &arr,int index,int sum){
    if(sum==0){
        return 1;
    }
    if(index==0){
        return (arr[index]==sum);
    }
    //nottake
    int notTake=countSubsetOfSumK(arr,index-1,sum);
    int take=0;
    if(sum>=arr[index]){
        take=countSubsetOfSumK(arr,index-1,sum-arr[index]);
    }
    //cout<<take+notTake<<endl;
    return take + notTake;
}
int countSubsetOfSumKMem(vector<int> &arr,int index,int sum,vector<vector<int>> &dp){
    if(sum==0){
        return 1;
    }
    if(index==0){
        return (arr[index]==sum);
    }
    if(dp[index][sum]!=-1)return dp[index][sum];
    //nottake
    int notTake=countSubsetOfSumKMem(arr,index-1,sum,dp);
    int take=0;
    if(sum>=arr[index]){
        take=countSubsetOfSumKMem(arr,index-1,sum-arr[index],dp);
    }
    //cout<<take+notTake<<endl;
    return dp[index][sum] = take + notTake;
}
int countSubsetOfSumKTab(vector<int> &arr,int n,int sum){
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
   
    }
    
    if(arr[0]<=sum)dp[0][arr[0]]=1;


        
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //cout<<countSubsetOfSumK(arr,n-1,k);
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    cout<<countSubsetOfSumKMem(arr,n-1,k,dp);

    return 0;
}