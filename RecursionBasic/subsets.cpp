#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &arr,int index,vector<int> output,vector<vector<int>> &ans,int n){
    if(index>=n){

        ans.push_back(output);

        return;
    }    //exclude call
    solve(arr,index+1,output,ans,n);


    //include 
    output.push_back(arr[index]);
    solve(arr,index+1,output,ans,n);
    output.pop_back();
}


int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }
    int index=0;
    vector<vector<int>> ans;
    vector<int> output;
    solve(arr,index,output,ans,n);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}