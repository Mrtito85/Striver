#include <iostream>
#include <vector>
using namespace std;


int fib(int n){
    if(n==0)return 0;
    if (n==1)return 1;

    return fib(n-1)+fib(n-2);
}

int fibDTopDown(int n,vector<int> &dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n] = fibDTopDown(n-1,dp)+ fibDTopDown(n-2,dp);
}

int fibBottonUp(int n){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+ dp[i-2];
    }
    // for(int i=0;i<dp.size();i++){
    //     cout<<dp[i]<<endl;
    // }
    return dp[n];
}
int fibBottonUpSpaceOptimize(int n){
    vector<int> dp(n+1,-1);
    int prev2=0;
    int prev1=1;
    for(int i=2;i<=n;i++){
        int curr=prev1+ prev2;
        prev2=prev1;
        prev1=curr;
    }
    // for(int i=0;i<dp.size();i++){
    //     cout<<dp[i]<<endl;
    // }
    return prev1;
}

int main(){
    // int n;
    // cin>>n;
    // vector<int> dp(n+1,-1);
    // fibDTopDown(n,dp);
    // dp[0]=0;
    // if(n>1)
    //     dp[1]=1;
    // for(int i=0;i<dp.size();i++){
    //     cout<<dp[i]<<" ";
    // }
    int n;
    cin>>n;
    cout<<fibBottonUpSpaceOptimize(n);
    return 0;
}