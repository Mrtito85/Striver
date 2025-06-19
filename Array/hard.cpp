#include<iostream>
#include<vector>
#include <set>
#include<map>
#include<algorithm>
#include <climits>
using namespace std;

//ncr  ==> N! / r! *(n-r)!

int fact(int n){
    int factNum=1;
    for(int i=1;i<=n;i++){
        factNum *=i;
    }
  return factNum;
}

void printPascalTriagleElement(int n,int r){
    //Here is the brute force using NCR
    int ans=fact(n) / (fact(r) *        (n - r));
    cout<<ans<<endl;
}
void printPascalTriangleElement1(int  n,int r){ 
   //Here is brute force run in BigO(R) time complexiy also take result in long long
   
    long long  result=1;
    for(int i=0;i<r;i++){
        result =result*(n-i);
        result=result/(i+1);
    }
    cout<<result<<" ";
}

void printPascalTriangleRow(int n){
    for(int i=1;i<=n;i++){
        printPascalTriangleElement1(n-1,i-1);
    }
    
}
void printPascalTriangleRow1(int n){
    int ans=1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
        ans=ans*(n-i);
        ans=ans/i;
        cout<<ans<<" ";
    }
}

void printPascalTriangleComplete(int n){
    for(int i=1;i<=n;i++){
        printPascalTriangleRow1(i);
        cout<<endl;
    }
}

void majorityElement(vector<int> &arr,int n){
    vector<int> ans;
    //if the element is appear more than n/3 then print it

    for(int i=0;i<n;i++){
        int element=arr[i];
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==element){
                count++;
            }
        }
        if(count>n/3){
            if(ans.empty() || ans[ans.size()-1]!=element )
                ans.push_back(element);
        }
        if(ans.size()>=2){
            break;
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
}
void majorityElementHashing(vector<int> &arr,int n){
    map<int,int> mp;
    set<int> st;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        if(mp[arr[i]]==n/3){
         //st.insert(arr[i]);   
         cout<<arr[i];
        }
    }
    for(auto i:st){
        cout<<i<<" ";
    }
   // cout<<"Hi";


}
void mahorityElementMoreVoteAlgorithm(vector<int> &arr,int n){
    int count1=0;
    int count2=0;
    int element1=INT_MIN;
    int element2=INT_MIN;
    for(int i=0;i<n;i++){
        if(count1==0 && element2!= arr[i]){
            count1=1;
            element1=arr[i];
        }else if(count2==0 && element1 != arr[i]){
            count2=1;
            element2 = arr[i];
        }
        else if(arr[i] == element1){
            count1++;
        }else if(arr[i]==element2){
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }

    count1=0;
    count2=0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[i]==element1){
            count1++;
        }
        if(arr[i]==element2){
            count2++;
        }
    }
    if(count1>n/3){
        ans.push_back(element1);
    }
    if(count2>n/3){
        ans.push_back(element2);
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i<<" ";
    }
}

void ThreeSum(vector<int> &arr,int n){
    set<vector<int>> st;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> ans;
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                    ans.push_back(arr[k]);
                    sort(ans.begin(),ans.end());
                    st.insert(ans);
                   // cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                }
            }
        }
    }
    vector<vector<int>> ans (st.begin(),st.end());
}
void ThreeSumHashing(vector<int> &arr,int n){
    
    //Here the time complexity in worst case is N*N and log n in set at worst case
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hash;
        for(int j=i+1;j<n;j++){
            int third=-(arr[i]+arr[j]);
            if(hash.find(third)!= hash.end()){
                vector<int> ans ={arr[i],arr[j],third};
                sort(ans.begin(),ans.end());
                st.insert(ans);
                
            }
           hash.insert(arr[j]);
        }
    }

    for(auto i:st){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
   // cout<<"HI";
}
void ThreeSumPointer(vector<int> &arr,int n){
    vector<vector<int>> ans;
    //here sort the array first because we don't require duplicates
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<n;i++){
        //Here check duplicates for I index
        if(i>0 && arr[i-1]==arr[i])continue;

        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>0){
                k--;
            }else if(sum< 0){
                j++;
            }else {
                //Here we print
                vector<int> temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                //Here check for duplicates if present 
                while(j<k && arr[j]==arr[j-1])j++;
                while(j<k && arr[k]==arr[k+1])k--;
            }
        }
    }

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
   // cout<<"thanks";
}

