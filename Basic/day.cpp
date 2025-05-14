#include <iostream>
using namespace std;

int main(){
    int day;
    cin>>day;
    switch(day){
        case 1:
        cout<<"Monday"<<endl;
        break;
        case 2:
        cout<<"Tuesday"<<endl;
        break;
        case 3:
        cout<<"Wednesday"<<endl;
        cout<<"This is day 3";
        break;
        default:
        cout<<"Didn't find any day"<<endl;
    }
    return 0;
}