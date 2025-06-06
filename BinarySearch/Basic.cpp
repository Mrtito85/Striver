#include<iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
void binarySearch(vector<int> &arr,int low,int high,int target){
    int mid=(low+high)/2;
    bool find=false;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==target){
            find=true;
            cout<<mid<<endl;
            break;
        }
        else if(target>arr[mid]){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    if(!find){
        cout<<-1<<endl;
    }
}

void binarySearchRecursive(vector<int> &arr,int low,int high,int target){
    if(low>high){
        cout<<-1<<endl;
        return;
    }
    int mid=(low+high)/2;
    if(arr[mid]==target){
        cout<<mid<<endl;
        return;
    }
    else if(target>arr[mid]){
        binarySearchRecursive(arr,mid+1,high,target);
    }
    else {
        binarySearchRecursive(arr,low,mid-1,target);
    }
}

void lowerBound(vector<int> &arr,int low,int high,int target){
    
    //also stl has a building function for lower_bound it's return iterator so that subtract
    //with arr.begin()
    //int index =lower_bound(arr.begin(),arr.end(),target)-arr.begin();    
    int mid=(low+high)/2;
    int ans=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans;
}
void upperBound(vector<int> &arr,int low,int high,int target){
    
    //also stl has a building function for upper_bound it's return iterator so that subtract
    //with arr.begin()
    //int index =upper_bound(arr.begin(),arr.end(),target)-arr.begin();    
    int mid=(low+high)/2;
    int ans=-1;
    while(low<=high){
        mid=(low+high)/2;
        //In Upper_bound Just remove the = assign because it's always return element 
        //which is greater than target
        if(arr[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans;
}

int lowerBound1(vector<int> &arr,int low,int high,int x){
    int mid=(low+high)/2;
    int ans=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int upperBound1(vector<int> &arr,int low,int high,int x){
        int mid=(low+high)/2;
    int ans=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
void firstLastOccurrenceIndex(vector<int> &arr,int n,int x){
       int lb=lowerBound1(arr,0,n-1,x);
       //cout<<lb;
       
       if(lb==n || arr[lb] != x){
        cout<<-1<<" "<<-1<<endl;
       }
       else {
         cout<<lb<<" "<<(upperBound1(arr,0,n-1,x)) -1<<" ";
       }
}


int SearchInRotatedArray(vector<int> &arr,int n,int x){
    int low=0;
    int high=n-1;;
    int mid=(low + high)/2;

    while(low<=high){
        mid=(low + high)/2;

        if(arr[mid]==x){
            return mid;
        }
        //IN the case our input array has duplicates

        if(arr[low]== arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }
        if(arr[low]<= arr[mid]){
            //Left half is sorted
            if(arr[low]<=x && x <=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=x && x <= arr[high]){
                low =mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int searchInRotatedSortedArray(vector<int> &arr,int n,int x){
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    int ans=INT_MAX;
    while(low<= high){
        mid=(low+high)/2;
        //A bit optimation if the array is sorted
        if(arr[low]<= arr[high]){
            ans=min(arr[low],ans);
            break;
        }
        if(arr[low]<=arr[mid]){
            ans=min(arr[low],ans);
            low=mid+1;
        }
        else{
            high=mid-1;
            ans=min(arr[mid],ans);
        }
    }
    return ans;
}

int findKRotationArray(vector<int> &arr,int n,int x){
    int low=0;
    int high = n-1;
    int mid=(low + high)/2;
    int ans=INT_MAX;
    int index=-1;
    while(low<= high){
        mid=(low+high)/2;
        //In case the array is sorteds
        if(arr[low]<=arr[high]){
            if(ans>arr[low]){
                ans = arr[low];
                index=low;
                break;
            }
        }
        if(arr[low]<=arr[high]){
            if(ans>arr[low]){
                ans=arr[low];
                index=low;
            }
            low=mid+1;
        }
        else{
            if(ans>arr[mid]){
                ans=arr[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
    return index;
}

int findElementAppearOnceInArray(vector<int> &arr,int n){
    //Base case if one element in the array
    if(n==1)return arr[0];
    for(int i=0;i<n;i++){
        if(i==0){
            if(arr[i]!= arr[i+1])return arr[i];
        }
        else if(i==n-1){
            if(arr[i]!= arr[i-1])return arr[i];
        }
        else{
            if(arr[i]!= arr[i+1] && arr[i]!= arr[i-1])return arr[i];
        }
    }
    return -1;
}
int findElementAppearOnceInArrays(vector<int> &arr,int n){
    if(n==1)return arr[0];
    if(arr[0]!=arr[1])return arr[0];
    if(arr[n-1]!= arr[n-2])return arr[n-1];
    int low=1;
    int high=n-2;

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]!= arr[mid-1] && arr[mid]!= arr[mid+1]){
            return arr[mid];
        }
        else if(mid % 2== 0 && arr[mid]== arr[mid+1] || mid%2 ==1 && arr[mid]==arr[mid-1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return -1;
}

int findPeak(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        if((i==0 || arr[i-1]<arr[i] )&& (i==n-1 || arr[i+1]<arr[i])){
            return arr[i];
        }
    }
    return -1;
}

int findSqrtNumber(int n){
        int ans=1;
        for(int i=1;i<=n;i++){
            if(i*i<=n){
                ans=i;
            }else{
                break;
            }
        }
        return ans;

}

int findSqrtNumberBinarySearch(int n){
    int low =0;
    int high=n;
    int ans=1;
    while(low<=high){
        int mid=(low+high)/2;
        if((mid*mid)<=n){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int find(int num,int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*num;
    }
    //cout<<ans<<endl;
    return ans;
}
int findNthRoot(int n,int m){
    for(int i=1;i<=m;i++){
        if(find(i,n)==m){
            return i;
        }
        else if(find(i,n)> m){
            break;
        }
    }
    return -1;
}
int findNthRootBinarySearch(int n,int m){
    int low=1;
    int high=m;
    while(low<=high){
        int mid=(low+high)/2;

        if(find(mid,n)==m){
            return mid;
        }
        else if(find(mid,n)>m){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return -1;
}

int EatPerHour(vector<int> &arr,int hourly){
    int totalBananaEat=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        totalBananaEat+=ceil((double)arr[i]/hourly);
    }
    return totalBananaEat;
}
int cocoEatBanana(vector<int> &arr,int h){
    auto it =max_element(arr.begin(),arr.end());
    int n=*it;
    for(int i=1;i<=n;i++){
        //cout<<i<<endl;
        int eatBanana=EatPerHour(arr,i);
        //cout<<eatBanana<<endl;
        if(eatBanana<=h){
           // cout<<"Done";
            return i;
        }
    }
    return -1;
}
int cocoEatBanana1(vector<int> &arr,int h){
    int low=0;
    int high= *max_element(arr.begin(),arr.end());
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        int eatBanana=EatPerHour(arr,mid);
        if(eatBanana<=h){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

bool isPossible(vector<int> &arr,int day,int m,int k){
    int count=0;
    int numberOfBoks=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            count++;
        }
        else{
            numberOfBoks +=(count/k);
            count=0;
        }
    }
    numberOfBoks +=(count/k);
    //cout<<numberOfBoks<<endl;
    if(numberOfBoks>=m)return true;
    else{
        return false;
    }
}
int bloomFlowers(vector<int> &arr,int m,int k){
    //m is number of bokies
    //k is a consecquative flowers
    
    int mini= *min_element(arr.begin(),arr.end());
    int maxi= *max_element(arr.begin(),arr.end());

    for(int i=mini;i<=maxi;i++){
        if(isPossible(arr,i,m,k)){
            return i;
        }
    }
    return -1;
}

bool isPossible1(vector<int> &arr,int distance,int cows){
    int last=arr[0];
    int placeCow=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]-last>=distance){
            placeCow++;
            last=arr[i];
        }
    }
    //cout<<distance<<" : "<<placeCow<<endl;
   // cout<<placeCow<<endl;
    if(placeCow>=cows){
        return true;
    }else{
        return false;
    }
}
int aggressiveCow(vector<int> &arr,int cows){
    int maxi= *max_element(arr.begin(),arr.end());
    int mini= *min_element(arr.begin(),arr.end());
    for(int i=1;i<=(maxi-mini);i++){
        //cout<<i<<endl;
        if(isPossible1(arr,i,cows)){
            continue;
            
        }
        else{
            return i-1;
        }
    }
}

int aggessiveCowBinarySearch(vector<int> &arr,int cows){
    int low=1;
    int maxi= *max_element(arr.begin(),arr.end());
    int mini= *min_element(arr.begin(),arr.end());
    int high=maxi-mini;
    while(low<=high){ 
        int mid=(low+high)/2;
        if(isPossible1(arr,mid,cows)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}
int main(){
    int n,cows;
    cin>>n>>cows;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<aggessiveCowBinarySearch(arr,cows);
    return 0;
} 