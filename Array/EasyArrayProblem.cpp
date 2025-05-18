#include <iostream>
#include <climits>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
using namespace std;


void findLargest(int arr[],int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    cout<<"Maximum element is "<<maxi<<endl;
}

void findSecondLargest(int arr[],int n){
    sort(arr,arr+n);
    int largest=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]!=largest){
            cout<<"Second Largest is "<<arr[i]<<endl;
            break;
        }
    }

}
void findSecondLargest1(int arr[],int n){
    int largest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    int secondLargest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] != largest && arr[i] >secondLargest){
            secondLargest=arr[i];
        }
    }

    cout<<"Second Largest is "<<secondLargest<<endl;
}
void findSecondLargest2(int arr[],int n){
    int largest=arr[0];
    int SecondLargest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            SecondLargest=largest;
            largest=arr[i];
        }
        if(arr[i]>SecondLargest && arr[i]!= largest){
            SecondLargest = arr[i];
        }
    }
    cout<<"Second Largest is "<<SecondLargest<<endl;
}

void findSecondSmallest(int arr[],int n){
    int smallest =arr[0];
    int secondSmallest= INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            secondSmallest=smallest;
            smallest=arr[i];
        }
        if(arr[i] < secondSmallest && arr[i] != smallest){
            secondSmallest=arr[i];
        }
    }

    cout<<"The second Smallest "<<secondSmallest<<endl;
}

void removeDuplicatesSortedArray(int arr[],int n){
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    cout<<"Size of Array "<<st.size();

}

void removeDuplicatesSortedArray1(int arr[],int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            i++;
            arr[i]=arr[j];
        }
    }
    cout<<"The size of Array "<<i+1<<endl;
}

void rotateArray1Place(int arr[],int n){
    //Here store the element

    int temp=arr[0];
    for(int i=1;i<n;i++){
        //Shifted back 1 place
        arr[i-1]=arr[i];
    }
    //Add it to the back
    arr[n-1]=temp;
}

//Here using extra array of size d and time complexity is BigO(2N) in worst case
void rotateArrayDplaces(int arr[],int n,int d){
    
    //here taking mode if value of d is greater than n
    d=d%n;
    //Here store the element
    vector<int> temp;
    for(int i=0;i<d;i++){
        temp.push_back(arr[i]);
    }
    //move back element
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    //insert at end
    int index=0;
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }


}

//not using extra space and time complexity in worst case is Big(2N)
void rotateArrayDplaces1(int arr[],int n,int d){
   
    d=d%n;

    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);

}

void moveAllNonZeroNumberToFront(int arr[],int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    int tempSize=temp.size();
    for(int i=0;i<tempSize;i++){
        arr[i]=temp[i];
    }
    for(int i=tempSize;i<n;i++){
        arr[i]=0;
    }
}

void moveAllNonZeroNumberToFront1(int arr[],int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    //here j always represent non-Zero number
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[j],arr[i]);
            j++;
        }
    }
}

void linearSearch(int arr[],int n,int element){
    bool find=false;
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            cout<<"element present at Index "<<i<<endl;
            find=true;
        }
    }
    if(!find){
        cout<<"Element Not present in the Array"<<endl;
    }
}

void UnionOfTwoArray(int arr1[],int n1,int arr2[],int n2){
    set<int> st;
    for(int i=0;i<n1;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(arr2[i]);
    }
    for(auto i:st){
        cout<<i<<" ";
    }
}

void UnionOfTwoArray1(int arr1[],int n1,int arr2[],int n2){
    int i=0;
    int j=0;
    vector<int> temp;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(temp.size()==0 ||temp.back()!= arr1[i] ){
                temp.push_back(arr1[i]);
            }
            i++;
            cout<<i<<endl;
        }
        else{
            if(temp.size()==0||temp.back()!= arr2[j]){
                temp.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i<n1){
        if(temp.back()!= arr1[i] || temp.size()==0 ){
            temp.push_back(arr1[i]);
        }
        i++;   
    }
    while(j<n2){
        if(temp.back()!= arr2[j] || temp.size()==0){
            temp.push_back(arr2[j]);
        }
        j++;
    }
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
}

void intersectionOfArray(int arr1[],int n1,int arr2[],int n2){
    vector<int> visited(n2,0);
    vector<int> ans;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]==arr2[j] && visited[j]==0){
                ans.push_back(arr1[i]);
                visited[j]=true;
                break;
            }
            if(arr2[j]>arr1[i])break;
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
}

void intersectionOfArray1(int arr1[],int n1,int arr2[],int n2){
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            i++;
        }
        if(arr1[i]>arr2[j]){
            j++;
        }
        if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
}

