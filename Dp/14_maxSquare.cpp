#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O(n*m)
	Space Complexity: O(n*m)
*/

class Solution{
     /*
        1 ->34
        2 ->24
        3 ->14
        4 ->04
        5 ->33
        6 ->23
        7 ->13
        8 ->03
        9 ->32
        10 ->22
        11 ->12
        12 ->02
        13 ->31
        14 ->21
        15 ->11
        16 ->01
        17 ->30
        18 ->20
        19 ->10
        20 ->00
    */
    int solve(vector<vector<int>> &mat,vector<vector<int>>&dp,int i, int j , int &mx){
        if(i>=mat.size() || j>=mat[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        // count max squares in r , d and b direction
        int r = solve(mat,dp,i,j+1,mx);
        int d = solve(mat,dp,i+1,j+1,mx);
        int b = solve(mat,dp,i+1,j,mx);
        
        if(mat[i][j]==0) return dp[i][j]=0;
        
        dp[i][j] = 1+ min(r,min(d,b));
        mx = max(mx,dp[i][j]);
        return dp[i][j];
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int mx = 0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        solve(mat,dp,0,0,mx);
        return mx;
    }

    // tabulation bottom-up approach

    /*
    End <----------------
        <----------------
        <---------------- Start
    */
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int mx = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int r = dp[i][j+1];
                int d = dp[i+1][j+1];
                int b = dp[i+1][j];
                
                if(mat[i][j]==0) dp[i][j]=0;
                else{
                    dp[i][j] = 1+ min(r,min(d,b));
                    mx = max(mx,dp[i][j]);
                }
            }
        }
        
        return mx;
    }

    // space optimization O(mn),O(m)
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int mx = 0;
        vector<int> row1(m+1,0);
        vector<int> row2(m+1,0);
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int r = row1[j+1];
                int d = row2[j+1];
                int b = row2[j];
                
                if(mat[i][j]==0) row1[j]=0;
                else{
                    row1[j] = 1+ min(r,min(d,b));
                    mx = max(mx,row1[j]);
                }
            }
                row2= row1;
        }
        
        return mx;
    }
};