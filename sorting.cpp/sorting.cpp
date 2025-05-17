#include <iostream>
using namespace std;

//Here is the time complexity of BigO(N*N)or(n*(n+1)/2)
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }

        int temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

//In Averge the the array has Linear Time Complexity
void bubbleSort1(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        bool inside=0;
        for(int j=0;j<i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                inside=1;
            }
        }
        if(inside==0)break;
    }
}

//Here is the time complexity of BigO(N*N) in worst case 
void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}


int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}