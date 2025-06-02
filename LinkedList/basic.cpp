#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
 
void insertAtTail(node* &head,node* &tail,int data){
    if(tail==NULL){
        node* node1=new node(data);
        tail=node1;
        head=node1;
    }else{
        node* temp=new node(data);
        tail->next=temp;
        tail=temp;
    }
}
void printLinkedList(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void reverseLinkedList(node* &head){
    //if the head is null or head has a single node then return
    if(head==NULL || head->next==NULL){
        return;
    }
    //creating a pointer for reverse the linkedlist
    node* prev=NULL;
    node* curr=head;
    node* forward=NULL;
    while(curr!=NULL){
        //keeping track of linkedlist using forward pointer 
        forward=curr->next;
        //here node point the curr pointer to prev
        curr->next=prev;
        //now moving pointers
        prev=curr;
        curr=forward;
    }
    //Now previous is pointing to the last node 
    //mark the head to previous node
    if(curr==NULL){
        head=prev;
    }
}
void reverseLinkedListUsingRecursion(node* &head,node* &tail,node* prev,node* curr){
    if(curr==NULL){
        head=prev;
        return;
    }
    node* forward= curr->next;
    reverseLinkedListUsingRecursion(head,tail,curr,forward);
    curr->next=prev;
    tail=curr;
    
}

int getLengthLinkedList(node* &head){
    int count=0;
    node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void middleOfLinkedList(node* &head){
    int length= getLengthLinkedList(head);
    int middle=(length/2)+1;
    int cnt=1;
    node* temp=head;
    while(cnt<middle){
        cnt++;
        temp=temp->next;
    }
    cout<<"Middle Node "<<temp->data<<endl;
}
node* middleofLinkedListPointerFastSlow(node* &head){
    //if we have 1 node and 0 node
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* slow=head;
    node* fast= head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        //cout<<slow->data<<" ";
        slow=slow->next;
        
    }
    return slow;

}

// Function to reverse k nodes
node* reverseLinkedListKGroup(node* head, int k) {
    if (head == NULL) return NULL;

    // Check if there are at least k nodes
    node* temp = head;
    int count = 0;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k) return head; // Less than k nodes, do not reverse

    // Reverse k nodes
    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;
    count = 0;

    while (curr != NULL && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Recursively reverse the rest and connect
    if (forward != NULL) {
        head->next = reverseLinkedListKGroup(forward, k);
    }

    return prev; // New head after reversing
}
int main(){
    node* head=NULL;
    node* tail=NULL;
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,12);
    insertAtTail(head,tail,14);
    insertAtTail(head,tail,16);
    insertAtTail(head,tail,18);
    //Reverse the linkedlist
   // node* curr=head;
  //  node* prev=NULL;
  //  reverseLinkedListUsingRecursion(head,tail,prev,curr);
    //printing the linkedlist
    printLinkedList(head);
    //Middle of linkedlist
   // middleOfLinkedList(head);
  //  cout<<"Middle using pointer "<<middleofLinkedListPointerFastSlow(head)->data<<endl;
    head=reverseLinkedListKGroup(head,2);
    printLinkedList(head);
    //Here tracking head and tail 
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    return 0;
}