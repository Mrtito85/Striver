#include <iostream>
#include <vector>
#include <string> 
using namespace std;

void solve(string arr,int index,string output,vector<string> &ans){
    if(index>=arr.size()){
        if(output.size()>0){
            ans.push_back(output);
        }
        return;
    }

    //exclude 
    solve(arr,index+1,output,ans);
    //include
    output.push_back(arr[index]);
    solve(arr,index+1,output,ans);
    output.pop_back();
}

int main(){
    string arr;
    cin>>arr;
    vector<string> ans;
    string output="";
    int index=0;
    solve(arr,index,output,ans);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}