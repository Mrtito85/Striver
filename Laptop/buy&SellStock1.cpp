#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &stockPrice,int n){
    int miniPriceDay=stockPrice[0];
    int profit=0;//mark it 0 because i'm not interested in negative profit
    for(int i=1;i<n;i++){
        int todayProfit=stockPrice[i]-miniPriceDay;
        miniPriceDay=min(stockPrice[i],miniPriceDay);
        profit=max(profit,todayProfit);
    }
    return profit;
}


int main(){
    int n;
    cin>>n;
    vector<int> stockPrice(n);
    for(int i=0;i<n;i++){
        cin>>stockPrice[i];
    }

    cout<<maxProfit(stockPrice,n);
    return 0;
}