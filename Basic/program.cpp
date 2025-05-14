

#include <iostream>
#include <string>
using namespace std;
 
int main(){
//Here you will enter your marks and i will give you a rank
while(1){
int mark;
cin>>mark;
if(mark>=80 && mark<=100){
    cout<<"A"<<endl;
}
else if(mark>=60 && mark <=79){
    cout<<"B"<<endl;
}
else if(mark >=50 && mark<=59){
    cout<<"C"<<endl;
}
else if(mark>=45 && mark<=49){
    cout<<"D"<<endl;
}
else if(mark>=25 && mark<=44){
    cout<<"E"<<endl;
}else if(mark<=25){
    cout<<"F"<<endl;
}
}
 return 0;
}