vector<vector<int>> fourSum(vector<int>& arr, int target) {
     //Brute-force 4 loops	O(n⁴) → 200⁴ = 1.6 * 10⁹ ops	⚠️ Too slow (TLE likely)

    set<vector<int>> ans;
            int n=arr.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        for(int l=k+1;l<n;l++){
                            long long sum= arr[i]+arr[j];
                            sum+=arr[k];
                            sum+=arr[l];

                            if(sum==target){
                                vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                                sort(temp.begin(),temp.end());
                                ans.insert(temp);
                            }
                        }
                    }
                }
            }
            vector<vector<int>> ansFinal(ans.begin(),ans.end());
            return ansFinal;
    }
void fourSumHashing(vector<int> &arr,int target){
    //3 loops + HashSet	O(n³) → ~8 million ops	✅ Acceptable
    int n=arr.size();
    set<vector<int>> st;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hash;
            for(int k=j+1;k<n;k++){
                
                long long sum=arr[i]+arr[j];
                sum+=arr[k];
                int fourth=target-(sum);
                if(hash.find(fourth)!=hash.end()){
                    vector<int> temp={arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    
                }

                hash.insert(arr[k]);
            }
        }
    }
    for(auto  i:st){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void fourSumTwoPointer(vector<int> &arr,int target){
    int n=arr.size();
    vector<vector<int>> ans;

    //sort the array  becasuse using two pointer approach
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        //Here check for duplicates
        if(i>0 && arr[i]==arr[i-1])continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1])continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                int sum=arr[i]+arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if(sum==target){
                    vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k< l && arr[k]==arr[k-1])k++;
                    while(k<l && arr[l]==arr[l+1])l--;
                }else if(sum>target){
                    l--;
                }else if(sum<target){
                    k++;
                }
            }
        }
    }

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void numberOfSubarrayWithXorK(vector<int> &arr,int target){
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xor1 = 0;
            for(int k=i;k<=j;k++){
                xor1 =xor1 ^ arr[k];
            }
            if(xor1 == target){
                count++;
            }
        }
    }
    cout<<count<<endl;
}
void numberOfSubbarywithXork1(vector<int> &arr,int n,int target){
    int count =0;
    for(int i=0;i<n;i++){
        int XOR1=0;
        //int sum=0;
        for(int j=i;j<n;j++){
            XOR1=XOR1 ^ arr[j];
            if(XOR1 ==target){
                count++;
               // cout<<"!";
            }
        }
    }
    cout<<count<<endl;
}
void numeberOfSubarrayWithXorK2(vector<int> &arr,int n,int target){
    map<int,int> mp;
    int xr=0;
    mp[xr]++;
    int count=0;
    for(int i=0;i<n;i++){
        //Base case rememebr we have to make ^ not plus
        xr = xr ^ arr[i];
        //Here also xor with remeaining target
        int x=xr ^ target;

        count += mp[x];

        //insert to map
        mp[xr]++;
    }
    cout<<count<<endl;
}

void mergeOverLappingSubIntervel(vector<vector<int>> &arr,int n,int m){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];
        if(ans.empty()==false && end<=ans.back()[1]){
            continue;
        }

        for(int j=i+1;j<n;j++){
            //Here is the base case
            if(end>=arr[j][0]){
                end=max(arr[j][1],end);
            }else {
                break;
            }
        }
        ans.push_back({start,end});

    }
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void mergeOverLappingSubInterval1(vector<vector<int>> &arr,int n,int m){

    vector<vector<int>> ans;
    for(int i= 0;i<n;i++){
            if(ans.empty() || ans.back()[1]<arr[i][0]){
                ans.push_back(arr[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],arr[i][1]);
            }
    }
        for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    
    }
    
}

