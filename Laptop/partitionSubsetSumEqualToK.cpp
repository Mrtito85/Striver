#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }
    int target=totalSum/2;
    if(totalSum&1){
        cout<<"NO"<<endl;
    }else{
        bool ans= subsetEqualToTargetTab(arr,n,target);
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}