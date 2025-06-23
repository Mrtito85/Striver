#include <iostream>
#include <vector>
using namespace std;

/*
represent every thing in term of index 

f (index , weight)
base case
explore the every possible solution
return the max of everyone

*/


int unboundedKnapstack(int index,int w,vector<int> &val,vector<int> &wt){
    if(index==0){
        return ((int )(w/wt[0])*val[0]);
    }
    int notTake=unboundedKnapstack(index-1,w,val,wt);
    int take=0;
    if(w>=wt[index]){
        take= val[index] + unboundedKnapstack(index,w-wt[index],val,wt);
    }
   // cout<<notTake<<" "<<take<<endl;
    return max(notTake,take);
}
int unboundedKnapstackMem(int index,int w,vector<int> &val,vector<int> &wt,vector<vector<int>> &dp){
    if(index==0){
        return ((int )(w/wt[0])*val[0]);
    }
    if(dp[index][w]!=-1)return dp[index][w];
    int notTake=unboundedKnapstackMem(index-1,w,val,wt,dp);
    int take=0;
    if(w>=wt[index]){
        take= val[index] + unboundedKnapstackMem(index,w-wt[index],val,wt,dp);
    }
   // cout<<notTake<<" "<<take<<endl;
    return dp[index][w] = max(notTake,take);
}
int unboundedKnapstackTab(int n,int w,vector<int> &val,vector<int> &wt){
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    //base case
    for(int i=0;i<w;i++){
        dp[0][i]=((int)(i/wt[0]) * val[0]);
    }
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int index=1;index<n;index++){
        for(int W=0;W<=w;W++){
            int notTake=dp[index-1][W];
            int take=0;
            if(W>=wt[index]){
                take=val[index]+ dp[index][W-wt[index]];
            }
            dp[index][W]=max(take,notTake);
        }
    }
    // cout<<endl;
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n-1][w];
}
int unboundedKnapstackTabSpace(int n,int w,vector<int> &val,vector<int> &wt){
   // vector<vector<int>> dp(n,vector<int>(w+1,0));
   vector<int> prev(w+1,0),curr(w+1,0);
    //base case
    for(int i=0;i<w;i++){
        prev[i]=((int)(i/wt[0]) * val[0]);
    }
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int index=1;index<n;index++){
        for(int W=0;W<=w;W++){
            int notTake=prev[W];
            int take=0;
            if(W>=wt[index]){
                take=val[index]+ curr[W-wt[index]];
            }
           curr[W]=max(take,notTake);
        }
        prev=curr;
    }
    // cout<<endl;
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    return prev[w];
}
int main(){

    int n,w;
    cin>>n>>w;
    vector<int> val(n);
    vector<int> wt(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    //cout<<unboundedKnapstack(n-1,w,val,wt);
    // vector<vector<int>> dp(n,vector<int>(w+1,-1));
    // cout<<unboundedKnapstackMem(n-1,w,val,wt,dp);
    cout<<unboundedKnapstackTabSpace(n,w,val,wt);
    return 0;
}