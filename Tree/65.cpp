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
        solve(root->right,sum,maxSum,len+1,maxLength);
}
void findLargestPathSum(node* &root){
    int sum=0;
    int maxSum=0;
    int len=0;
    int maxLength=0;
    solve(root,sum,maxSum,len,maxLength);
    cout<<"Largest path sum is "<<maxSum<<endl;
}

node* lowestCommonInsister(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return  root;
    }
    node* left=lowestCommonInsister(root->left,n1,n2);
    node* right=lowestCommonInsister(root->right,n1,n2);

    if(left!=NULL && right!=NULL){
        return root;
    }
    else if(left!=NULL && right==NULL){
        return left;
    }else if(left==NULL && right!=NULL){
        return right;
    }
    else{
        return NULL;
    }
}
void solve1(node* &root,int k,int &count,vector<int> path){
    if(root==NULL)return;
    path.push_back(root->data);
    solve1(root->left,k,count,path);
    solve1(root->right,k,count,path);
    int sum=0;
    int n=path.size();
    //here we traverse from leaf
    for(int i=n-1;i>=0;i--){
        sum+=path[i];
        if(sum==k)count++;
    }
    path.pop_back();
}
int kSumPath(node* &root,int k){
    int count=0;
    vector<int> path;
    solve1(root,k,count,path);
    return count;
}
int main(){
    node* root=NULL;
    root=buildTree(root);
    levelOrder(root);
    findLargestPathSum(root);
    cout<<"lowest common insister "<<lowestCommonInsister(root,50,60)->data;// 40
    return 0;
}