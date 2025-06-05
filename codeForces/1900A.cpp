#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool isThreeCellSame=false;
        int count=0;
        for(int i=0;i<n;i++){
            
            if(s[i]=='.'){
                count++;
                if(count==3){
                    isThreeCellSame=true;
                    break;
                }
              
            }
            else if(s[i]=='#'){
                    count=0;
                }
        }
        if(isThreeCellSame){
            cout<<2<<endl;
        }else{
            count=0;
            for(int i=0;i<n;i++){
                if(s[i]=='.'){
                    count++;
                }
            }
            cout<<count<<endl;
        }
    }

    return 0;
}