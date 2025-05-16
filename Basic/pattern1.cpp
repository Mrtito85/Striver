#include<iostream>
#include<math.h>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;

void rectangle(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
void paramid(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void paramid1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
void paramid2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}
void paramid4(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
void paramid5(int n){
    for(int i=0;i<n;i++){
        //Star begining
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        //Here print star
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        //Start end
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void paramid6(int n){
    for(int i=0;i<n;i++){
        //Star begining
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        //Here print star
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        for(int j=0;j<n-i-1;j++){
            cout<<"*";
        }
        //Start end
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void paramid7(int n){
    int start=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            start=0;
        }else {
            start=1;
        }
        for(int j=0;j<=i;j++){
            cout<<start<<" ";
            start= 1-start;
        }
        cout<<endl;

    }
}

void paramid8(int n){
    int spaces=2*(n-1);
    for(int i=0;i<n;i++){
        //print Number
        for(int j=0;j<i+1;j++){
            cout<<j+1;
        }
        //print spaces
        for(int j=0;j<spaces;j++){
            cout<<" ";
        }
        //print number
        for(int j=i;j>=0;j--){
            cout<<j+1;
        }
        spaces = spaces-2;
        cout<<endl;
    }
}
void paramid9(int n){
    int number=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<number<<" ";
            number++;
        }
        cout<<endl;
    }
}
void paramid10(int n){
   
    for(int i=0;i<n;i++){
        char ch='A';
        for(int j=0;j<i+1;j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}
int sum(int a,int b){
    int sum=a+b;
    return sum;
}

void explainPair(){
    pair<int,int> p1={1,4};
    cout<<p1.first<<" "<<p1.second<<endl;
    pair<int,pair<int,int>> p2={1,{9,3}};
    cout<<"P2 "<<p2.first<<endl;
    cout<<"P2 second "<<p2.second.first<<endl;

    pair<int,int> arr[]={{1,2},{2,4},{2,4}};
    cout<<arr[1].first;

}

void explainVector(){
    vector<int> v;
    v.push_back(2);
    v.emplace_back(3);
    for(auto i:v){
        cout<<i<<endl;
    }
    vector<pair<int,int>> v1;
    v1.push_back({2,4});
    v1.push_back({2,2,});
    for(int i=0;i<v1.size();i++){
        cout<<v1[i].first<<" "<<v1[i].second<<" ";
        cout<<endl;
    }
    vector<int> v11(10,100);
    for(auto i:v11){
        cout<<i<<" ";
    }
    vector<int> ::iterator it=v.begin();
    it++;
    cout<<*(it)<<endl;
}

void explainList(){
    list<int> l;
    l.push_back(22);
    l.push_back(21);
    l.push_front(1);
    l.push_back(20);

    for(auto i:l){
        cout<<i<<" ";
    }
}

void explainDeque(){
    deque<int> dq;
    dq.push_back(22);
    dq.push_back(21);
    dq.push_front(1);
    for(auto i:dq){
        cout<<i<<" ";
    }
}

void explainStack(){
    stack<int> st;
    st.push(1);
    st.push(2);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void explainQueue(){
    queue<int> q;
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

void explainSet(){
    //In set everything will happened in logermetric time complexity
    set<int> st;
    st.insert(2);
    st.insert(2);
    st.insert(22);
    auto find =st.find(21);
    cout<<*find<<" ";
    for(auto i:st){
        cout<<i<<" ";
    }
    cout<<endl;

    for (auto it = st.rbegin(); it != st.rend(); ++it) {
        cout << *it << " ";
    }

}

void explainPriorityQueue(){
    priority_queue<int> q;
    q.push(12);
    q.push(22);
    q.push(10);
    cout<<q.top()<<" ";

    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(22);
    pq.push(1);
    pq.push(222);
    cout<<pq.top();
}

void explainUnordered_set(){
//big O(1) unique : but not sorted
    unordered_set<int> st;
    st.insert(1);
    st.insert(20);
    st.insert(20);
    st.insert(-1);

    auto it=st.find(20);
    if(it != st.end()){
        cout<<*it<<endl;
    }
    for(auto i:st){
        cout<<i<<" ";
    }
}

void explainmap(){
    map<int,int> mpp;
   // map<int,pair<int,int>> mpp;
   // map<pair<int,int>,int> mpp;
    mpp[1]=2;
        mpp[3]=4;
    mpp.insert({2,4});
    cout<<mpp[3]<<endl;

    for(auto i:mpp){
        cout<<i.first<<" "<<i.second<<endl;
    }
}

void explainSort(){
    int arr[]={2,4,24,1};
    sort(arr,arr+4,greater<int>());
    vector<int> v={2,4,1,3};
    sort(v.begin(),v.end(),greater<int>());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    string name="zahid";
    sort(name.begin(),name.end());
    cout<<name<<endl;

    string s ="123";
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));

    int maxi=*max_element(v.begin(),v.end());
    cout<<maxi;
}
int main(){
    explainSort();
    //explainUnordered_set();
   // explainQueue();   
    //explainStack();
    //xplainDeque();
    //explainList();
   // explainVector();
    return 0;
}