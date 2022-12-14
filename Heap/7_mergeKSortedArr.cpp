#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
class Solution
{
    public:
    //Function to merge k sorted arrays.
    // all arr has same size= k, no of array =k
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        vector<int> merge(k*k);
        
        for(int i=0; i<k;i++){
            // we have to store val,r,c 
            pq.push({arr[i][0],i,0});
        }
        
        int i = 0;
        while(pq.size()){
            int val = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();
            merge[i++] = val;
            if(c + 1 < k) pq.push({arr[r][c+1],r,c+1});
        }
        return merge;
    }
};