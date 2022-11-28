#include <bits/stdc++.h> 
using namespace std;
class NQueue{
    int free,*next ,*front,*rear,*arr; 
public:
    // Initialize your data structure.
    NQueue(int n, int s){
        next = new int[s];
        arr = new int[s];
        front = new int[n+1];
        rear = new int[n+1];
        free = 0;
        for(int i = 0;i<s;i++){
            next[i] = i+1;
            if(i<n) front[i] = -1;
        }
        next[s-1] = -1;
        front[n] =-1;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(free==-1) return false;
        int i = free;
        free = next[i];
        if(front[m]==-1) front[m] = i;
        else next[rear[m]] = i;
        next[i] = -1;
        rear[m] = i;
        arr[i] = x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(front[m]==-1) return -1;
        int i = front[m];
        front[m] = next[i];
        next[i] = free;
        free = i;
        return arr[i];
    }
};