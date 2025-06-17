#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Assign  Cookies
INPUT:
greed=1 5 3 3 4   child
cookieSize=4 2 1 2 1 3      parent
every child has a greed factor and parent has the cookies 
the child only satisfied when the cookie size is greater or equal to the greed of child 
TASK:
your task is to satisfied the maximum children
greed <=cookieSize

Approach

sort the both array
take two pointer left and right
left point to greed , right points to the cookieSize
at the end return the right pointer because it's represent the satisfied child number 
start assigning the minimum cookie size


Time complexty Big O N(log N)
we are distortating the array
*/


int assignCookies(vector<int> greed,vector<int> cookies,int n,int m){
    int left=0;
    int right=0;
    sort(greed.begin(),greed.end());
    sort(cookies.begin(),cookies.end());
    while(left < n && right <m){
        if(greed[left] <= cookies[right]){
            left++;
        }
        right++;
    }
    return left;
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<int> greed(n);
    vector<int> cookieSize(m);
    for(int i=0;i<n;i++){
        cin>>greed[i];
    }
    for(int i=0;i<m;i++){
        cin>>cookieSize[i];
    }

    cout<<assignCookies(greed,cookieSize,n,m);
    return 0;
}