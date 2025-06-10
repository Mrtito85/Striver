#include <iostream>
#include <climits>
using namespace std;

/*
why print answer 10^9 + 7  Modular Arithmetic
we can't calculate factorial of 100 so that we mod M=10^9 + 7 is INT_MAX-1 and this is a prime number
how to calculate inverse of B
fact= (fact * i)%m = fact(1*2*3*4 % m )

Use:
we use mod operator where the value is to big to store in (int) or (long long) then we mod with number 

int range is 10^9+7  , 2^32
we can store ans in integer 
mutiplicative inverse applicable only for prime number so that 10 ^ 9 + 7 is prime number 
so it's ideal choice for modolo M        
*/


/*
Binary  Number's

they number containing 1 and 0 
we can convert every number to decimal and binary
1--> 1
2--> 10
3--> 11
4--> 100
5--> 101
6--> 110

we have 4 main operation  and or not xor  <<leftShift  >>rightShift
if we leftshift the number then it' mutiple the number with 2 and and
 bit 0 to the left side

using 4 bits i can make a number 2^4   --> 16   0 to 15 number it's 
mean total 16 number can make

Integeter can only hold 2^31 -1 number because it's a sign integer and the last 
bit is rezireved for negative number and we
add -1 becaues the number is starting from 0

cout << ((1LL << 31) - 1) << endl;

unsign int range is double than the sign integer because it's stores only 
positive number and we have 2^32 bit and store number for 0 to 2^32 -1
*/

/*
Set bit , unset bit , count bit

we can index bit's from Right to left
010

0bit
1 bit 
2 bit 

right bit is Least significant bit lsb
left bit is most significant bit  
  --> opertion remove lsb or msb

set bit  = 1
unset bit = 0

count the set bits question

how to check ith bit of number is set or not

5 binary is 
check first bit is set or not

101
make number 010
101 & 010  
if the & is 1 then mean the bit is set the number is 1
only if 1 bit is set then the and is non-zero

int a=5;
a=a& (1<<ith);
if(a!= 0){
    the bit is set
}
else{
    the bit is not set
}
    //code

    printBinary(10);
    int a=10; // 3th bit of 10 is set it's mean it's 1
    //checking making a number which has 1 at it's 3th or ith position and and all other are zer
    a=a& (1<<3);
    if(a!=0){
        cout<<"The bit is set"<<endl;
    }
    else{
        cout<<"the bit is not set";
    }


    Set the ith bit to 1 
    . to set the ith bit to set we can | with number
        //set a bit to 1
    //Here i'm going to set the first 2 bit of 10 to 1
    //10 has binary 0000001010
    //i need a      0000000100
*/


/*
        odd and even divide and multiple , lower case ,upper case ,lsb,msb

    every odd number has 0th bit 1
    every even number has 0th bit 0 
    if we take & with 1 then if it's true then the number is odd
    else even

    & is fast as compare to Mod operator

    right shift >> divide by 2
    left shift << multiply by 2

    In lower case 5th bit is set to 1 --> 00000100000 ' ' set to bit to 1 for upper case

    In Upper case 5th bit set to 0    ---> unset bit to lower caes   11111011111  & with '_'
*/

/*
intersecton using bits
[2,3]  make a bit    1100
[1,2,3]              1110
[1,3]                1010

to represent food we will take bit
int has 32 bit 
long long has 64 bits
fruits must be less than 64 

*/
void printBinary(int num){
    for(int i=10;i>=0;i--){
        cout<<((num >> i)& 1); 
    }
}
void input(){

    printBinary(10);
    int a=10; // 3th bit of 10 is set it's mean it's 1
//     //checking making a number which has 1 at it's 3th or ith position and and all other are zer
//    // a=a& (1<<3);
//     if(a!=0){
//       //  cout<<"The bit is set"<<endl;
//     }
//     else{
//        // cout<<"the bit is not set";
//     }

    //set a bit to 1
    //Here i'm going to set the first 2 bit of 10 to 1
    //10 has binary 0000001010
    //i need a      0000000100

    a=a| (1<<2);
    cout<<endl;
    printBinary(a);

    //what if i have unset bit i have to & the   number with bitmask
    // 1<<ith     000001000 than take not ~ of number to reverse all the bits
    //and than & with the target number 111110111 this number will unset the bit
    //after proforming & operation
    int n=10;
    //unset the 3rd  bit
    int mask=~(1<<3);
    n=(n&mask);
     //answer is 2
     cout<<endl;
     printBinary(n);
     cout<<endl ;
     cout<<n<<endl;

     n=10;
     //if we want to toggle any bit then have to zor with that bit
     n=n^(1<<1);
     printBinary(n);
// //fact= (fact * i)%m       =((1*2*3*4 % m)* (5%m) )%m
// cout<<INT_MAX<<endl;//2147483647
// int m=2147483647;
// cout<<m<<"hi1"<<endl;
// //cout<<long long((1<<31)-1)<<endl;

// cout << ((1LL << 31) - 1) << endl;  // C++ style cast
}

/*
binary Exponentiation

we can calculate pow using power function also 
run a for loop for int
int a;
int b;
cin>>a>>b;
int ans=1;
for (int i=0;i<b;i++){
    ans=ans*a;
    //if i want i can mod the number
}

*/



int BinaryExponentiation(int a,int b){
    //base case 
    if(b==0)return 1;

    //i don't want multiple recursive call so that i can here call single time
    //and store it in varibale
    int res=BinaryExponentiation(a,b/2);

    if(b&1){
        return a * res* res;
    }
    else{
        //if the b is postive
        return res * res;
    }
}


int main(){


int a=2;
int b=3;
cout<<"Pow of A^B "<<BinaryExponentiation(a,b)<<endl;


//printing 1st 10 number bit's
for(int i=0;i<=10;i++){
    printBinary(i);
    if(i&1){
        cout<<" odd";
    }else{
        cout<<" even";
    }
    cout<<endl;
}

// for(int i='a';i<='e';i++){
//     printBinary(i);
//     cout<<endl;
// }
// for(int i='A';i<='E';i++){
//     printBinary(i);
//     cout<<endl;
// }
//Unset the bit
char ch=('a' & (~(1<<5)));//'_'
cout<<ch<<endl;
//set bit
char cap=('A'| (1<<5));//' '
cout<<cap<<endl;
printBinary(ch);
cout<<endl;
printBinary('_');
}