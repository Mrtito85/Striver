


#include <iostream>
using namespace std;

int main(){

    while(1){
    int age;
    cin>>age;
    if(age<18){
        cout<<"Not eliagble for the job"<<endl;
    }
    else if(age>=18 && age<=54){
        cout<<"Eligble for job"<<endl;
    }
    else if(age>=55 && age <=60){
        cout<<"Eligable for job, retirement soon"<<endl;
    }
    else {
        cout<<"Retirement time"<<endl;
    }
}
    return 0;
}