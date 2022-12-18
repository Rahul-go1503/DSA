#include <bits/stdc++.h>
using namespace std;
// another approach - counter table - read official soln

/*
TC - 2^N 
SC -N
*/
class Solution {
    void solve(int currIdx, vector<int>& candid, int tar, vector<int> &temp, vector<vector<int>> &ans){
        if(tar==0){
            // st.insert(temp);
            ans.push_back(temp);
            return;
        }
        if(tar < 0) return;

        int n = candid.size();
        for(int i = currIdx; i<n; i++){
            // i > 0 --> wrong.. think
            if(i>currIdx && candid[i]==candid[i-1]) continue;
            temp.push_back(candid[i]);
            solve(i+1,candid,tar-candid[i],temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candid, int tar) {
        sort(candid.begin(),candid.end()); // bcoz we required unique combination by sorting we can skip duplicates values easily.
        set<vector<int>> st; // no need
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,candid,tar,temp,ans);
        // for(auto &sol : st) ans.push_back(sol);
        return ans;
    }
};