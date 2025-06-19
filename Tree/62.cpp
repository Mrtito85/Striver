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
#include <vector>
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
    if(root==NULL)return 0;
    int operation1=diameterOfTree(root->left);
    int operation2=diameterOfTree(root->right);
    int operation3=(maxHeightOfBinaryTree(root->left)+ 
    maxHeightOfBinaryTree(root->right))+1;
    return max(operation1,max(operation2,operation3));
}

//DiameterFast
//return pair first node point at the diameter and second point toward the height
pair<int,int> diameterFast(node* &root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    //here calculate the diameter
    pair<int,int> left=diameterFast(root->left);
    pair<int,int> right=diameterFast(root->right);

    int diameterleft=left.first;
    int diameterRight=right.first;

    int heightleft =left.second;
    int heightRight=right.second;
    int op1=diameterleft;
    int op2=diameterRight;
    int op3=heightleft+heightRight+1;
    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=1+max(heightleft,heightRight);
    return ans; 
}

bool isBalence(node* &root){
    if(root==NULL)return true;

    //checking for balence of left
    bool left= isBalence(root->left);
    bool right= isBalence(root->right);
    bool diff= abs(maxHeightOfBinaryTree(root->left) - maxHeightOfBinaryTree(root->right))<=1;
    if(left && right && diff ){
        return true;
    }else{
        return false;
    }
}

//is balence fast here we return pair<balence , height> 
pair<bool,int> isBalenceFast(node* &root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    //left call
    pair<bool,int> left=isBalenceFast(root->left);
    pair<bool,int> right=isBalenceFast(root->right);
    
    //left check
    bool isLeft=left.first;
    bool isRight=right.first;

    //checking for diff
    //height
    int heightLeft=left.second;
    int heightRight=right.second;

    pair<bool,int> ans;
    bool diff=abs(heightLeft - heightRight )<=1;
    ans.first=(isLeft && isRight && diff );
    ans.second=1+max(heightLeft,heightRight);
    return ans;
}
 
//here first pair point the issum is equal and second point sum
pair<bool,int> treeSum(node* &root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    //if the leave node
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }

    //Here call for left
    pair<bool,int> leftAns=treeSum(root->left);
    pair<bool,int> rightAns=treeSum(root->right);

    //check left and right condition for sumtree
    bool left= leftAns.first;
    bool right=rightAns.first;

    bool condition= root->data== leftAns.second + rightAns.second;
    pair<bool,int> ans;
    if(left && right && condition){
        ans.first= true;
        ans.second=2* root->data;
    }
    else{
        ans.first=false;
        ans.second=root->data + leftAns.second + rightAns.second;
    }
    return ans;
}

void zigzagTraversal1(node* &root){
        vector<int> result;
    queue<node*> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int n=q.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
        

            node* curr=q.front();
            q.pop();

            //push element left to right base on boolean

            int index=leftToRight?i:n-i-1;
            ans[index]=curr->data;
            cout<<curr->data<<endl;
            
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        leftToRight = !leftToRight;
        for(auto i:ans){
            result.push_back(i);
        }
    }
    for(auto i:result){
        cout<<i<<" ";
    }
    cout<<endl;
}

void leftTraverse(node* &root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    //check if leaf node then skip it for leaf traversal
    if(root->left==NULL && root->right==NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        leftTraverse(root->left,ans);
    }
    else{
        leftTraverse(root->right,ans);
    }
}
void rightTraverse(node* &root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    //check if leaf node then skip it for leaf traversal
    if(root->left==NULL && root->right==NULL){
        return;
    }
    
    if(root->right){
        rightTraverse(root->right,ans);
    }
    else{
        rightTraverse(root->left,ans);
    }
    //we are writig tail case becasue we want get them reverse
    ans.push_back(root->data);
}
void leafNode(node* &root,vector<int> &ans){
    if(root==NULL)return;
    //preorder
   if(root->left==NULL && root->right ==NULL){
    ans.push_back(root->data);
    return;
   }
    leafNode(root->left,ans);
    leafNode(root->right,ans);
}
void boundryTraversal(node* &root){
    if(root==NULL){
        return;
    }
    vector<int> ans;
    ans.push_back(root->data);
    //traverse left 
    leftTraverse(root->left,ans);
    //traverse leaf Node
    leafNode(root->left,ans);
    leafNode(root->right,ans);
    //traverse Right
    rightTraverse(root->right,ans);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

}

int main(){
    node* root=NULL;
    root= buildTreeFromLevelOrder(root);
    levelOrder(root);
    //zigzagTraversal1(root);
    boundryTraversal(root);
  //  int count=0;
   // countLeafNodes(root,count);
   // cout<<"Total Number of Leaf Nodes is "<<count<<endl;
   // cout<<"Maximum height is "<<maxHeightOfBinaryTree(root);
   // cout<<"Maximum diameter is "<<diameterOfTree(root)<<endl;
   // cout<<"Diameter Fast "<<diameterFast(root).first<<endl;
    //cout<<"IS balence tree "<<isBalence (root)<<endl;
    //cout<<"Is balence fast "<<isBalenceFast(root).first<<endl;
   // cout<<"is Sum tree  "<<treeSum(root).first<<endl;
    //cout<<"zig zag Tree "<<endl;
    
    return 0;
}