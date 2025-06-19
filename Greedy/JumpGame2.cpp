#include <iostream>
#include <vector>
#include <climits>
using namespace std;


/*
    JUMP GAME II
calculate the minimum number of jump starting from point to the end

INPUT  2 3 1 1 4  n=5 ,
approach 1 
starting from the 0 index and jump to all possible way after every jump jump + 1
and track the mini jump
*/


int  solve(vector<int> v,int n,int index,int jumps){
    if(index>=n-1){
       // cout<<jumps<<endl;
        return jumps;
    }
    int miniJump=INT_MAX;

    for(int i=1;i<=v[index];i++){
        miniJump=min(miniJump,solve(v,n,index+i,jumps+1));
        
    }
    //cout<<miniJump<<endl;
    return miniJump;
}

int solve1(vector<int> v,int n){
    int jump=0;
    int l=0;
    int r=0;
    while(r<n-1){
        int far=0;
        for(int i=l;i<=r;i++){
            far=max(far,v[i]+i);
        }
        l=r+1;
        r=far;
        jump++;
    }
    return jump;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int index=0;
    int jump=0;
    //cout<<solve(v,n,index,jump);
    cout<<solve1(v,n);
    return 0;
}