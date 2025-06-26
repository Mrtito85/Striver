#include <iostream>
#include <vector>
using namespace std;

void powerSet(vector<int> &arr,int n){
    vector<vector<int>> ans;
    for(int num=0;num<(1<<n);num++){
        vector<int> list;
        for(int i=0;i<n;i++){
            if(num & (1<<i)){
                list.push_back(arr[i]);
            }
        }
        ans.push_back(list);
    }
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    powerSet(arr,n);
    return 0;
}