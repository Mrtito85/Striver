#include <iostream>
using namespace std;

/*
stack data structure implement
push operation
pop
size
top


*/

class stack{
    public:
    int size;
    int top=-1;
    int *arr;
    stack(int size){
        this->size=size;
        arr=new int[size];
    }

    void push(int element){
        if(top<size){
            top++;
            arr[top]=element;
        }else{
            cout<<"Size is full";
        }
    }

    int topElement(){
        if(top!=-1){
            return arr[top];
        }
        return -1;
    }

    int size1(){
        return top+1;
    }
    void pop(){
        if(top!=-1){
            top--;
        }else{
            cout<<"Stack is empty";
        }
        
    }
};
int main(){
    stack s(5);
    s.push(2);
    cout<<s.topElement()<<endl;
    cout<<s.size1();

    return 0;
}