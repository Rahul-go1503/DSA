#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string &s, int l, int r,vector<vector<int>> &dp){
        if(l>r) return 0;
        if(l==r) return 1;
        if(dp[l][r] != -1) return dp[l][r];

        int res = 0;
        if(s[l] == s[r]){
            int t = solve(s,l+1,r-1,dp);
            res = 2 + t;
        }
        else{
            int t1 = solve(s,l,r-1,dp);
            int t2 = solve(s,l+1,r,dp);
            res = max(t1,t2);
        }
        return dp[l][r] = res;
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
    }
};