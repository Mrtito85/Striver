#include <iostream>
using namespace std;

/*
we have to implement queue using linkedlist data structure
pointer use head and tail
the head represent that start of queue , tail repesent end 
we perform the following operations

push
pop
top
size

*/
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
        

    }
};

class Queue{
    public:
    int curSize=0;
    node* head, *tail;
    Queue(){
        head=NULL;
        tail=NULL;
    }
    void push(int element){
        node* temp=new node(element);
        if(head==NULL){
            head=tail=temp;
            //cout<<head->data<<endl;
            curSize++;
        }else{
            tail->next=temp;
            tail=temp;
            curSize++;
        }
    }
    void pop(){
        if(head!=NULL){
            node* ele=head;
            node* temp=head;
            head=head->next;
            delete temp;
            curSize--;
           
        }
        else{
            cout<<"Queue is Empty ";
            
        }
    }
    int top(){
        
        if(head!=NULL){
            return head->data;
        }
        return -1;
    }
    int size(){
        return curSize;
    }
};


int main(){
    Queue q;
    q.push(1);
    cout<<q.top();


    return 0;
}