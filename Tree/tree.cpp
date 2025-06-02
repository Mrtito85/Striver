//Tree is a non-Linear data structure where each node connect to multiple node

// node, root,parent,child , sbling,incestor,decentent,leaf node
//binary tree has <=2 childs
//Starting point in the tree is called root 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    //if you want to create a tree data structure
    // list<node*> child;
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};

node* buildTree(node* &root){
    cout<<"Enter the Data for Node "<<endl;
    int data;
    cin>>data;

    root=new node(data);
    //if data is -1 i assume that it is null
    if(data==-1){
        return NULL;
    }

    cout<<"Enter data for Inserting in Left "<< data<<endl;
    root->left= buildTree(root->left);
    cout<<"Enter data for Inserting in Right "<<data<<endl;
    root->right = buildTree(root->right);
    return  root;
}
void levelOrder(node* &root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            node* curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            ans.push_back(curr->data);
        }
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
void levelOrderTraversalWithInnerLoop(node* &root){
    queue<node*> q;
    q.push(root);
    //after complete the first horizontal line
    q.push(NULL);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        //Here is the base case when if the q.front() is  null then add a separater
        
        if(curr==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            cout<<curr->data<<"  ";
        }
    }
}

int main(){
    //   1
    // 3    5
    //7    11 17 null
    node* root=NULL;
    root=buildTree(root);
    levelOrderTraversalWithInnerLoop(root);

    return  0;
}