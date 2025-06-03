//Tree Data Structure 
//Tree is a non-linear data structure where each node connect to multiple node
//We have mulitple term in tree data structure
//root,parent,child ,ancestor,decendor,leaf,sblings
//Binary tree has <=2 childs
//       1
//     3     7
//  9   11 7   null

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//build a binary tree
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
    cout<<"Enter Data for Node "<<endl;
    int data;
    cin>>data;
    node* temp=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for the root->left "<<data<<endl;
    temp->left=buildTree(temp->left);
    cout<<"Enter data for the root right "<<data<<endl;
    temp->right=buildTree(temp->right);
}

void inorder(node* &root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void levelOrder(node* &root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
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
            cout<<curr->data<<" ";
        }

    }
}

void levelOrderReverse(node* &root){
    queue<node*> q;
    stack<int> s;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
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
            s.push(curr->data);
            //cout<<curr->data<<" ";
        }

    }
    cout<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
void Preorder(node* &root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
node* buildTreeFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter Data for Root "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"Enter data for the root left "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter data for the root right "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right= new node(rightData);
            q.push(temp->right);
        }


    }
    return root;
}
void countLeafNodes(node* &root,int &count){
    //Here we are using inorder traversal 
    if(root==NULL)return;

    countLeafNodes(root->left,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    countLeafNodes(root->right,count);
}

int maxHeightOfBinaryTree(node* &root){
    if(root==NULL){
        return 0;
    }
    int left=maxHeightOfBinaryTree(root->left);
    int right=maxHeightOfBinaryTree(root->right);
    return 1 + max(left,right);
}

int diameterOfTree(node* &root){
    //longet path between any two nodes
    
}
int main(){
    node* root=NULL;
    root= buildTreeFromLevelOrder(root);
    levelOrderReverse(root);
    int count=0;
    countLeafNodes(root,count);
    cout<<"Total Number of Leaf Nodes is "<<count<<endl;
    cout<<"Maximum height is "<<maxHeightOfBinaryTree(root);
    return 0;
}