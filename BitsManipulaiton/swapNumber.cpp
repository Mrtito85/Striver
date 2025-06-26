#include <iostream>
using namespace std;

int main(){
    int a=5;
    int b=3;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"a "<<a<<endl;
    cout<<"b "<<b<<endl;

    //Check the i th bit is set or not
    int number=6;
    int i=2;
    int mask=1<<i;
    cout<<(number&mask)<<endl;
    //set the ith bit to 1
    number=5;
    i=1;
    cout<<(number | (1<<i))<<endl;
    //set the ith bit to zero
    number=7;
    i=1;
    cout<<(number & ~(1<<i))<<endl;
    //flip the ith bit
    number=5;
    i=1;
    cout<<(number ^ (1<<i))<<endl;

    //unset the first bit of number
    number=5;
    cout<<(number & (number-1))<<endl;
    //check number is power of 2 because power of 2 number has only 1 set bit the & with it's n-1 number is zero
    number=8;
    cout<<(number & (number -1));
    return 0;
}