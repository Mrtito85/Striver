#include <iostream>
using namespace std;

//Here is the time complexity in worst case is BigO(N) and space complexity in stack
//is Big O(N) it's a hypothical memory usage in stack
void printName5Time(int n){
    if(n==5){
        return ;
    }
    n++;
    cout<<"zahid"<< n<<endl;
    printName5Time(n);
}

void printCounting1to5(int n){
    if(n>=5){
        return;
    }
    n++;
    cout<<n<<endl;
    printCounting1to5(n);
}
void printCounting5to1(int n){
    if(n<=1){
        return;
    }
    n--;
    cout<<n<<endl;
    printCounting5to1(n);
}

void printCounting1to5BackTracking(int n){
    if(n<=1){
        return;
    }
    n--;

    printCounting1to5BackTracking(n);
    //Here using backtracking
    cout<<n<<endl;
}

void printCounting5To1BackTracking(int n){
    if(n>=5){
        return;
    }
    n++;

    printCounting5To1BackTracking(n);
    //Here using backtracking
    cout<<n<<endl;
}

void sumOfNaturalNumber(int i,int n,int sum){
    if(i>n){
        cout<<sum<<endl;
        return;
    }
    sum+=i;
    sumOfNaturalNumber(i+1,n,sum);

}
int sumNaturalNum(int n){
    if(n>5){
        return 0;
    }
    return n + sumNaturalNum(n+1);
    
}

int fact(int n){
    if(n==0)return 1;
    return n*fact(n-1);
}

void reverseArr(int arr[],int l,int r){
    if(l>=r)return;
    swap(arr[l],arr[r]);
    reverseArr(arr,l+1,r-1);
}

void reverseStr(string &name,int l,int r){
    //Here string is pass by value
    if(l>=r)return;
    swap(name[l],name[r]);
    reverseStr(name,l+1,r-1);
}

string checkPal(string name,int l,int r){
    //Here is the time complexity is Big O(n/2)
    if(l>=r){
        return "true";
    }
    if(name[l]!= name[r])return "false";
    return checkPal(name,l+1,r-1);
}

int fibonacci(int n){
    if(n==0 || n==1)return n;
    return fibonacci(n-1)+fibonacci(n-2);
}
int fib(int n,int a,int b){
    if(n==0)return a;
    if(n==1)return b;
    return fib(n-1,a,b) + fib(n-2,a,b);
}

void explainHashing(){
    int n;
    cin>>n;
    int* arr = new int[n]; // dynamically allocate array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //In main function you can only declare the array of 10power6 elements 
    //just 1 lakh 
    //But in globly  we can store 10 power 7 elements
    //like 1 million elements
    
    //Hashing
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int t;
    cout<<"Enter the value ";
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<"element "<<hash[n]<<endl;

    }
   
}
int main(){


    return 0;
}