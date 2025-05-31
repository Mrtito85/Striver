#include <iostream>
#include <queue>
#include <stack>
using namespace std;
//Inorder-->Left/Root/Right
//preorder-->Root/Left/Right
//postOrder-->Left/Right/Root

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};
void inorder(node* root){
    if(root==NULL){
        return;
    }
    //Left
    inorder(root->left);
    //Root
    cout<<root->data<<" ";
    //right
    inorder(root->right);
}

void preOrder(node* root){
    if(root==NULL){
        return;
    }
    //Root
    cout<<root->data<<" ";
    //Left
    preOrder(root->left);
    //right
    preOrder(root->right);
}

void postOrder(node* root){
    if(root==NULL){
        return;
    }
    //left
    postOrder(root->left);
    //right
    postOrder(root->right);
    //root
    cout<<root->data<<" ";
}
void bfs(node* root){
    if(root==NULL)return;

    //make queue for bfs
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* cur=q.front();
        q.pop();
        cout<<cur->data<<" ";

        if(cur->left){
            q.push(cur->left);
        }
        if(cur->right){
            q.push(cur->right);
        }

    }
}
//dfs (preorder traversal)
void dfs(node* root){
    if(root==NULL){
        return;
    }

    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node* curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        //Here pushing the right node in the stack first becasuse it's has a
        //LIFO property 
        if(curr->right){
            s.push(curr->right);
        }if(curr->left){
            s.push(curr->left);
        }
    }
    
}

void levelOrder(node* root){
    if(root==NULL)return;
    vector<vector<int>> ans;
    //making queue to fifo
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            node* curr=q.front();
            q.pop();
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
            level.push_back(curr->data);
        }
        ans.push_back(level);
    }

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void inOrderTraversalIterative(node* root){
    if(root==NULL)return;
    stack<node*> s;
    node* curr=root;
    while(true){
        if(curr){
            s.push(curr);
            curr=curr->left;
        }else{
            if(s.empty())break;
            curr=s.top();
            cout<<curr->data<<" ";
            s.pop();
            curr=curr->right;
        }
    }
}

int maxDepthOfBinaryTree(node* root){
    if(root==NULL)return 0;

    int leftHeight=maxDepthOfBinaryTree(root->left);
    int rightHeight= maxDepthOfBinaryTree(root->right);

    return 1+ max(leftHeight,rightHeight);
}

bool balenceBinaryTree(node* root){
    if(root==NULL)return true;
    int leftHeight= maxDepthOfBinaryTree(root->left);
    int rightHeight=maxDepthOfBinaryTree(root->right);
    if(abs(rightHeight-leftHeight)>1){
        return false;
    }
    bool lf=balenceBinaryTree(root->left);
    bool r=balenceBinaryTree(root->right);
    if(!lf || !r)return false;
    return true;
}
int main(){
// Creating the tree:
    //        10
    //       /  \
    //      5   15
    //     / \
    //    2   7
    node* root=new node(10);
    root->left=new node(5);
    root->left->left=new node(2);
    root->left->right=new node(7);
    root->right=new node(15);
    //inorder(root);
    //preOrder(root);
    //postOrder(root);
    //bfs(root);
    //dfs(root);
    //levelOrder(root);
    //inOrderTraversalIterative(root);
    //cout<<maxDepthOfBinaryTree(root);//3
    //cout<<balenceBinaryTree(root);//1



    return 0;
}