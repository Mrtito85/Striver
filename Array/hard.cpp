#include<iostream>
#include<vector>
#include <set>
#include<map>
#include<algorithm>
#include <climits>
using namespace std;

//ncr  ==> N! / r! *(n-r)!

int fact(int n){
    int factNum=1;
    for(int i=1;i<=n;i++){
        factNum *=i;
    }
  return factNum;
}

void printPascalTriagleElement(int n,int r){
    //Here is the brute force using NCR
    int ans=fact(n) / (fact(r) *        (n - r));
    cout<<ans<<endl;
}
void printPascalTriangleElement1(int  n,int r){ 
   //Here is brute force run in BigO(R) time complexiy also take result in long long
   
    long long  result=1;
    for(int i=0;i<r;i++){
        result =result*(n-i);
        result=result/(i+1);
    }
    cout<<result<<" ";
}

void printPascalTriangleRow(int n){
    for(int i=1;i<=n;i++){
        printPascalTriangleElement1(n-1,i-1);
    }
    
}
void printPascalTriangleRow1(int n){
    int ans=1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
        ans=ans*(n-i);
        ans=ans/i;
        cout<<ans<<" ";
    }
}

void printPascalTriangleComplete(int n){
    for(int i=1;i<=n;i++){
        printPascalTriangleRow1(i);
        cout<<endl;
    }
}

void majorityElement(vector<int> &arr,int n){
    vector<int> ans;
    //if the element is appear more than n/3 then print it

    for(int i=0;i<n;i++){
        int element=arr[i];
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==element){
                count++;
            }
        }
        if(count>n/3){
            if(ans.empty() || ans[ans.size()-1]!=element )
                ans.push_back(element);
        }
        if(ans.size()>=2){
            break;
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
}
void majorityElementHashing(vector<int> &arr,int n){
    map<int,int> mp;
    set<int> st;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        if(mp[arr[i]]==n/3){
         //st.insert(arr[i]);   
         cout<<arr[i];
        }
    }
    for(auto i:st){
        cout<<i<<" ";
    }
   // cout<<"Hi";


}
void mahorityElementMoreVoteAlgorithm(vector<int> &arr,int n){
    int count1=0;
    int count2=0;
    int element1=INT_MIN;
    int element2=INT_MIN;
    for(int i=0;i<n;i++){
        if(count1==0 && element2!= arr[i]){
            count1=1;
            element1=arr[i];
        }else if(count2==0 && element1 != arr[i]){
            count2=1;
            element2 = arr[i];
        }
        else if(arr[i] == element1){
            count1++;
        }else if(arr[i]==element2){
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }

    count1=0;
    count2=0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[i]==element1){
            count1++;
        }
        if(arr[i]==element2){
            count2++;
        }
    }
    if(count1>=n/3){
        ans.push_back(element1);
    }
    if(count2>=n/3){
        ans.push_back(element2);
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans){
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
    mahorityElementMoreVoteAlgorithm(arr,n);
    return 0;
}