#include <iostream>
#include <vector>
#include <unordered_map>
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


void maxPointsObtainFromCard(vector<int> v,int n,int k){
    //Input:arr, n
    //we have to find the maximum points obtain from the cards from left or right k size window
    //initially leftSum=0,rightSum=0  calcuate leftSum from 0 to k-1
    //now start removing 1 element form left and adding from right and track the maxSum
    // 7 4
    // 0 2 3 3 4 5 5

    if(k>n){
        cout<<"Not possible"<<endl;
        return ;
    }

    int leftSum=0;
    int rightSum=0;
    int maxSum=INT_MIN;
    //calculate the left sum
    for(int i=0;i<k;i++){
        leftSum+=v[i];
    }
    maxSum=max(maxSum,leftSum);
    //calculte the right sum and start removing from left
    int  rightIndex=n-1;
    for(int i=k-1;i>=0;i--){
        //cout<<i<<endl;
        leftSum-=v[i];
        rightSum+=v[rightIndex];
        rightIndex--;
        maxSum=max(maxSum,leftSum+rightSum);
    }
    cout<<maxSum<<endl;

}

void longestSubstringWithoutRepeatingCharacter(string v,int n){
    //we have to find the longest substring without repeating character
    //we will traverse through the every substring
    //and if it's visited than we break the loop otherwise we will update the maxLength
    int maxLength=INT_MIN;
    for(int i=0;i<n;i++){
        unordered_map<char,bool> visited;
        for(int j=i;j<n;j++){
            if(visited[v[j]]==1)break;
            maxLength=max(maxLength,j-i+1);
            visited[v[j]]=1;
        }

    }
    cout<<maxLength<<endl;
}

void longestSubstringWithoutRepeatingCharacter1(string s,int n){
    //better
    //use unordered map to track visited and their index in which they are present
    //if visited than and visited[curr]>=l  than update l =visited[curr]+1;
    //calculate the length length=r-l+1

    int l=0;
    int r=0;
    int maxLength=0;
    unordered_map<char,int> lastSeen;
    while(r<n){
        int curr=s[r];
        if(lastSeen.find(curr)!=lastSeen.end()){
            //we found the element now check if the index 
            if(lastSeen[curr]>=l){
                l=lastSeen[curr]+1;
            }
        }
        int len=r-l+1;
        maxLength=max(maxLength,len);
        //mark the visited
        lastSeen[curr]=r;
        r++;
    }
    cout<<"Hash "<<maxLength<<endl;
}

void maxConsecutiveOnes(vector<int> v,int n , int k){
    //can i map this problem with this-> longest subarray with at most k zero's
    //brute force 
    //Approach 1
    //generate all the subarrays  k=2
    //if zero count is less than equal to k calculte the max length else break from the loop
    int maxLength=INT_MIN;
    for(int i=0;i<n;i++){
        int zeroCount=0;
        for(int j=i;j<n;j++){
            if(v[j]==0)zeroCount++;
            if(zeroCount<=k){
                maxLength=max(maxLength,j-i+1);
                //cout<<zeroCount<<" "<<j-i+1<<endl;
            }else{
                break;
            }
        }
    }
    cout<<maxLength<<endl;
}
void maxConsecutiveOnes1(vector<int> v,int n,int k){
    //better solutuion
    //using two pointer's left and right
    //initially left and right both points to zero
    //check if v[r]==0 zeroCount++ if the zeroCount > k than move the left pointer forward until zeroCount came under k
    //and if the zeroCount is less or equal to k than update the maximum length and move the r pointer by 1 always

    int left=0;
    int right=0;
    int maxLength=INT_MIN;
    int zeroCount=0;
    while(right<n){
        if(v[right]==0)zeroCount++;
        while(zeroCount>k){
            if(v[left]==0)zeroCount--;

            left++;
        }
        if(zeroCount<=k){
            //update the maximum length
            int len=right-left+1;
            maxLength=max(maxLength,len);
        }

        right++;
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

    maxConsecutiveOnes1(v,n,k);
//constantSizeWindow(v,n,k);
    return 0;
}