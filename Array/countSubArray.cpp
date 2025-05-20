#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countAllSubarrayOfSumK(vector<int> &arr,int n,int target){
    int count=0;
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum =0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==target){
                count++;
            }
        }
    }

    cout<<"HI "<<count<<endl;
}
void countAllSubarrayOfSumK1(vector<int>&arr,int n,int target){
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==target){
                count++;
            }
        }
    }
    cout<<count<<endl;
}
void countAllSubarrayOfSumK2(vector<int> &arr,int n,int target){
    map<int,int> mp;
    int count=0;
    int sum=0;
    mp[0]=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int remainSum=sum-target;
        count+=mp[remainSum];
        mp[sum]+=1;
    }
    cout<<count;

}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    countAllSubarrayOfSumK2(arr,n,target);


    return 0;
}