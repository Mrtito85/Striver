#include <iostream>
#include <vector>
using namespace std;

/*
we have a lemonade stall
currencey is 5 ,10 , 20

INPUT 5 5 5 10 20

you have to sell lemon juice to every possible custmer  if it's not possible return false

5-> if the custmer has 5 dollar you can take money and sell because lemonade price is 5 dollar
10->if the custmer has 10 dollar than take 10 and return 5 dollar if you don't have change return false
20 -> if the custmer has 20 dollar than take it'  and you can return 3 notes of 5 dollar oor   one 10 dollar and 5 dollar
if not possible because you don't have change return false;

*/

bool solve(vector<int> lemonadePrice,int n){
    int five=0;
    int ten=0;
    int twenty=0;
    for(int i=0;i<n;i++){
        if(lemonadePrice[i]==5){
            five++;
        }
        if(lemonadePrice[i]==10){
            if(five){
                five--;
                ten++;
            }
            else{
                return false;
            }
        }
        if(lemonadePrice[i]==20){
            if(five>=3){
                five =five-3;
                twenty++;
            }
            else if(five && ten){
                five--;
                ten--;
                twenty++;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){

    int n;
    cin>>n;
    vector<int> lemonadePrice(n);
    for(int i=0;i<n;i++){
        cin>>lemonadePrice[i];
    }

    cout<<solve(lemonadePrice,n);

    return 0;
}