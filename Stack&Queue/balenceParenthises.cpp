#include <iostream>
#include <string>
#include <stack>
using namespace std;

void solve(string brackets,int n){
    stack<char> st;

    for(int i=0;i<n;i++){
        if(brackets[i]=='(' || brackets[i]=='[' || brackets[i]=='{'){
            st.push(brackets[i]);
        }else{
            if(st.empty()){
                cout<<"Not Matching"<<endl;
                return;
            }
            int closing=brackets[i];
            int top=st.top();
            if(top=='(' && closing==')' || 
                top=='{' && closing=='}'||
                top=='[' && closing==']'){
                    st.pop();
                }else{
                    cout<<"Not matching"<<endl;
                    return;
                }
        }
    }
    cout<<"matching"<<endl;

}
int main(){

    string brackets;
    cin>>brackets;
    int n=brackets.size();
    solve(brackets,n);
    return 0;
}