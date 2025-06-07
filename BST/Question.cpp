#include <iostream>
#include<queue>
#include <climits>
using namespace std;

//it's almost similar to binary search where i can find my element in big o(log (N)) Time complexity
//in Binary search where we first find the middle element in the array and compare with our target if it's
//less than our target then we have to search the element in the right half of the array and else in the left and and if found then return index
/*
In binary Search tree we have a root and conidtion
in the left side of binary tree all the element are less than root node
in the right side of binary tree all the element are greater than root node
and this condition is apply to every node of the BST

Here is a example build Binary Search Tree using this Example
10 8 21 7 27 5 4 3
So we have 10 our first node so make root node to 10
then we have 8 the is less than root node so that we can append at to the left of  root node
then we got 21 which is greater than the root node so it's append to the right side of root node
then we have 7 which is less than root node and also less than root->left node so that i append to the left of root->left->__cpp_lib_exchange_function
and same goes for all the node of binary tree

Time Complextiy 
In binary Search Tree insertion time complexity has Log(N)
*/

/*
Find ELement in binary Search Tree 
input given 
element , binarySearchTree Root

*/



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
bool SearchInBST(node* &root,int element){
    if(root==NULL)return false;
    if(element==root->data)return true;
    if(root->data>element){
        //search in left half
        bool ans=SearchInBST(root->left,element);
        return  ans;
    }
    else{
        return SearchInBST(root->right,element);
    }
}
void insertIntoBST(node* &root,int data){
    
    if(root==NULL){
        root=new node(data);
        
        return;
    }

    if(data<root->data){
        insertIntoBST(root->left,data);
    }
    else{
        insertIntoBST(root->right,data);
    }
}
node* buildBST(node* &root){
    cout<<"Enter data for node"<<endl;
    int data;
    cin>>data;
    while(data!=-1){
        
        insertIntoBST(root,data);
        cin>>data;
    }
    return root;
}
void levelOrder(node* &root){
    //using queue to traverse all the node
    //NULL pointer to go to the next line
    //bfs
    queue<node*> q;
    q.push(root);
    //first level complete
    q.push(NULL);
    while(!q.empty()){
        node* frontNode=q.front();
        q.pop();
        if(frontNode==NULL){
            cout<<endl;
            //if the queue has more element than push NULL
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(frontNode->left !=NULL){
                q.push(frontNode->left);
            }
            if(frontNode->right!=NULL){
                q.push(frontNode->right);
            }
            cout<<frontNode->data<<" ";
        }
    }
}

/*
validate BST
as we know the Inoder of BST is Sorted, so if we want to  check if the BST is valid then we have to travser the inorder
and check
*/

void inordered_BST(node* &root,vector<int> &ans){
    if(root==NULL){
        return ;
    }
    inordered_BST(root->left,ans);
    ans.push_back(root->data);
    inordered_BST(root->right,ans);
}
bool isValid(node* &root,int min,int max){
    if(root==NULL)return true;
    if(root->data >=min && root->data <=max){
        bool left=isValid(root->left,min,root->data);
        bool right=isValid(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}
int main(){
    node* root=NULL;
    root=buildBST(root);
    levelOrder(root);
    cout<<"Element " <<SearchInBST(root,3);
    vector<int> ans;
   // root->data=1;
    inordered_BST(root,ans);
    cout<<"INORDER \n";
    for(auto i:ans){
        cout<<i<<" ";
    }

    cout<<endl;
    bool check=true;
    for(int i=1;i<ans.size();i++){
        if(ans[i]>ans[i-1]){
            continue;
        }else{
            check=false;
        }
    }
    
    if(check){
        cout<<"The Tree is valid\n";
    }else{
        cout<<"Not valid"<<endl;
    }
    cout<<"Isvalid Function using Min max "<<isValid(root,INT_MIN,INT_MAX);

    return 0;
}