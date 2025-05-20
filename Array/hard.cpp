#include<iostream>
#include<vector>
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


int main(){
    //cout<<fact(5);
    printPascalTriangleComplete(10);
   // printPascalTriangleElement1(4,2);
   // cout<<"HI";
    return 0;
}