#include <iostream>
#include <vector>
#include <climits>
using namespace std;


bool subsetEqualToTarget(vector<int> &arr,int index,int k){
    if(k==0)return  true;
    if(index==0){
        return arr[0]==k;        
    }
    //not take
    int notTake=subsetEqualToTarget(arr,index-1,k);
    //take
    int take=false;
    if(k>=arr[index]){
        take=subsetEqualToTarget(arr,index-1,k-arr[index]);
    }

    return take | notTake;

}

bool subsetEqualToTargetMem(vector<int> &arr,int index,int k,vector<vector<int>> &dp){
    if(k==0)return  true;
    if(index==0){
        return arr[0]==k;        
    }
    if(dp[index][k]!= -1)return dp[index][k];
    //not take
    int notTake=subsetEqualToTargetMem(arr,index-1,k,dp);
    //take
    int take=false;
    if(k>=arr[index]){
        take=subsetEqualToTargetMem(arr,index-1,k-arr[index],dp);
    }

    return dp[index][k] = take | notTake;

}

bool subsetEqualToTargetTab(vector<int> &arr,int n,int target){
    vector<vector<bool>> dp(n,vector<bool>(target+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if(arr[0]<=target)
        dp[0][arr[0]]=true;
    else{
        //cout<<"out of bound"<<endl;
    }
    
    //print
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // } 
    for(int index=1;index<n;index++){
        for(int k=1;k<=target;k++ ){
            bool notTake=dp[index-1][k];
            bool take=false;
            if(k>=arr[index]){
                take=dp[index-1][k-arr[index]];
            }
            dp[index][k]=take | notTake;
        }
           
    }
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // } 
    return dp[n-1][target];
}

bool subsetEqualToTargetTabSpace(vector<int> &arr,int n,int target){
    //vector<vector<bool>> dp(n,vector<bool>(target+1,0));
    vector<bool> prev(target+1,0),curr(target+1,0);
    prev[0]=curr[0]=true;
    curr[0]=true;
    
    //print
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // } 
    for(int index=1;index<n;index++){
        for(int k=1;k<=target;k++ ){
            bool notTake=prev[k];
            bool take=false;
            if(k>=arr[index]){
                take=prev[k-arr[index]];
            }
            curr[k]=take | notTake;
        }
            prev=curr;
    }
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // } 
    return prev[target];
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //vector<vector<int>> dp(n,vector<int>(k+1,-1));
    //cout<<subsetEqualToTargetMem(arr,n-1,k,dp);
    //cout<<subsetEqualToTarget(arr,n-1,k);
    //cout<<subsetEqualToTargetTab(arr,n,k);
    cout<<subsetEqualToTargetTabSpace(arr,n,k);
    return 0;
}