#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int stairClimbCost(int index,vector<int> &cost,vector<int> &dp){
    if(index==0)return 0;   
    if(dp[index]!=-1)return dp[index];

    int left=stairClimbCost(index-1,cost,dp)+ abs(cost[index]-cost[index-1]);
    int right=INT_MAX;
    if(index>1){
        right=stairClimbCost(index-2,cost,dp)+ abs(cost[index]-cost[index-2]);
    }
    return dp[index] = min(left,right);
}
int stairClimbCostBottomUp(int index,vector<int> &cost){
    vector<int> dp(index+1,0);
    dp[0]=0;
    for(int i=1;i<=index;i++){
        int left=dp[i-1]+abs(cost[i]-cost[i-1]);
        int right=INT_MAX;
        if(i>1){
           right=dp[i-2]+abs(cost[i]-cost[i-2]);
        }
        dp[i]=min(left,right);

    }
    for(int i=0;i<dp.size();i++){
       // cout<<dp[i]<<" ";
    }
    return dp[index];
}
int stairClimbCostBottomUpSpaceOptimize(int index,vector<int> &cost){
    int prev1=0;
    int prev2=0;
    for(int i=1;i<=index;i++){
        int left=prev1 +abs(cost[i]-cost[i-1]);
        int right=INT_MAX;
        if(i>1){
           right=prev2+abs(cost[i]-cost[i-2]);
        }
        int curr=min(left,right);
        prev2=prev1;
        prev1=curr;

    }
    return prev1;
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    vector<int> cost(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    cout<<stairClimbCostBottomUpSpaceOptimize(n-1,cost);
    return 0;
}