void mergeTwoArraySortedArray(vector<int> &arr1,vector<int> &arr2,int n1,int n2){
    int left=0;
    int right=0;
    vector<int> temp;

    while(left<n1 && right <n2){
        if(arr1[left]<arr2[right]){
            temp.push_back(arr1[left]);
            left++;
        }
        else{
            temp.push_back(arr2[right]);
            right++;
        }
    }

    //One portion left from both arrays
    while(left<n1){
        temp.push_back(arr1[left++]);
    }
    while(right<n2){
        temp.push_back(arr2[right++]);
    }


    for(int i=0;i<temp.size();i++){
        if(i<n1)arr1[i]=temp[i];
        else{
            arr2[i-n1]=temp[i];
        }
    }
    for(auto i:arr1){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:arr2){
        cout<<i<<" ";
    }
}

void mergeTwoSortedArray(vector<int> &arr1,vector<int> &arr2,int n1,int n2){
    int left=n1-1;
    int right=0;
    while(left>=0 && right<n2){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }else{
            //do not need to do anying
            break;
        }
    }
    //then sort the array
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    for(auto i:arr1){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:arr2){
        cout<<i<<" ";
    }

}

void countMissingAndRepeatingNumber(vector<int> &arr,int n){
    int repeating=-1;
    int missing =-1;
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i == arr[j]){
                count++;
            }
        }
        if(count==2){
            repeating=i;
        }
        if(count==0){
            missing=i;
        }
        if(repeating != -1 && missing != -1)break;
    }
    cout<<"Missing Number is "<<missing<<endl;
    cout<<"Repeating Number is "<<repeating<<endl;
}
void countMissingAndRepeatingNumberHashing(vector<int> &arr,int n){
    vector<int> hash(n+1,0);
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int repeating=-1;
    int missing=-1;
    for(int i=1;i<hash.size();i++){
        if(hash[i]==0){
            missing=i;
        }
        if(hash[i]==2){
            repeating=i;
        }
        if(missing != -1 && repeating != -1){
            break;
        }
    }
    cout<<missing<<" "<<repeating<<endl;
}

 void inversonCount(vector<int> &arr,int n){
   //Here i < j condition 
    int count=0;
    for(int i= 0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    cout<<"Inversion Count is "<<count<<endl;   
 }
int COUNT=0;
 void merge(int arr[],int l,int mid,int h){
    vector<int> temp;

    int left=l;
    int right=mid+1;

    while(left<=mid && right<=h){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            //Here we are in the right part
            COUNT+=mid-left+1;
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++; 
    }
    while(right<=h){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }

}

void mergeSort(int arr[],int l,int h){
    if(l>=h)return;
    int mid=(l+h)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);
    merge(arr,l,mid,h);
}

void InversonCount1(int arr[],int n){
    int l=0;
    int h=n-1;
    mergeSort(arr,l,h);
  //  cout<<"Inversion Count is "<<COUNT<<endl;
}


void countPair(vector<int> &arr,int low,int mid,int high){
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i] > (long long)2*arr[right]){
            right++;
        }
        COUNT+=(right -(mid+1));
    }
}
void reversePair(vector<int> &arr,int n){
    int count=0;
    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]> 2*arr[j]){
                count++;
            }
        }
    }
    cout<<"reverse count "<<count<<endl;
} 

void maximumProductSubarray(vector<int> &arr,int n){
    int maxProduct=INT_MIN;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int product=1;
            for(int k=i;k<=j;k++){
                product *= arr[k];
                maxProduct = max(maxProduct,product);
            }
        }
    }
    cout<<maxProduct;
}

void maximumProductSubarray1(vector<int> &arr,int n){
    int prefix=1;
    int suffix=1;
    int maxProduct=INT_MIN;

    for(int i=0;i<n;i++){
        if(prefix==0)prefix=1;
        if(suffix==0)suffix=1;

        prefix *=arr[i];
        suffix *=arr[n-i-1];

        maxProduct = max(maxProduct,max(prefix,suffix));
    }
    cout<<maxProduct<<endl;
}



int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maximumProductSubarray1(arr,n);
    

    return 0;
}