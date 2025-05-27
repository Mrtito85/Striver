#include<iostream>
#include <climits>
#include <vector>
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


int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<searchInRotatedSortedArray(arr,n,target);

    return 0;
}