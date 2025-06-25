#include <iostream>
#include <vector>
using namespace std;
/*
we will buy and sell stocks multiple times but here we are strictly avoid to buy before selling the existing
ones.

*/

int maxProfit(vector<int> &values,int index,bool buy,int n){
    if(index==n)return 0;
    int profit=0;
    if(buy){
        profit=  max(-values[index] + maxProfit(values,index+1,0,n),maxProfit(values,index+1,1,n));
    }
    else{
        profit=  max(values[index] + maxProfit(values,index+1,1,n),maxProfit(values,index+1,0,n));

    }
    return profit;
}

int maxProfitMem(vector<int> &values,int index,bool buy,int n,vector<vector<int>> &dp){
    if(index==n)return 0;
    int profit=0;
    if(dp[index][buy]!=-1)return dp[index][buy];
    if(buy){
        profit=  max(-values[index] + maxProfitMem(values,index+1,0,n,dp),maxProfitMem(values,index+1,1,n,dp));
    }
    else{
        profit=  max(values[index] + maxProfitMem(values,index+1,1,n,dp),maxProfitMem(values,index+1,0,n,dp));

    }
    return dp[index][buy] = profit;
}
int maxProfitTab(vector<int> &values,int n){
    vector<vector<long>> dp(n+1,vector<long>(2,0));
    dp[n][0]=0;
    dp[n][1]=0;

    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            long profit=0;
            if(buy){
                profit=  max(-values[index] + dp[index+1][0],dp[index+1][1]);
            }
            else{
                profit=  max(values[index] + dp[index+1][1],dp[index+1][0]);

            }
             dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}
int main(){
    int n;
    cin>>n;
    vector<int> values(n);
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    cout<<maxProfit(values,0,1,n)<<endl;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<maxProfitMem(values,0,1,n,dp)<<endl;
    cout<<maxProfitTab(values,n);
    return 0;
}