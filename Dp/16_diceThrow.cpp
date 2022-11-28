#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :
Given N dice each with M faces, numbered from 1 to M, find the number of ways to get sum X. X is the summation of values on each face when all the dice are thrown.

Notes :

**********************************************************************************************/
/*
	Time Complexity: O()
	Space Complexity: O()
*/

class Solution {
    
    // M^x total ways find out no of ways where sum==x
    // dp[n][x] means no of ways to form x by n dices
    long long int solve(int m , int n, int x,vector<vector<long long>> &dp){
        if(n==0&&x==0) return 1;
        if((x<=0&& n!=0) || (n==0 && x!=0)) return 0;
        
        if(dp[n][x]!=-1) return dp[n][x];
        long long ans = 0;
        // loop for each no on dice faces
        for(int i=1;i<=m;i++){
            ans+= solve(m,n-1,x-i,dp);
        }
        return dp[n][x] = ans;
    }
  public:
    long long noOfWays(int m , int n , int x) {
        vector<vector<long long>> dp(n+1,vector<long long> (x+1,-1));
        return solve(m,n,x,dp);
    }
};

// gfg solution
class Solution {
  public:
    long long noOfWays(int M , int N , int X) {
        
        // Create a table to store results of subproblems.  One extra  
        // row and column are used for simpilicity (Number of dice 
        // is directly used as row index and sum is directly used 
        // as column index).  The entries in 0th row and 0th column 
        // are never used. 
        long long table[N + 1][X + 1]; 
        memset(table, 0, sizeof(table)); // Initialize all entries as 0 
      
        // Table entries for only one dice 
        for (int j = 1; j <= M && j <= X; j++) 
            table[1][j] = 1; 
      
        // Fill rest of the entries in table using recursive relation 
        // i: number of dice, j: sum 
        for (int i = 2; i <= N; i++) 
            for (int j = 1; j <= X; j++) 
                for (int k = 1; k <= M && k < j; k++) 
                    table[i][j] += table[i-1][j-k]; 
      
        return table[N][X]; 
    }
};