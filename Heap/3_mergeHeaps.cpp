#include <bits/stdc++.h>
using namespace std;

class Solution{
    void maxHeapify(vector<int> &a, int i){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int n = a.size();
        int mx = i;
        
        if(l<n && a[mx] < a[l]) mx = l;
        if(r<n && a[mx] < a[r]) mx = r;
        
        if(mx != i){
            swap(a[mx],a[i]);
            maxHeapify(a,mx);
        }
    }
    
    vector<int> buildMaxHeap(vector<int> &a){
        int n = a.size();
        for(int i = n/2-1;i>=0;i--) maxHeapify(a,i);
        return a;
    }
    
    vector<int> merge(vector<int> &a, vector<int> &b){
        for(auto &val : b) a.push_back(val);
        return buildMaxHeap(a);
    }
    
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        if(n>m) return merge(a,b);
        else return merge(b,a);
    }
};