#include <bits/stdc++.h> 
using namespace std;
class NStack{
    int free,*next ,*top,*arr;
public:
    // Initialize your data structure.
    NStack(int N, int S){
        next = new int[S];
        arr = new int[S];
        top = new int[N+1];
        free = 0;
        for(int i = 0;i<S;i++){
            next[i] = i+1;
            if(i<N) top[i] = -1;
        }
        next[S-1] = -1;
        top[N] =-1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m){
        if(free==-1) return false;
        int i = free;   // find free index
        free = next[i]; // update free 
        next[i] = top[m]; // next me ab prev elem ka index dalo... jis stack ka elem uss index par hai abhi uska prev index daal do
        top[m] = i; 
        arr[i] = x;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m){
        if(top[m]==-1) return -1;
        int i = top[m];  // find cuu idx
        top[m] = next[i]; // update top
        next[i] = free; // like free ko ek step piche le aaye... jo ab free hai vo next to next free hoga
        free = i;
        return arr[i];
    }
};