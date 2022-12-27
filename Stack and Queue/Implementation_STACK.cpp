/********************************************************************************************* 
 
Question : 


Notes : 

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;
    public:
    Stack(int size){
        this->top=-1;
        this->size=size;
        this->arr= new int[this->size];
    }
    void push(int data){
        if(size-top>1){
            top++;
            arr[top]=data;
        }
    }
    void pop(){
        if(top!=-1){
            top--;
        }
    }
    int top(){
        if(size-top>1) return arr[top];
    }

    bool empty(){
        if(top==-1) return true;
        return false;
    }
    int size(){
        return top+1;
    }
};
