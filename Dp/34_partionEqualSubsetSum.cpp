#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(int i, int tar, vector<int> &nums, vector<vector<int>> &dp){
        if(tar == 0) return true;
        int n = nums.size();
        if(i>=n || tar < 0) return false;
        if(dp[i][tar] != -1) return dp[i][tar];
        return dp[i][tar] = solve(i+1, tar - nums[i], nums, dp) || solve(i+1, tar, nums,dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        int totSum = accumulate(nums.begin(),nums.end(),0);
        if(totSum%2) return false;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(totSum/2 + 1,-1));
        return solve(0,totSum/2,nums,dp);
    }
};