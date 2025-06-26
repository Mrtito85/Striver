#include<iostream>
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

class queue{

    public:
    node* head;
    int curSize=0;

    void push(int element){
        node* temp=new node(element);
        temp->next=head;
        head=temp;
        curSize++;
    }
    int pop(){
        node* temp=head;
        head=head->next;
        delete temp;
        curSize--;


        
    }
    int top(){
        if(head!=NULL){
            return head->data;
        }
    }
    int size(){
        return curSize;
    }
    
};

int main(){
    queue q;
    q.push(10);
    q.push(11);
    cout<<q.top()<<endl;
    cout<<q.top()<<endl;
    cout<<q.top()<<endl;
    cout<<q.size();
    return 0;
}