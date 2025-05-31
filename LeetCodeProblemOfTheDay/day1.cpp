#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int n;
    pair<int,int> getCood(int num){
        int TopRow=(num-1)/n;
        int BottomROW=(n-1)-(TopRow);

        int col=(num-1)%n;
        if((n%2==0 && BottomROW%2==0 )||(n%2==1 && BottomROW%2==1) ){
            col=(n-1)-col;
        }
        return {BottomROW,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
       n=board.size();
       vector<vector<bool>> visited(n,vector<bool> (n,false));
       queue<int> q;
       q.push(1);
       visited[n-1][0]=true;
       int steps=0;

       //Here writing simple code for bfs to find the shortest path to destination
       while(!q.empty()){
        int N=q.size();
        while(N--){
            int x=q.front();
            q.pop();
            if(x==n*n){
                return steps;
            }
            for(int k=1;k<=6;k++){
                int val=x+k;
                if(val>n*n)break;
                pair<int,int> cood= getCood(val);
                int row=cood.first;
                int col=cood.second;
                if(visited[row][col])continue;
                if(board[row][col]==-1){
                    q.push(val);
                }
                else{
                    q.push(board[row][col]);
                }
                visited[row][col]=true;
            }
        }
        steps++;
       }
       return -1;

    }
};  

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    Solution sol;
    bool result = sol.snakesAndLadders(arr);
    if (result == -1)
        cout << "Cannot reach the final cell.\n";
    else
        cout << "Minimum moves required: " << result << endl;

    return 0;
}