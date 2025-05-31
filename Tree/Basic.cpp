#include <iostream>
using namespace std;
//-->Full Binary tree --->> 0 and 2 children
//-->Complete Binary tree---> all level are completed except the last level
//the last level are completed form left to right
//-->Perfect binary tree: all leave node at the same level
//-->Balence Bianry Tree: the high is not more than (log base 2 N )
//Degenerate Tree: just like a linklist has single line

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
int main(){
    node* root= new node(10);
    cout<<root->data<<endl;
    root->left = new node(11);
    root->right=new node(12);
    root->left->right=new node(14);
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->left->right->data<<endl;

    return 0;
}