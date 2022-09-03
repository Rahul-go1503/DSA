/********************************************************************************************* 
 
Question : 

Notes : 
You can just replace "stack" with "vector" and it'll work perfectly since vector has all the functionality of a stack. The only purpose of stack in STL is to make it clearer to the reader.

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class MinStack {
    int *arr;
    int peak;
public:
    //Day_10
    MinStack() {
        arr= new int[100000];
        this->peak=-1;
    }
    
    void push(int val) {
        peak++;
        arr[peak]=val;
    }
    
    void pop(){ peak--; }
    int top() { return arr[peak]; }
    
    void solve(){

    }
    int getMin() {
        solve();
    }
};


int main(){

}