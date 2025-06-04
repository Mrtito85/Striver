#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main(){
    //trip line problem at codeforces
    //we have a number lines which is start from the point zero and end at point x
    //our car has intial gas capacity and gas station is not present at point zero and point 
    int t;
    cin>>t;
    while(t--){
    long long n,x;
    cin>>n>>x;
    vector<long long> ans;
    //here i'm adding zero because car starting point is at zero
    ans.push_back(0);
    for(int i=0;i<n;i++){
        long long point;
        cin>>point;
        ans.push_back(point);
    }
    //here pushing x because the car has to go at the point x
    ans.push_back(x);
    n=ans.size();

    long long max_distance=INT_MIN;
    for(int i=1;i<n;i++){
        if(i==n-1){
            //here we are multipling with 2 because our car don't fuel at the point x so need dubble fuel
            max_distance=max(max_distance,2*(ans[i]-ans[i-1]));
        }else{
            max_distance=max(max_distance,ans[i]-ans[i-1]);
        }
    }
    cout<<max_distance<<endl;

}
    return 0;
}