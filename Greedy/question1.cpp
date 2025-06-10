#include <iostream>
#include <vector>
using namespace std;

/*
            Problem "Lemonade Change"


bills =[5,5,5,10,20]
Custmers=N  --> this Number varies

Problem : You have a Lemonade Stall and Every Lemon is cost you a $5 dollar 
If The custmer have 20 Dollar the Lemon Cost is 5 dollar and you have to return 15 dollar 
to the custmer

Basically you have a Dollar / currency  of 
5--> 
10-->
20--> 

You always have to keep change in your pocket
 so that when some custmer come you can sell to them

 at the end you have check you can sell the lemonade to all the custmers and no-one 
 can return form your stall due to you don't have change in your pocket


*/

bool solve(vector<int> &Dollar,int n){
    int fiveDollar=0;
    int tenDollar=0;
    int twentyDollar=0;

    for(int i=0;i<n;i++){
        if(Dollar[i]==5){
            fiveDollar++;
        }
        else if(Dollar[i]==10){   // here is a logical mistake compare with the 10
            if(fiveDollar){
                fiveDollar--;
                tenDollar++;
            }
            else {
                return false;
            }
        }
        else{
            if(fiveDollar && tenDollar){
                fiveDollar--;
                tenDollar--;
                
            }else if(fiveDollar>=3) {
                
                    fiveDollar=fiveDollar-3;
                
            }else{
                return false;
            }
        }
    }
    return true;

}

int main(){

    int n;
    cin>>n;// n is assume as a custmer
    vector<int> LemonadeSell(n);
    for(int i=0;i<n;i++){
        cin>>LemonadeSell[i];
    }

    cout<<"Answer "<<solve(LemonadeSell,n);
    return 0;
}