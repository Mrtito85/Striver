#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


/*
Assing Cookies 
m=6--->cookies
n=5 --->childrens
Every children has a greedy factor

parents =[4,2,1,2,1,3] cookies
children =[1,5,3,3,4] greedy factor of childs
               ^
you can satisfied the children by given cookies more than there greedy factor
let take child 3
3-> this child can only take cookies 4  and 3  mean greedy <= cookies

Your Task:
    You Can  pick one cookie to qive it to only one children --> condition
    Once the cookie is given to child it's never given to other child
    your task is tu assign maximum cookies to children
    so that's that maximum children satisfied

*/
int solve1(vector<int> &cookiesSize, vector<int> &greedy, int n, int m) {
    sort(greedy.begin(), greedy.end());       // Sort children's greed
    sort(cookiesSize.begin(), cookiesSize.end()); // Sort cookie sizes

    int child = 0; // pointer for greedy
    int cookie = 0; // pointer for cookies

    while (child < n && cookie < m) {
        if (greedy[child] <= cookiesSize[cookie]) {
            // Satisfied this child
            child++;
        }
        // Move to the next cookie regardless of whether it was used or not
        cookie++;
    }
    return child; // Number of satisfied children
}

int solve(vector<int> &cookiesSize,vector<int> &greedy,int n,int m){

    //sort the both are so that i can use two pointer left and right
    //left pointer point to greedy array and if the greedy <=cookies size then we can 
    //satisfied that child and then traverse the at next child
    int child=0;
    int cookie=0;
    sort(greedy.begin(),greedy.end());
    sort(cookiesSize.begin(),cookiesSize.end());

    //l point to greed
    //r poiint to cookiesSize
    while(child<n && cookie<m){
        //here we check if the greed of the child is less than cookie size than 
        //this child is satisfied check for the other childs
        if(greedy[child]<=cookiesSize[cookie]){
            cookie++;
        }
        child++;
    }
    //here i'm return the satisfied child counts
    return cookie;
}
int main(){

    int n,m;
    cin>>n>>m;
    //Here take the wrong input that's why finding issue
    vector<int> greedy(n);
    for(int i=0;i<n;i++){
        cin>>greedy[i];
    }
    vector<int> cookies(m);
    for(int i=0;i<m;i++){
        cin>>cookies[i];
    }

    cout<<"Maximum child that Satisifed "<<solve1(cookies,greedy,n,m);

    return 0;
}