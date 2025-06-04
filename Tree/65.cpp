#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* &root){
    cout<<"Enter data for node "<<endl;
    int data;
    cin>>data;
    node* temp=new node(data);
    if(data==-1)return NULL;
    cout<<"Enter data for for the left Node "<<data<<endl;
    temp->left=buildTree(temp->left);
    cout<<"Enter data for the root->right "<<data<<endl;
    temp->right=buildTree(temp->right);

    return temp;
}
void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            cout<<temp->data<<" ";
        }
    }
}
void solve(node* &root,int sum,int &maxSum,int len,int &maxLength){
    if(root==NULL){
        //check for length
        if(len>maxLength){
            maxSum=sum;
            maxLength=len;
        }
        else if(len==maxLength){
            maxSum=max(sum,maxSum);
        }

        return;
    }

        sum+=root->data;
        solve(root->left,sum,maxSum,len+1,maxLength);
        solve(root->right,sum,maxSum,len,maxLength);
}
void findLargestPathSum(node* &root){
    int sum=0;
    int maxSum=0;
    int len=0;
    int maxLength=0;
    solve(root,sum,maxSum,len,maxLength);
    cout<<"Largest path sum is "<<maxSum<<endl;
}
int main(){
    node* root=NULL;
    root=buildTree(root);
    levelOrder(root);
    findLargestPathSum(root);
    return 0;
}