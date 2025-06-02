#include <iostream>
#include <climits>
using namespace std;
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
int maxi=INT_MIN;
int heightOfTree(node* root){
    if(root==NULL)return 0;

    int l= heightOfTree(root->left);
    int r= heightOfTree(root->right);
    return 1 + max(l,r);
}

void diameterOfTree(node* root){
    if(root==NULL)return ;
    int l=heightOfTree(root->left);
    int r=heightOfTree(root->right);

    maxi=max(maxi,l+r);
    cout<<maxi<<endl;
    diameterOfTree(root->left);
    diameterOfTree(root->right);
}
int maximum=INT_MIN;
int maxPathSum(node* root){
    if(root==NULL)return 0;

    int leftSum=maxPathSum(root->left);
    int rightSum=maxPathSum(root->right);

    maximum=max(maximum,root->data + leftSum+rightSum);
    return root->data + max(leftSum,rightSum);
}
int main(){
    node* root=new node(-10);
    root->left=new node(9);
    root->right=new node(20);
    root->right->left= new node(15);

    root->right->right=new node(7);
    maxPathSum(root);
    cout<<maximum<<endl;


    return 0;
}