void findELementMissingFrom1ToN(int arr[],int n){
    for(int i=1;i<=n;i++){
        bool find=false;
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                find=true;
                break;
            }
        }
        if(find==false){
            cout<<i<<endl;
            break;
        }
    }
}

void findELementMissingFrom1ToN1(int arr[],int n){
    
    int *hash = new int[n+1];
    for(int i=0;i<n+1;i++){
        hash[i]=0;
    }

    for(int i=0;i<n;i++){
        hash[arr[i]]=1;
    }
    for(int i=1;i<n+1;i++){
        if(hash[i]==0){
            cout<<i<<endl;
        }
    }
}
void findELementMissingFrom1ToN_2(int arr[],int n){
    //Here we will give n by plus 1
    n++;
    int sum=(n*(n+1))/2;
    //cout<<"Sum is "<<sum<<endl;
    int elementSum=0;
    for(int i=0;i<n-1;i++){
        elementSum+=arr[i];
    }
    int ans = sum-elementSum;
    cout<<ans<<endl;
}
void findELementMissingFrom1ToN_3(int arr[],int n){
    int xor1=0;
    int xor2=0;
    //we will run till 1 to = n and also add 1 because we have to find the missing elemet 
    for(int i=1;i<=n+1;i++){
        xor1=xor1^i;
    }
    for(int i=0;i<n;i++){
        xor2= xor2 ^ arr[i];
    }
    int ans = xor1 ^ xor2;
    cout<<ans<<endl;
}

void maximumConsecutiveOnes(int arr[],int n){
    int maxi=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maxi=max(count,maxi);
        }
        else{
            count=0;
        }
    }
    cout<<maxi<<endl;
}


void findNumberThatAppearOnce(int arr[],int n){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==arr[i]){
                count++;
            }
        }
        if(count==1){
            cout<<arr[i]<<endl;
            break;
        }
    }
    
}
void findNumberThatAppearOnceHashing(int arr[],int n){
    int maxi=arr[0];
    for(int i=0;i<n;i++){
        maxi=max(arr[i],maxi);
    }

    //hashing arr and inilized to zero
    int *hash= new int[maxi+1];
    for(int i=0;i<maxi+1;i++){
        hash[i]=0;
    }
    //pre compute
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    //find the value that appears 1 time only
    for(int i=0;i<maxi+1;i++){
        if(hash[i]==1){
            cout<<i<<endl;
            break;
        }
    }


}
void findNumberThatAppearOnceMap(int arr[],int n){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto i:mp){
        if(i.second ==1){
            cout<<"map "<<i.first<<endl;
            break;
        }
    }
}
void findNumberTHatAppearOnceXor(int arr[],int n){
    int xor1 = 0;
    for(int i=0;i<n;i++){
        xor1= xor1 ^ arr[i];
    }
    cout<<"xor "<<xor1<<endl;
}

void longestSubarraySumOfK(int arr[],int n,int target){
    //Here is the time complexity of BigO(N*N*N)
    int length=-1;
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum += arr[k];
                cout<<arr[k]<<" ";
            }
            cout<<endl;
            if(sum==target){
                    
                length = max(length,j-i+1);
            }
        }
    }
    cout<<length<<endl;
}
void longestSubarraySumOfK1(int arr[],int n,int target){
    //Here is the time complexity of Big O(N*N) in worst case
    int len=-1;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            cout<<arr[j]<<" ";
            sum+=arr[j];
            if(sum==target){
                len=max(len,j-i+1);
            }
        }
        cout<<endl;
    }
    cout<<len<<endl;
}
void longestSubarraySumOfK2(int arr[],int n,int k){
    //THis code is optimal for postive and Negative
    int sum=0;
    map<int,int> mp;
    int len=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            len=max(len,i+1);
        }

        int rem=sum-k;
        if(mp.find(rem)!=mp.end()){
            int l=i-mp[rem];
            len=max(len,l);
        }

        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }
    }
    cout<<len<<endl;
}
void longestSubarraySumOfK3(int arr[],int n,int k){
    //Here is a optimal solution for postive and Zero subarray
    //Here time complexity in worst case is BigO(2N)
    int sum=arr[0];
    int len=0;
    int left=0;
    int right=0;
    while(right<n){
        while(sum>k && left<=right){
            sum -= arr[left];
            left++;
        }
        if(sum==k){
            len=max(len,right-left+1);
        }
        right++;
        if(right<n){
            sum+=arr[right];
        }
    }
    cout<<len<<endl;
}

int main(){
    int n,k;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    longestSubarraySumOfK3(arr,n,k);
    return 0;
}