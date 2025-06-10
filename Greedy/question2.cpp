#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Problem : Minimum Time to schdule all the job

Task:
calcuate the waiting time of all job and return their average

Input: N,JobArray
N=5
jobArray =[4,3,7,1,2]

Approach:

first take the minimum time taking job and process it
then take the second minimum time taking job and process it 
and soon on

while doing that create a variable and maintain the WaitngTime and SumOfAllTheJob
and at the end return the average of the Sum of WaitingTime


*/

int solve(vector<int> &jobArray,int n){
    //here sort the array so that we can't iterate for every element again and again
    sort(jobArray.begin(),jobArray.end());
    int miniTime=0;
    int sum=0;
    
    for(int i=0;i<n;i++){
        
        miniTime +=sum;
        sum+=jobArray[i];
    }

    //return the average of minimum time
    return (miniTime/n);
}

int main(){
    int n;
    cin>>n;
    vector<int> jobArray(n);
    for(int i=0;i<n;i++){
        cin>>jobArray[i];
    }
    cout<<"Minimum time to process all the  job "<<solve(jobArray,n);
    return 0;
}