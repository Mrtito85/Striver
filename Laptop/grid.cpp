#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxGridPath(int i,int j,vector<vector<int>> &arr){
    if(j<0 || j>=arr[0].size() ){
        return -1e9;
    }
    if(i==0){
        return arr[i][j];
    }
    //up
    int up=arr[i][j] + maxGridPath(i-1,j,arr);
    //up left
    int dl= arr[i][j] + maxGridPath(i-1,j-1,arr);
    //up right
    int dr=arr[i][j] + maxGridPath(i-1,j+1,arr);

    return max(up,max(dl,dr));
}
int maxGridPathRec(int i,int j,vector<vector<int>> &arr,vector<vector<int>> &dp){
    if(j<0 || j>=arr[0].size() ){
        return -1e9;
    }
    if(i==0){
        return arr[i][j];
    }
    if(dp[i][j]!= -1 )return dp[i][j];
//up
    int up=arr[i][j] + maxGridPath(i-1,j,arr);    
    //up left
    int dl= arr[i][j] + maxGridPath(i-1,j-1,arr);
    //up right
    int dr=arr[i][j] + maxGridPath(i-1,j+1,arr);

    return  dp[i][j] =  max(up,max(dl,dr));
}
int maxGridPathTab(int n,int m,vector<vector<int>> &arr){
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    for(int j=0;j<=n;j++){
        dp[0][j]=arr[0][j];
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            int up=arr[i][j]+dp[i-1][j];
            int dl=arr[i][j];
            if(j>0){
                dl+=dp[i-1][j-1];
            }else{
                dl=-1e9;
            }
            int dr=arr[i][j];
            if(j<arr[0].size()-1){
                dr+=dp[i-1][j+1];

            }
            else{
                dr=-1e9;
            }

            dp[i][j]=max(up,max(dl,dr));
        }
    }
    int maxi=-1e9;
    for(int i=0;i<=n;i++){
        maxi=max(maxi,dp[n][i]);
    }
    return maxi;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    // int ans=INT_MIN;
    // for(int i=0;i<m;i++){
    //     ans=max(ans,maxGridPath(n-1,i,arr));
    // }
    // cout<<ans;
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // int ans=INT_MIN;
    // for(int i=0;i<m;i++){
    //     ans=max(ans,maxGridPathRec(n-1,i,arr,dp));
    // }
    // cout<<ans;
    cout<<maxGridPathTab(n-1,m-1,arr);

    return 0;
}