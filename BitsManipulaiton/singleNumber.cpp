#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void findSingle(vector<int> &arr,int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto i:mp){
        if(i.second==1){
            cout<<i.first<<endl;
            break;
        }
    }
    //using xor
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i];
    }
    cout<<xor1<<endl;   
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    findSingle(arr,n);
    return 0;
}