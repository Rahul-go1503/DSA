#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O(n3)
	Space Complexity: O(n2)
*/

class Solution {
    int solve(vector<int> &val,int s , int e,vector<vector<int>> &dp){
        if(s+1==e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int mn = INT_MAX;
        for(int i=s+1;i<e;i++){
            int ans = val[s]*val[i]*val[e] + solve(val,s,i,dp) + solve(val,i,e,dp);
            mn = min(mn,ans);
        }
        return dp[s][e]=mn;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(values,0,n-1,dp);
    }
};