#include <bits/stdc++.h>
using namespace std;

// Recursive ~~ T(T)= exp,T(S)=O(1)
class Solution {
    int solve(int n){
        if(n==0||n==1)return 1;
        return solve(n-1)+solve(n-2);
    }
public:
    int climbStairs(int n) {
        return solve(n);
    }
};

// top-down , memoizations
class Solution {
    int solve(int n,vector<int> &dp){
        if(dp[n]!=-1)return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;dp[1]=1;
        solve(n,dp);
        return dp[n];
    }
};

//Bottom-up approach -- Tabulation
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// space optimaztion
class Solution {
public:
    int climbStairs(int n) {
        int prev1=1;
        int prev2=1;
        int ans =1;
        for(int i=2;i<=n;i++){
            ans= prev1+prev2;
            prev2=prev1;
            prev1=ans;
        }
        return ans;
    }
};