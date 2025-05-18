#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void twoSum(vector<int> &arr,int n,int target){
    for(int i=0;i<n;i++){
        bool find =false;
        for(int j=i+1;j<n;j++){
            if(arr[i] + arr[j]==target){
                cout<<i<<" "<<j<<endl;
                find=true;
                break;
            }
        }
        if(find==true)break;
    }
}
void twoSum1(vector<int> &arr,int n,int target){
    vector<pair<int,int>> v;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int remain=target-arr[i];
        if(mp.find(remain)!=mp.end()){
            v.push_back({mp[remain],i});

        }
        mp[arr[i]]=i;
    }
    sort(v.begin(),v.end());
    for(auto i:v){
        cout<<i.first<<" "<<i.second<<endl;
        break;
    }
}
void twoSum2(vector<int> &arr,int n,int target){
    int left=0;
    int right=n-1;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]=i;
    }
    for(auto i:mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==target){map<int,int> mp;
            for(int i=0;i<n;i++){
                mp[arr[i]]=i;
            }
            cout<<left<<" "<<right<<endl;
            break;
        }
        if(sum>target){
            right--;
        }else if(sum<target){
            left++;
        }
    }
}

void sort0_1_2(vector<int> &arr,int n){
    //Time complexity is BigO(2N) and change the array element 
    //constant extra space BigO(1)
    int zero=0;
    int one=0;
    int two=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)zero++;
        if(arr[i]==1)one++;
        if(arr[i]==2)two++;
    }
    for(int i=0;i<zero;i++){
        arr[i]=0;
    }
    for(int i=zero;i<one+zero;i++){
        arr[i]=1;
    }
    for(int i=zero+one;i<n;i++){
        arr[i]=2;
    }
    for(auto i:arr){
        cout<<i<<" ";
    }
}
void sort0_1_2_(vector<int> &arr,int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){

        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
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
    sort0_1_2_(arr,n);
    return 0;
}