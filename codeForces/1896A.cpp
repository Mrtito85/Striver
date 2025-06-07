#include <iostream>
#include <vector>
using namespace std;
bool solve(vector<int> &arr,int n){
    if(arr[0]==1)return true;
    else return false;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool ans =solve(arr,n);
        if(ans){
            cout<<"YES"<<endl;
        }
        else{ 
            cout<<"NO"<<endl;
        }
    }
    return 0;
}