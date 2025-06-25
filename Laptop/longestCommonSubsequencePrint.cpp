#include <iostream>
#include <vector>
using namespace std;

int longestSubsequenceStringLength(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i-1]==s2[j-1]){
        return dp[i][j] = 1 + longestSubsequenceStringLength(s1,s2,i-1,j-1,dp);
    }
    else{
        return dp[i][j] = max(longestSubsequenceStringLength(s1,s2,i-1,j,dp),longestSubsequenceStringLength(s1,s2,i,j-1,dp));
    }

}

void printLongestStringSubsequence(string &s1,string &s2,int n1,int n2){
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    //mark all the i row to zero
    for(int i=0;i<n1;i++){
        dp[i][0]=0;
    }

    //mark all the j col to zero
    for(int j=0;j<n2;j++){
        dp[0][j]=0;
    }
    vector<char> ans;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                ans.push_back(s1[i-1]);
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<dp[n1][n2]<<endl;
}


int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    int n1=s1.size();
    int n2=s2.size();
    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
    cout<<longestSubsequenceStringLength(s1,s2, n1, n2,dp);
    printLongestStringSubsequence(s1,s2,n1,n2);
    return 0;
}