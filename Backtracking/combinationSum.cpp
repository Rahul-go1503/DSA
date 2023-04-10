#include <bits/stdc++.h>
using namespace std;

/*
Reading the question we understand that we need every possible unique combination such that sum of the 
combination is equal to target.

For such questions where we have to find "every possible" we generally use backtracking.
*/

// Backtracking
class Solution {
    void solve(vector<int>& can, int tar,int j,vector<int> &temp,vector<vector<int>> &ans){
        if(tar==0){
            ans.push_back(temp);
            return;
        }
        if(tar<0) return;
        // for(int k=j;k>=0;k--){
        for(int k=j;k<can.size();k++){
            temp.push_back(can[k]);
            solve(can,tar-can[k],k,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        // sort(can.begin(),can.end());
        // int j = lower_bound(can.begin(),can.end(),tar)- can.begin();
        // if(j==can.size())j--;
        int j=0;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(can,tar,j,temp,ans);
        return ans;
    }
};
