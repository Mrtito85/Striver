#include <iostream>
#include <vector>
using namespace std;

/*
How to find the problem is related to dp
--> find all number of ways
--> find the minimum or maximum possible ways

Solve Trick
-> try to represent the problem in term of index
-> do all possible stuff on that index according to the problem statement
-> if the questin says count all ways sum of all ways
-> min(of all stuff) or max(of all stuff)
For n = 3, the valid ways are:

1+1+1

1+2

2+1
➡️ Total = 3
*/

int climbStair(int n){
    //all possible way
    if(n==0)return 1;
    if(n<0)return 0;
    return climbStair(n-1)+ climbStair(n-2);
}
int climbStairTopDown(int n,vector<int> &dp){
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    return dp[n] = climbStairTopDown(n-1,dp) + climbStairTopDown(n-2,dp);
}
int climbStairBottomUp(int n){
    vector<int> dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(i-2>=0){
            dp[i]+=dp[i-2];
        }
    }
    return dp[n];
}

int climbStairSpaceOptimize(int n) {
    if (n == 0) return 1;
    int prev2 = 1;  // dp[0]
    int prev1 = 1;  // dp[1] (will be computed during first iteration if n >= 1)

    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<climbStairSpaceOptimize(n);
    //cout<<climbStair(n);
    return 0;
}