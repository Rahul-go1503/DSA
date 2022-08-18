/*********************************************************************************************

Question : 221. Maximal Square


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Recursive
    int solve(vector<vector<char>>& m,int i,int j){
        if(i>=m.size() || j>=m[0].size() || i<0 || j<0) return 0;
        int right = solve(m,i,j+1);
        int down = solve(m,i+1,j);
        int diagonal = solve(m,i+1,j+1);
        if(m[i][j]=='1'){
            return 1+min(right,min(down,diagonal));
        }else{
            return 0;
        }
    }
    //Memo
    int solveMem(vector<vector<char>>& m,int i,int j,vector<vector<int>> & dp,int &ans){
         if(i>=m.size() || j>=m[0].size() || i<0 || j<0) return 0;
         if(dp[i][j]!=-1) return dp[i][j];
        int r = solveMem(m,i,j+1,dp,ans);
        int d = solveMem(m,i+1,j,dp,ans);
        int dia = solveMem(m,i+1,j+1,dp,ans);
        if(m[i][j]=='1'){
            int temp= 1+min(r,min(d,dia));
            ans=max(ans,temp);
            // cout<<"1: i="<<i<<" j="<<j<<" "<<" temp="<<temp<< ans<<endl;
            return dp[i][j]=temp;
        }else{
            // ans=0;
            // cout<<"0: i="<<i<<" j="<<j<<" "<<ans<<endl;
            return dp[i][j] = 0;
        }
    }
    //Tab
    int solveTab(vector<vector<char>>& m){
        int ans=0;
        vector<vector<int>> dp(m.size()+1,vector<int> (m[0].size()+1,0));
        for(int i=m.size()-1;i>=0;i--){
            int j;
            for(j=m[0].size()-1;j>=0;j--){
                int r = dp[i][j+1];
                int d = dp[i+1][j];
                int dia = dp[i+1][j+1];
                dp[i][j] = m[i][j]=='1'? 1+min(r,min(d,dia)) : 0;
                ans= max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
    //space
    int solveTab(vector<vector<char>>& m){
        int ans=0;
        vector<int> curr(m[0].size()+1,0);
        vector<int> nxt(m[0].size()+1,0);
        // IMP : itrating right to left it is important
        for(int i=m.size()-1;i>=0;i--){
            int j;
            for(j=m[0].size()-1;j>=0;j--){
                int r = curr[j+1];
                int d = nxt[j];
                int dia = nxt[j+1];
                curr[j] = m[i][j]=='1'? 1+min(r,min(d,dia)) : 0;
                ans= max(ans,curr[j]);
            }
            nxt=curr;
        }
        return ans*ans;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),-1));
        int ans=0;
        return solveMem(matrix,0,0,dp,ans);*/
        return solveTab(matrix);
    }
};