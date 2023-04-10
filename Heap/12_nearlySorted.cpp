#include<bits/stdc++.h>
using namespace std;

/*
each element is at most k away from its target position
so k window size ki window me jo min elem hoga vhi phele aayega

ith elem within next k elem me hi hoga naa

- O(nlogk);
- O(k);
*/
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        priority_queue<int> pq;
        int i = 0;
        for(i=0;i<=k;i++) pq.push(-arr[i]);
        vector<int> res(n);
        int j = 0;
        while(i<n){
            int a = - pq.top(); 
            pq.pop();
            res[j++] = a;
            pq.push(-arr[i++]);
        }
        
        while(pq.size()){
            res[j++] = - pq.top();
            pq.pop();
        }
        return res;
    }
};