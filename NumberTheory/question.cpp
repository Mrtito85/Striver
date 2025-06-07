#include <iostream>
#include <math.h>
#include<string>
using namespace std;

//every odd number has last bit 1
//we have and,or,not ,xor operator ,leftshit << multiply (add zero to left) , rightshift >> divide
//we have lSB-> least sigficant bit ,MSB-> most significant  bit
//set bit mean 1
//Unset bit mean the bit is 0
//set bit count mean count all the bit from number which is 1----> 10001101 ---> 4 set bit 
// the number before 2 powers -1 is always has all the bits 1
//1<<0 =1 
//1<<1 = 10
//1<<2= 100
//1<<3 =1000 binary

void binary(int n){
    for(int i=10;i>=0;i--){
        cout<<((n>>i) & 1);
    }
}

long long fact(int n){
   long long factorial=1;
   for(int i=1;i<=n;i++){
    factorial=(factorial * i)% 1000000000 + 7;//this is a prime number 
   } 
   return factorial;
}

void binaryToDecimal(int number){
    int base=1;
    int decimal=0;
    while(number >0){
        int lastDigit=number%10;
        decimal+=lastDigit*base;
        base *=2;
        number=number/10;
    }
    cout<<decimal<<endl;

}
void decimalToBinary(int number){
    if(number==0)cout<<"0";
    string ans="";
    while(number!=0){
        ans =  to_string((number%2)) + ans;
        number=number/2;
    }
    cout<<ans<<endl;
}

void printBinary(int num){
    // Right-shifting num by i bits (num >> i)

    // Masking the least significant bit (& 1)

    // Printing the result (0 or 1)
    //if we left shift 10 by 10 places the number become zero because the first 3 bits are making 10 -->1010  starting from zero bit

    for(int i=10;i>=0;i--){
        cout<<((num>>i)& 1);
    }
    cout<<endl;

}
void checkEvenOrOdd(int num){
    cout<<endl;
    if(num&1==0){
        cout<<"The Number is Even";
    }else{
        cout<<"Odd";
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        printBinary(i);
    }
    
    checkEvenOrOdd(121);

    //cout<<fact(21);
    // int number= 2147483648;//why can't i store 2power31 in integer because it's 2power 32 range
    //cout<<number;
   // binaryToDecimal(100);
  // decimalToBinary(10);
//   binary(10);
//   int a=10;
//   int i=9;
//   if((a & (1<<i)) !=0 ){
//     cout<<"Bit is set"<<endl;
//   }
//   else{
//     cout<<"Bit is Not Set"<<endl;
//   }

}