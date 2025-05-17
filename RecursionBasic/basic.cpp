#include <iostream>
using namespace std;

void func(int i){
    if(i==10){
        return ;
    }
      i++;   
    cout<<"Hi "<<i<<endl;
  

    func(i);
    cout<<i<<endl;
}

int main(){
    //Here we would know first what is function
    //Recurion when a funciton call it's it is called recursion
    func(1);
    return 0;
}