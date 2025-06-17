#include <iostream>
#include <vector>
using namespace std;


/*
    JUMP GAME
INPUT_  1 2 4 1 1 0 2 5  n =8  output is true

Problem : 
            Here is a problem statement of jump game I. in this problem the player 
            can jump for given array value -> to next indexs
            
Approach : Here we will store the maxJumpPossible  index+ arr[i]  and if i> maxJump then return false

*/

bool solve(vector<int> arr,int n){
    int maxJump=0;
    for(int i=0;i<n;i++){
        if(i>maxJump)return false;
        maxJump=max(maxJump,i+arr[i]);
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n);

    return 0;
}