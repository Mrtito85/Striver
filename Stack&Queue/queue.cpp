#include<iostream>
using namespace std;

/*
capacity
int *arr
start=-1
end=-1

queue fifo  use two pointer start ,end
push element at end
pop element at start
size = end - start+1 not work .. while push sizecout++ AND POP sizecount--
top =  is present at start

*/

class queue{
    public:
    int totalSize;
    int curSize;
    int *q;
    int start;
    int end;
    queue(int size){
        this->totalSize=size;
        q=new int[size];
        start=-1;
        end=-1;
        curSize=0;
    }

    void push(int element){
        if(curSize==totalSize){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(curSize==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%totalSize;
        }
        q[end]=element;
        curSize++;
    }

    int pop(){
        int ele=-1;
        if(curSize==0){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }else if(curSize==1){
             ele=q[start];
            start=-1;
            end=-1;
           
        }else{
            ele=q[start];
            start=(start+1)%totalSize;
            
        }
        return ele;
    }
    int top(){
        if(curSize==0){
            cout<<"empty"<<endl;
        }else{
            return q[start];
        }
    }
    int size(){
        return curSize;
    }
};


int main(){
    queue q(2);
    q.push(3);
    q.push(3);
    cout<<q.top();
    cout<<q.size();
    //q.push(33);
    return 0;
}