#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int idx, int prevIdx,vector<int>& arr1, vector<int>& arr2, vector<vector<int>> &dp){
        int n = arr1.size(), m = arr2.size();
        if(idx>=n) return 0;

        if(dp[idx][prevIdx] != -1) return dp[idx][prevIdx];
        int prev = -1;
        if(idx > 0) prev = prevIdx == m ? arr1[idx-1] : arr2[prevIdx];
        int j = upper_bound(arr2.begin(),arr2.end(),prev) - arr2.begin();

        int res1 = INT_MAX, res2 = INT_MAX;
        if(arr1[idx]>prev){
            // not replace
            res1 = solve(idx+1,m,arr1,arr2,dp);
        }
        // replace
        if(j<arr2.size()){
            res2 = solve(idx+1,j,arr1,arr2,dp);
            if(res2 != INT_MAX) res2++;
        }
        return dp[idx][prevIdx] = min(res1,res2);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int n = arr1.size(), m = arr2.size();

        vector<vector<int>> dp(n,vector<int>(m+1,-1));
        int res = solve(0,m,arr1,arr2,dp);
        if(res==INT_MAX) return -1;
        else return res;
    }
};