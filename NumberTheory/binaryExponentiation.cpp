#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int M =1e9+7;


/*
we calculate the power of a^b 
first calculate the bit's in b
let suppose a=2
and b=13 ----> the binary of 13 is 1101

*/



void binaryExponentiation(int a,int b){
    int ans =1;

    while(b){
        if(b&1){
            ans=(ans* 1LL*a)%M; //basically all the calcuation are in long long and while storing the answer convert to int with M mod
        }
        a=(a *1LL* a)%M;
        b=(b>>1);
    }
    cout<<ans;

}   


/*
print all divisor of number N

Approach 1
we can just iterate for 1 to that N 
check  N%i==0
if it's true then it's mean the ith number is divisiable by N and add to our answer
*/

void printDivisor(int N){
    int count=0;
    int sum=0;
    for(int i=1;i<=N;i++){
        if(N%i==0){
            //it's mean number is diviable
            cout<<i<<" ";
            count++;
            sum+=i;
        }
    }
    cout<<endl;
    cout<<"count "<<count<<endl;
    cout<<"Sum "<<sum<<endl;
}
/*
print Divisor the BigO(N)
Now going to opptimise in Big Sqrt(n)
lets calculate the divisor for 36

1 * 36
2 * 18
3 * 12
4 * 9
6 * 6 ----> add one to answer base case check if i==n/i then add one of them 
Repeatation start
9 * 4
12 * 3
18 * 2
31 * 1

Here are the all divisor of 36 , Notice one thing after 6 or sqrt(N) the are going to repeat 
in opposite order 
*/

void printDivisorSqrt(int n){
    int count=0;
    int sum=0;
    vector<int> ans;
    for(int i=1;i*i <=n;i++){
        if(n%i==0){
            ans.push_back(i);
            count++;
            sum+=i;

            if(i==n/i){
                //do nothing
            }else{
               ans.push_back(n/i);
                count++;
                sum+=n/i;
            }

        }
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"count "<<count<<endl;
    cout<<"Sum "<<sum<<endl;

}

int main(){
    int a,b;
    cin>>a>>b;

    binaryExponentiation(a,b);
    cout<<endl;
    printDivisor(10);
    cout<<endl;
    printDivisorSqrt(10);
    //cout<<pow(2,13);
    return 0;
}