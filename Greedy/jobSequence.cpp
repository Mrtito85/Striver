#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class jobs{
    public:
      int id;
      int deadline;
      int profit;

};
bool camp(jobs val1 ,jobs val2){
    return val1.profit > val2.profit;
}
void solve(vector<jobs> arr,int n){
    sort(arr.begin(),arr.end(),camp);
    int count=0;
    int totalProfit=0;
    int maxDeadLine=0;
    for(int i=0;i<n;i++){
        maxDeadLine=max(maxDeadLine,arr[i].deadline);
    }
    vector<int> hashing(maxDeadLine+1,-1);

    for(int i=0;i<n;i++){
        for(int j=arr[i].deadline;j>=0;j--){
            if(hashing[j]==-1){
                count++;
                totalProfit+=arr[i].profit;
                hashing[j]=arr[i].id;
                 break;

            }
        }
    }
    cout<<count<<"  "<<totalProfit<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<jobs> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].id;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].deadline;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].profit;
    }

    solve(arr,n);
    return 0;
}