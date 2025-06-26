#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;

void printBinary(int n){

    vector<int> ans;
    int i=0;
    int result=0;
    int power=1;
    while(n>0){
        int digit=n&1;
        ans.push_back(digit);
       // result=result +(digit * pow(10,i));
       result=result+(digit * power);
       power *=10;

      //  i++;
        n=n>>1;
    }
    cout<<result<<endl;
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}
void printBinaryAsDecimal(int n) {
    int result = 0;
    int i = 0;
    int place=1;

    while (n > 0) {
        int digit = n % 2;             // Get the last binary digit
        result += digit * place;  // Place digit in correct position
        place *=10;
        i++;                           // Move to the next power of 10
        n = n / 2;                     // Shift right in binary
    }

    cout << "Binary as decimal integer: " << result << endl;
}

void binaryToDecimal(int n){
    int ans=0;
    int place=1;
    while(n>0){
        //get digit
        int digit=n%10;
        ans=ans+(digit * place);
        place*=2;
        n=n/10;
    }
    cout<<ans<<endl;
}
void countBinary(int n){
    int ans=0;
    while(n>0){
        int digit=n&1;
        if(digit){
            ans++;
        }
        n=n>>1;
    }
    cout<<ans<<endl;
}

int main(){

    int n;
    cin>>n;
    countBinary(n);
    printBinary(n);
    printBinaryAsDecimal(n);
    cout<<endl;
    int binary=111;
    binaryToDecimal(binary);
    return 0;
}