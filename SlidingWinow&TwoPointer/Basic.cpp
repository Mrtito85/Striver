#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    Pattern 1
    Two Pointer and Sliding windows questions
    Constant side of window
    Input :  Arr , k

    Problem Maximum sum by picking element consequetitively
    Approach 1 

    take two pointer L and R
    L point point to 0
    R =k
    while moving the pointer L++ and R++  left value substrack and right value added
    and update the sum while travelling because we have to update the maximum 
    n=7
    -1 2 3 3 4 5 -1 
    k=4
    the maximum sum is 15
*/

/*
    Pattern 2 
    Longest SubArray & SubString  where  <Condition>  --> Most Asked problem 
       - Under Pattern 2 -> longest SubArray where Sum is <=k  
       - k is given in input
*/
void constantSizeWindow(vector<int> v,int n,int k){
    //using two pointers l and R
    int l=0;
    int r=k;
    int sum=0;
    int maxSum=INT_MIN;
    for(int i=l;i<r;i++){
        sum+=v[i];
        
    }
    maxSum=max(sum,maxSum);
  //  cout<<maxSum<<endl;
   // cout<<sum<<endl;

    while(r<v.size()){
        sum-=v[l];
        l++;
        
        sum+=v[r];
        // After adding the sum then move the r pointer other r will out of array size and we are adding wrong sum
        r++;
        maxSum=max(sum,maxSum);
       // cout<<maxSum<<endl;
    }
    cout<<"Maximum Sum is "<<maxSum<<endl;

}

void longestSubarrayLength(vector<int > v,int n,int k){
    //we have to find the longest subarray length where sum is <= k
    //Brute Force Approach
    //Traverse all all the subArrays 
    //create a maxLength variable and update maxSum
    //In the starting of every subArray initial value of sum is 0

    int maxLength=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=v[j];
            if(sum<=k){
                //cout<<sum<<endl;
                 maxLength=max(maxLength,j-i+1);
            }
               
            if(sum>k){
                break;
            }
        }
    }
    cout<<maxLength<<endl;
}

void LongetSubarrayLength1(vector<int> v,int n,int k){
    //Better Solution
    //here we will use two pointers l and r
    //l points to 0 initially and r also point to 0
    //while r < n   sum add v[i]  and if sum >k  then we will substract the left increment until the sum come to range
    //then check if sum is less then k than upate the maxlength j-i+1  | r-l+1  
    //r pointer always move 1 step in every iteration

    //Time Complexity BigO 2N space complexity BigO(1)
    int l=0;
    int r=0;
    int sum=0;
    int maxLength=INT_MIN;
    while(r<n){
        sum+=v[r];
        while(sum>k){
            sum-=v[l];
            l++;
        }
        if(sum<=k){
            maxLength=max(maxLength,r-l+1);
        }
        r++;

    }
    cout<<maxLength<<endl;
}
void LongetSubarrayLength2(vector<int> v,int n,int k){
    //Optimal Solution
    //here we will use two pointers l and r
    //l points to 0 initially and r also point to 0
    //while r < n   sum add v[i]  and if sum >k  then we will substract the left increment until the sum come to range
    //then check if sum is less then k than upate the maxlength j-i+1  | r-l+1  
    //r pointer always move 1 step in every iteration

    //Time Complexity BigO N space complexity BigO(1)
    int l=0;
    int r=0;
    int sum=0;
    int maxLength=INT_MIN;
    while(r<n){
        sum+=v[r];
        //instead of while loop i can use if because i want to calculate the max length
        // but this case is not valid for finding subarry

        if(sum>k){
            sum-=v[l];
            l++;
        }
        if(sum<=k){
            maxLength=max(maxLength,r-l+1);
        }
        r++;

    }
    cout<<maxLength<<endl;
}


/*
    Pattern 3:
    Count Number of Subarray where  <Condition>
    --> number of subarray where sum=k --> if it's a constant sign it' difficult to understand weather to expand or shrink
    we can break this problem into this--> number of subarray where sum<=k
    than find number of subarray where sum <=(k-1)
    than subtrack both the answer is sum<=k  -  sum<=(k-1) 
*/

/*
    Pattern 4
    Shortest and Minimum window Where <conditon>
*/

int main(){


    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    LongetSubarrayLength1(v,n,k);
//constantSizeWindow(v,n,k);
    return 0;
}