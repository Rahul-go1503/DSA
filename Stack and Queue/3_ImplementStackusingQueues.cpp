/********************************************************************************************* 
 
Question : 225. Implement Stack using Queues


Notes : 

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int>stack;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        stack.push(x);
        int i=stack.size();
        while(i>1){
            stack.push(stack.front());
            stack.pop();
            i--;
        }
    }
    
    int pop() {
        int x= stack.front();
        stack.pop();
        return x;
    }
    
    int top() {
        return stack.front();
    }
    
    bool empty() {
        return stack.empty();
    }
};



int main(){

}