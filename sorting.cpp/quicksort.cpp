#include <iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[j],arr[low]);
    return j;
}

void qs(int arr[],int low,int high){
    if(low<high){
        int pivot= partition(arr,low,high);
        qs(arr,low,pivot-1);
        qs(arr,pivot+1,high);
    }
}

void quicksort(int arr[],int n){
    int low=0;
    int high=n-1;
    qs(arr,low,high);

}

int main(){

    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}