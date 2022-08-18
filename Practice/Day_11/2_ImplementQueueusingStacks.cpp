/********************************************************************************************* 
 
Question : 232. Implement Queue using Stacks



Notes : 
Do you know when we should use two stacks to implement a queue?
I was asked in the internship interview of a company two years ago.

The application for this implementation is to separate read & write of a queue in multi-processing. One of the stack is for read, and another is for write. They only interfere each other when the former one is full or latter is empty.

This is not only a trick. :)
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> queue;
    stack<int> temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        int queueSize=queue.size();
        for(int i=0;i<queueSize;i++){
            temp.push(queue.top());
            queue.pop();
        }
        queue.push(x);
        int tempSize=temp.size();
        for(int i=0;i<tempSize;i++){
            queue.push(temp.top());
            temp.pop();
        }

    }
    void push2(int x) {
        while(!queue.empty()){
            temp.push(queue.top());
            queue.pop();
        }
        queue.push(x);
        while(!temp.empty()){
            queue.push(temp.top());
            temp.pop();
        }
    }
    void push3(int x) {
        if(queue.empty()){
        queue.push(x);
        return;
        } 
        int temp= queue.top();
        queue.pop();
        push3(x);
        queue.push(temp);
    }
    int pop() {
        int temp= queue.top();
        queue.pop();
        return temp;
    }
    
    int peek() {
        return queue.top();
    }
    
    bool empty() {
        return !queue.size();
    }
};

/********************************************************************************************* 
 
I have one input stack, onto which I push the incoming elements, and one output stack, from which I peek/pop. I move elements from input stack to output stack when needed, i.e., when I need to peek/pop but the output stack is empty. When that happens, I move all elements from input to output stack, thereby reversing the order so it's the correct order for peek/pop.

The loop in peek does the moving from input to output stack. Each element only ever gets moved like that once, though, and only after we already spent time pushing it, so the overall amortized cost for each operation is O(1).

**********************************************************************************************/

class Queue {
    stack<int> input, output;
public:

    void push(int x) {
        input.push(x);
    }

    int pop(void) {
        int x=peek();
        output.pop();
        return x;
    }

    int peek(void) {
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool empty(void) {
        return input.empty() && output.empty();
    }
};



int main(){

}