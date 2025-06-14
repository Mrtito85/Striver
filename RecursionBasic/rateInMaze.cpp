#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isSafe(vector<vector<int>> &m,int x,int y,vector<vector<int>> &visited,int n){
    if((x>=0 && x<n) && (y >=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
        return true;
    } 
    else{
        return false;
    }
}

void solve(vector<vector<int>> &m,int n,int x,int y,string output,vector<string> &ans,vector<vector<int>> &visited){
    if(x>= n-1 && y>=n-1){
        ans.push_back(output);
        return;
    }
    //cout<<"HI";
    visited[x][y]=1;
    int newX=x+1;
    int newY=y;
    //down x+1,y
    if(isSafe(m,newX,newY,visited,n)){
        output.push_back('D');
        solve(m,n,newX,newY,output,ans,visited);
        output.pop_back();
    }
    //left x,y-1
    newX=x;
    newY=y-1;
    if(isSafe(m,newX,newY,visited,n)){
        output.push_back('L');
        solve(m,n,newX,newY,output,ans,visited);
        output.pop_back();
    }
    //right x,y+1
    newX=x;
    newY=y+1;
    if(isSafe(m,newX,newY,visited,n)){
        output.push_back('R');
        solve(m,n,newX,newY,output,ans,visited);
        output.pop_back();
    }
    //up x-1,y
    newX=x-1;
    newY=y;
    if(isSafe(m,newX,newY,visited,n)){
        output.push_back('U');
        solve(m,n,newX,newY,output,ans,visited);
        output.pop_back();
    }
    visited[x][y]=0;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> m(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }
    vector<vector<int>> visited=m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    //cout<<"Hi";

    vector<string> ans;
    string output="";

    int i=0;
    int j=0;
    solve(m,n,i,j,output,ans,visited);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}