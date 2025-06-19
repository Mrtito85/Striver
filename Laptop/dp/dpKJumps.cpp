#include <iostream>
#include <vector>
#include<climits>
using namespace std;

// int climbKJumpsRec(int index,int k,vector<int> &cost,vector<int> &dp){
//     int steps=INT_MAX;
//     if(index==0)return 0;
//     if(dp[index]!= -1)return dp[index];
//     for(int i=1;i<=k;i++){
//         int jump=INT_MAX;
//         if(index-i>=0){
//             jump=climbKJumpsRec(index-i,k,cost,dp)+ abs(cost[index]-cost[index-i]);
//         }
//        // steps=min(steps,jump);
//     }
//     return dp[index] = steps;

// }

int climbKJumpsTab(int index, int k, vector<int> &cost) {
    vector<int> dp(index + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= index; i++) {
        int steps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            int jump = INT_MAX;
            if (i - j >= 0) {
                jump = dp[i - j] + abs(cost[i] - cost[i - j]);
            }
            steps = min(steps, jump);
        }
        dp[i] = steps;
    }

    return dp[index];
}



int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> cost(n+1);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    vector<int> dp(n+1,-1);
    cout<<climbKJumpsTab(n-1,k,cost);
    return 0;
}
