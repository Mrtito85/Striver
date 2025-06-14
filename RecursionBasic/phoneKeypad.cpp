#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
given us a number of string "23"

we have to find what are the possible combination of that 2 key pressed

*/


void solve(string arr,int index,string output,vector<string> &ans,string* mapping){
    if(index>=arr.size()){
        ans.push_back(output);
        return;
    }
   // cout<<"HIi1";
    int digit=arr[index]-'0';
    string val=mapping[digit];
    for(int i=0;i<val.size();i++){
        output.push_back(val[i]);
        solve(arr,index+1,output,ans,mapping);
        output.pop_back();
    }

}

int main(){
    string arr;
    cin>>arr;
    vector<string> ans;
    string output;
    int index=0;
    //create a maaping for mobile form 2 ---9
    string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    cout<<"Called"<<endl;
    solve(arr,index,output,ans,mapping);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}