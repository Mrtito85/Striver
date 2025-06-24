#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubstring(string &s1,string &s2,int index1,int index2){
    //base case
    if(index1<0 || index2 <0){
        return 0;
    }

    if(s1[index1]==s2[index2]){
        return 1 + longestCommonSubstring(s1,s2,index1-1,index2-1);
    }else{
        return max(longestCommonSubstring(s1,s2,index1-1,index2),longestCommonSubstring(s1,s2,index1,index2-1));
    }
}
int longestCommonSubstringMem(string &s1,string &s2,int index1,int index2,vector<vector<int>> &dp){
    //base case
    if(index1<0 || index2 <0){
        return 0;
    }
    if(dp[index1][index2]!=-1)return dp[index1][index2];
    if(s1[index1]==s2[index2]){
        return dp[index1][index2]= 1 + longestCommonSubstringMem(s1,s2,index1-1,index2-1,dp);
    }else{
        return dp[index1][index2]= max(longestCommonSubstringMem(s1,s2,index1-1,index2,dp)
            ,longestCommonSubstringMem(s1,s2,index1,index2-1,dp));
    }
}
int main(){

    string s1;
    string s2;
    cin>>s1>>s2;
    int n1=s1.size();   
    int n2=s2.size();
   cout<<longestCommonSubstring(s1,s2,n1-1,n2-1)<<endl;
   vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
   cout<<longestCommonSubstringMem(s1,s2,n1-1,n2-1,dp);
    return 0;


}