#include<iostream>
#include <vector>
using namespace std;

void subsequence(vector<int> &arr,int index,int n,vector<int> &temp){
    if(index>=n){
        for(auto i:temp){
            cout<<i<<" ";
        }
        if(temp.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    //take
    temp.push_back(arr[index]);
    subsequence(arr,index+1,n,temp);
    temp.pop_back();

    //not take
    subsequence(arr,index+1,n,temp);
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> temp;
    subsequence(arr,0,n,temp);
    return 0; 
}