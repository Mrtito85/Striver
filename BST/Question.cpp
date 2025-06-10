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

/*
find the Kth-Smallest elment in BST
approach 1
what if a get a inordered because it's sorted and the we traverse the array and find the kth index element 
apporach 2
while travering the inorder maintain a count =0 and increment while increment the root node and when the count==k return root->__inner_data_entrypoint
and when root==NULL then return -1
*/

int kthSmallest(int k,vector<int> &ans){
    //they have given us a index
    if(k>0 && k<ans.size()){
        return ans[k-1];
    }
    return -1;
}

int inorder(node* &root,int &count,int k){
    if(root==NULL){
        return -1;
    }
   int left= inorder(root->left,count,k);
   if(left!=-1)return left;
   count++;
   if(count==k){
    return root->data;
   }
   return inorder(root->right,count,k);


    
    
}

/*
find the Kth Largest Element what if i told you it's similar to to kth smallest let i know the 
largest element for the right is n-i+1  ==>  n-kth+1  ---> this  now i can find kth largest using a kth smallest code

*/
int kthLargest(int k,vector<int> &ans){
    //they have given us a index
    int n=ans.size();
    if(k>0 && k<ans.size()){
        return ans[n-k+1];
    }
    return -1;
}
/*
Find the Predecessor and successor inorder in BST
inorder predecessor -> the element who is come before the target value
inorder successor   -> the element who is come after the target value

Appraoch 1
take  an answer array  and the element [target-1]  && [target+1]


Approach 2

predecessor --> the element the left subtree which has a maximum = findMax
successor   --> the element which is minimum in the right subtree = findMin
*/

node* findMin(node* &root){
    node* temp=root;
    while(temp->left != NULL){
        temp=temp->left;
    }
    return temp;
}  
node* findMax(node* &root){
    node* temp=root;
    while(temp->right !=NULL){
        temp=temp->right;
    }
    return temp;
} 
/*
Input ->key , root 
*/
pair<int,int> predecessorAndSuccessor(node* &root,int key){
    //first we have to find the key
    node* temp=root;
    int predecessor=-1;
    int successor=-1;
    while(temp->data!=key){
        if(temp->data > key){
            //it's mean we have greater root the key is in the left half
            //the root has greater value it is possible it might be our successor
            successor=root->data;
            temp=temp->left;
        }
        else{
            predecessor=root->data;
            temp=temp->right;
        }
    }

    //now find the max element is the left which is our successor
    node* templeft=temp->left;
    while(templeft != NULL){
        predecessor=templeft->data;
        templeft=templeft->right;
    }
    //find minimum at the right which is our successor
    node* tempright=temp->right;
    while(tempright!=NULL){
        successor=tempright->data;
        tempright=tempright->left;
    }
    return {predecessor,successor};


}


/*
Find LCA in BST
Input: root  , int p , int q   or may give p->data or q->data
Appoach 1 
we have 4 conditions 
1: root->data > q->data  && root->data > p->data its mean both p and q lies in left part
2: root->data <q->data && root->data < p->data  it's mean both p and q lies right part because data is greater than the root
3: root->data < q->data  q in the right part and root->data > p->data it's mean it's lies in left part 
4 : vice versa for 4th conditon similar to 3


*/

int LCA_BST(node* &root,int p,int q){
    if(root==NULL)return -1;

    if(root->data>p && root->data > q){
        //go to left half
        return LCA_BST(root->left,p,q);
    }
    else if(root->data<p && root->data <q){
        return LCA_BST(root->right,p,q);
    }
    else{
        return root->data;
    }
}
int LCA_BST_Iterative(node* &root,int p,int q){
    node* temp=root;
    while(temp!=NULL){

    

            if(temp->data>p && temp->data > q){
                //go to left half
                temp=temp->left;
            }
            else if(temp->data<p && temp->data <q){
                temp=temp->right;
            }
            else{
                return temp->data;
            }

}
}

/*
Two Sum in BST
Input: Root,Target  
Approach 1
pick each node and subtract with the target and now traverse in the BST to find the remainingTarget
remaining=target-node->data
search the remaining in the bst for each node
pick 1 node -> n-1 comparsion
pick 2 node -> n-2 comparsion
pick 3 node -> n-3 comparsion
and so on

Approach 2 : BigO(N)
BST property is inorder is sorted
*/
bool search(node* root,int val,int skip){
    if(root==NULL)return false;
    if(root->data != skip && root->data==val){
        return true;
    }
    if(val>root->data){
        return search(root->right,val,skip);
    }else{
        return search (root->left,val,skip);
    }
}
bool solve(node* &root,node* curr,int target){
    if(curr==NULL)return false;
    int remaining=target-curr->data;
    if(search(root,remaining,curr->data)){
        return true;
    }
    return solve(root,curr->left,target) || solve(root,root->right,target);
}
bool twoSum(node* &root,int target){
    return solve(root,root,target);
}
/*
Appraoch 2
*/
bool twoSumOpptimal(vector<int> &ans,int target){
   //find the inorder vector arrays
    int i=0;
    int j=ans.size()-1;
    while(i<j){
        int sum=ans[i]+ans[j];
        if(sum==target)return true;
        if(sum>target){
            j--;
        }else{
            i++;
        }
    }
    return false;
}

/*
Input: Root
make an inorder 
Flatten a BST into linked list where the left pointer is point to NULL 
and right pointer is point toward the null node
and the base case is the last Node left and right is point toward NULL

*/

node* BST_Flatten(node* &root){
    //inorder
    vector<int> ans;
    inordered_BST(root,ans);
    
    //create a node newRoot to return
    node* newRoot=new node(ans[0]);
    node* curr=newRoot;
    for(int i=1;i<ans.size();i++){
        node* temp=new node(ans[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
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
    cout<<endl;
    int count=0;
    cout<<inorder(root,count,2)<<endl;
    cout<<findMax(root)->data<<endl;
    cout<<findMin(root)->data<<endl;
    cout<<"Printing predecessor and Successor "<<endl;
    cout<<predecessorAndSuccessor(root,8).first<<" "<<predecessorAndSuccessor(root,8).second; 
    cout<<endl;
    cout<<LCA_BST(root,8,21);  //answer is 5
    cout<<"linked list from bst "<<endl;
    cout<<BST_Flatten(root)->right->data;

    return 0;
}