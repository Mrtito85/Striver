#include <iostream>
#include <algorithm>
#include <math.h>
#include <list>

using namespace std;

void count(int n){
    int cnt=0;
    while(n>0){
        int digit=n%10;
        cnt++;
        n=n/10;
    }
    cout<<cnt<<endl;
}

void reverseDigit(int n){
    int revNumber=0;
    while(n>0){
        int digit=n%10;
        revNumber = (revNumber*10)+digit;
        n=n/10;
    }
    cout<<revNumber<<endl;
}

string checkPal(int n){
    int number=n;
            int revNumber=0;
        while(n>0){
            int digit=n%10;
            revNumber = (revNumber*10)+digit;
            n=n/10;
        }
        //cout<<revNumber<<endl;
        if(revNumber==number){
            return "True";
        }else{
            return "False";
        }
}

string armStrongNumber(int n){
        int number=n;
            int sum=0;
        while(n>0){
            int digit=n%10;
            sum = sum + (digit*digit*digit);
            n=n/10;
        }
        //cout<<revNumber<<endl;
        if(sum==number){
            return "True";
        }else{
            return "False";
        }
}

void printAllDivisor(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
} 

void printAllDivisorMath(int n){
    //Here i will priint all the divisor in bigO(Sqrt(N)) Time Complexity
    //here declaring a list to to store
    list<int> l;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            l.push_back(i);
            if(n/i != i){
                l.push_back(n/i);
            }
        }
    }

    // sort(l.begin(),l.end()); return error becasue don't return random iterator
    l.sort();
    for(auto i:l){
        cout<<i<<" ";
    }
}

void GCDorHCF(int n1,int n2){
    //Here is the time complexity of minimum of(n1,n2) in worst case
    for(int i=min(n1,n2);i>=1;i--){
        if(n1%i==0 && n2%i==0){
            cout<<i<<endl;
            break;
        }
    }
}

void GCDEuclideanAlgorithm(int n1,int n2){
     //Eucldean algorithm is  mathically proved so that here is the time complexity of 
     //Big O(log base phi min of (n1,n2))
    while(n1>0 && n2 > 0){
        if(n1>n2){
            n1=n1%n2;
        }
        else{
            n2=n2%n1;
        }
    }
    if(n1==0){
        cout<<n2;
    }
    else {
        cout<<n1;
    }
    
}

int main(){
    int n1,n2;
    cin>>n1>>n2;

    GCDEuclideanAlgorithm(n1,n2);
    return 0;
}