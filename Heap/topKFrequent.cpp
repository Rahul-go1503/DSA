/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(auto val : nums) mp[val]++;
        for(auto itr = mp.begin();itr!=mp.end();itr++){
            if(pq.size()<k) pq.push({itr->second,itr->first});
            if(itr->second>pq.top().first){
                pq.pop();
                pq.push({itr->second,itr->first});
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};