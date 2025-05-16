#include <iostream>
using namespace std;



void doSomething(int &num){
    num++;
    cout<<num<<endl;
}
int main(){

    int num=10;
    doSomething(num);
    cout<<num<<endl;
    // long long arr[5];
    // for(int i=0;i<5;i++){
    //     cin>>arr[i];
    // }
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }

    // string name="zahid";
    // cout<<name[name.size()-1];
    return 0;
}