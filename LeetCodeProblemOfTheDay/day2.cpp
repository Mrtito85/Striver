
#include <iostream>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        int remainCharacter=word.size() - (numFriends-1);
        int n=word.size();
        if(numFriends==1)return word;
        string result="";
        for(int i=0;i<n;i++){
            int canTakeLength=min(remainCharacter,n-i);
            result=max(result,word.substr(i,canTakeLength));
        }
        return result;
        
    }
};

int main(){
    string word;
    cin>>word;
    int numFriends;
    cin>>numFriends;
    Solution sol;
    cout<<sol.answerString(word,numFriends);
    return 0;
}