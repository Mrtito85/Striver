#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;





class meeting{
    public:
    int sTime;
    int eTime;
    int pos;
};
bool camp(meeting valEnding1, meeting valEnding2){
    return valEnding1.eTime < valEnding2.eTime;
}

void solve(vector<int> startingTime,vector<int> endingTime,int n){
    //if i want to return the index of meeting 
    vector<meeting> arr(n);
    for(int i=0;i<n;i++){
        arr[i].sTime=startingTime[i];
        arr[i].eTime=endingTime[i];
        arr[i].pos=i+1;
    }

    sort(arr.begin(),arr.end(),camp);
    int count=1;
    int freeTime=arr[0].eTime;
    vector<int> ans;
    ans.push_back(arr[0].pos);

    for(int i=1;i<n;i++){
        if(arr[i].sTime > freeTime){
            count++;
            ans.push_back(arr[i].pos);
            freeTime=arr[i].eTime;
        }
    }
    cout<<count<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
}



int main(){
    int n;
    cin>>n;
    vector<int> startingTime(n);
    vector<int> endingTime(n);
    for(int i=0;i<n;i++){
        cin>>startingTime[i];
    }
    for(int i=0;i<n;i++){
        cin>>endingTime[i];
    }
    solve(startingTime,endingTime,n);
    return 0;
}