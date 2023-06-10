#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(n2), SC - O(n2)
// not solved

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char *X, char *Y, int m, int n)
{
    // intitalizing a matrix of size (m+1)*(n+1)
    int L[m + 1][n + 1];
 
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
        that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
    return L[m][n];
}

// leetcode
class Solution {
    int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int res = 0;
        if(text1[i]==text2[j]){
            int t = solve(text1, text2, i-1, j-1,dp);
            res = 1 + t;
        }
        else {
            int t1 = solve(text1, text2,i,j-1,dp);
            int t2 = solve(text1, text2,i-1,j,dp);
            res = max(t1,t2);
        }
        return dp[i][j] = res;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(text1,text2,n-1,m-1,dp);
    }
};