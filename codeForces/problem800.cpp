#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    long long  t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;

        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<long long> copy_arr=arr;
        sort(copy_arr.begin(),copy_arr.end());
        
        if(copy_arr==arr || k>1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}