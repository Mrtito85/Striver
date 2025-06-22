#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int minimumGridPath(vector<vector<int>> &arr,int i,int j){
    if(i==0 && j==0 )return arr[i][j];
    if(i<0 || j<0)return 1e9;

    int up=arr[i][j]+minimumGridPath(arr,i-1,j);
    int back=arr[i][j] + minimumGridPath(arr,i,j-1);
    return min(up,back);
}
int minimumGridPathRec(vector<vector<int>> &arr,int i,int j,vector<vector<int>> &dp){
    if(i==0 && j==0 )return arr[i][j];
    if(i<0 || j<0)return 1e9;
    if(dp[i][j]!=-1)return dp[i][j];

    int up=arr[i][j]+minimumGridPathRec(arr,i-1,j,dp);
    int back=arr[i][j] + minimumGridPathRec(arr,i,j-1,dp);
    return dp[i][j] = min(up,back);
}
int minimumGridPathTab(vector<vector<int>> &arr,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 && j==0)dp[i][j]=arr[i][j];
            else{
                int up=arr[i][j];
                int back=arr[i][j];
                if(i>0){
                    up+=dp[i-1][j];
                }else{
                    up=INT_MAX;
                }
                if(j>0){
                    back+=dp[i][j-1];
                }else{
                    back=INT_MAX;
                }
                dp[i][j]=min(up,back);
            }
        }
    }
    return dp[n][m];
}

int minimumGridPathTabSpaceOptimize(vector<vector<int>> &arr,int n,int m){
    vector<int> prev(n+1,0);
    for(int i=0;i<=n;i++){
        vector<int> curr(m+1,0);
        for(int j=0;j<=m;j++){
            if(i==0 && j==0)curr[j]=arr[i][j];
            else{
                int up=arr[i][j];
                int back=arr[i][j];
                if(i>0){
                    up+=prev[j];
                }else{
                    up=INT_MAX;
                }
                if(j>0){
                    back+=curr[j-1];
                }else{
                    back=INT_MAX;
                }
                curr[j]=min(up,back);
            }
        }
        prev=curr;
    }
    return prev[m];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    //cout<<minimumGridPath(arr,n-1,m-1);
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<minimumGridPathTabSpaceOptimize(arr,n-1,m-1);
    return 0;
}