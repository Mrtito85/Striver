#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printAllPermutation(vector<int> &arr,int n,vector<int> &temp,vector<vector<int>> &ans,vector<int> &visited){
    if(temp.size()>=arr.size()){
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=1;
            temp.push_back(arr[i]);
            printAllPermutation(arr,n,temp,ans,visited);
            visited[i]=0;
            temp.pop_back();
        }
    }

}
void printAllPermutation1(vector<int> &arr,int index,int n,vector<vector<int>> &ans){
    if(index>=n){
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<n;i++){
        swap(arr[i],arr[index]);
        printAllPermutation1(arr,index+1,n,ans);
        swap(arr[i],arr[index]);
    }
}
void nextPermutation(vector<int> &arr,int n){
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(arr.begin(),arr.end());
    }
    int miniFromRight=-1;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>arr[index]){
            miniFromRight=i;
            break;
        }
    }
    swap(arr[index],arr[miniFromRight]);
    reverse(arr.begin() + index+1,arr.end());

    for(auto i:arr){
        cout<<i<<" ";
    }

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> temp;
    vector<vector<int>> ans;
    vector<int> visited(n,0);
    nextPermutation(arr,n);
    
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";   
        }
        cout<<endl;
    }

    return 0;
}