#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
/*
 - if k = max num in a list
 - n = no of lists
 - PQ me always n element rhenge => SC - O(N)
 - TC - O(NLogN)
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        int mx = nums[0][0];
        for(int i=0; i<n;i++){
            pq.push({nums[i][0],i,0});
            mx = max(mx,nums[i][0]); // L isse bda hi hoga
        }
        int mn = INT_MAX;
        int L = mx, S = pq.top()[0]; // S ko kam krne ki kosis krenge
        while(pq.size()){
            auto v = pq.top();
            int r = v[1] , c = v[2];
            pq.pop();
            mn = v[0];
            if(mx - mn < L -S) S = mn , L = mx;
            if(v[2]+1 < nums[r].size()){
                pq.push({nums[r][c+1],r,c+1});
                mx = max(mx,nums[r][c+1]);
            }
            else return {S,L}; // jese hi ek list end hoti hai return kr jao 
        }
        return {}; // Not Reachable code
    }
};