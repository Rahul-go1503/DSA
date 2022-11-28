#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(), SC - O()


class Solution {
    int solve(string s , string t, int i ,int j,vector<vector<int>> & dp){
        int n1 = s.length();
        int n2 = t.length();
        if(i==-1 && j==-1){
            return dp[i+1][j+1] = 0;
        }
        if(i==-1){
            return dp[i+1][j+1] = j+1;
        }
        if(j==-1){
            return dp[i+1][j+1] = i+1;
        }
        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
        
        if(s[i]==t[j]){
            return dp[i+1][j+1] = solve(s,t,i-1,j-1,dp);    
        }else{
            return dp[i+1][j+1] = 1+ min(solve(s,t,i-1,j-1,dp),min(solve(s,t,i-1,j,dp),solve(s,t,i,j-1,dp)));
        }
    }
  public:
    int editDistance(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solve(s,t,n1-1,n2-1,dp);
    }
};