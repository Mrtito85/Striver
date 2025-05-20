#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setRow(vector<vector<int>> &arr,int i,int m){
    for(int j=0;j<m;j++){
        if(arr[i][j]!= 0){
            arr[i][j]=-1;
        }
    }
}
void setCol(vector<vector<int>> &arr,int j,int n){
    for(int i=0;i<n;i++){
        if(arr[i][j]!= 0){
            arr[i][j]=-1;
        }
    }
}
void setMatrixToZero(vector<vector<int>> &arr,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                setRow(arr,i,m);
                setCol(arr,j,n);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0 || arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
}
void setMatrixToZero1(vector<vector<int>> &arr,int n,int m){
    vector<int> row(n,0);
    vector<int> col(m,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j]){
                arr[i][j]=0;
            }
        }
    }

}

void rotateImage(vector<vector<int>> &arr,int n,int m){
    vector<vector<int>> temp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[j][n-i-1]=arr[i][j];
        }
    }

        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
}
void rotateImage1(vector<vector<int>> &arr,int n,int m){
    //transpose of matrix
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            //cout<<arr[i][j]<<" ";
            swap(arr[j][i],arr[i][j]);
        }
       // cout<<endl;
    }
   for(int i=0;i<n;i++){
    reverse(arr[i].begin(),arr[i].end());
   }
}

void spiralPrint(vector<vector<int>> &arr,int n,int m){
    int left=0;
    int bottom=m-1;
    int right=n-1;
    int top=0;
    vector<int> ans;

    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top<=bottom){
        for(int i=right;i>=left;i--){
            ans.push_back(arr[bottom][i]);
        }
        bottom--;
        }

        if(left<=right){     
        for(int i=bottom;i>=top;i--){
            ans.push_back(arr[i][left]);
        }
        left++;
        }

    }
    for(auto i:ans){
        cout<<i<<" ";
    }

}

int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }   
    }
    spiralPrint(arr,n,m);

    //here print the matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          //  cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}