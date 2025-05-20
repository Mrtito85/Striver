#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

void printAllPermutation(vector<int> &arr,int n,vector<int> &temp,vector<vector<int>> &ans,vector<int> &visited){
    if(temp.size()>=arr.size()){
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=1;
            temp.push_back(arr[i]);
            printAllPermutation(arr,n,temp,ans,visited);
            visited[i]=0;
            temp.pop_back();
        }
    }

}
void printAllPermutation1(vector<int> &arr,int index,int n,vector<vector<int>> &ans){
    if(index>=n){
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<n;i++){
        swap(arr[i],arr[index]);
        printAllPermutation1(arr,index+1,n,ans);
        swap(arr[i],arr[index]);
    }
}
void nextPermutation(vector<int> &arr,int n){
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(arr.begin(),arr.end());
    }
    int miniFromRight=-1;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>arr[index]){
            miniFromRight=i;
            break;
        }
    }
    swap(arr[index],arr[miniFromRight]);
    reverse(arr.begin() + index+1,arr.end());

    for(auto i:arr){
        cout<<i<<" ";
    }

}

void findLeader(vector<int> &arr,int n){
    vector<int> leader;
    for(int i=0;i<n;i++){
        bool leaderNum =true;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                leaderNum=false;
                break;
            }
        }
        if(leaderNum){
            leader.push_back(arr[i]);
        }

    }
    for(auto i:leader){
        cout<<i<<" ";
    }
}
void findLeader1(vector<int> &arr,int n){
    int maxi=INT_MIN;
    vector<int> leader;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            leader.push_back(arr[i]);
        }
        maxi=max(arr[i],maxi);
    }
    reverse(leader.begin(),leader.end());
    for(auto i:leader){
        cout<<i<<" ";
    }
}

bool linear_Search(vector<int> &arr,int element,int n){
    for(int i=0;i<n;i++){
        if(element==arr[i]){
            return true;
        }
    }
    return false;
}

void longestConsecutiveSubsequence(vector<int> &arr,int n){
    int longest=-1;
    for(int i=0;i<n;i++){
        int count=0;
        int x=arr[i];
        while(linear_Search(arr,x,n)){
            count+=1;
            x=x+1;
            longest=max(count,longest);

        }
    }
    cout<<longest<<endl;

}
void longestConsecutiveSubsequence1(vector<int> &arr,int n){
    sort(arr.begin(),arr.end()); //here we distoring the array the interview might not like it
    int count=0;
    int longest=-1;
    int previousElement=INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]-1 == previousElement){
            count+=1;
            previousElement==arr[i];
        }
        else if(arr[i]!= previousElement){
            count=1;
            previousElement=arr[i];
        }
        longest=max(longest,count);
    }
    cout<<longest<<endl;
}
void longeestConsecutiveSubsequence2(vector<int> &arr,int n){
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int longest=-1;
    int count=0;
    for(auto it:st){
        if(st.find(it-1)==st.end()){
             count=0;
            int x= it;
            while(st.find(x)!=st.end()){
                x=x+1;
                count++;
            }
            longest=max(count,longest);
        }
    }
    cout<<longest<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> temp;
    vector<vector<int>> ans;
    vector<int> visited(n,0);
    longeestConsecutiveSubsequence2(arr,n);
    

    return 0;
}