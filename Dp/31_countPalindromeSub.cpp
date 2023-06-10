#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
class Solution{
    long long solve(string &str, int l, int r, vector<vector<int>> &dp){
        if(l>r) return 0;
        
        if(dp[l][r] != -1) return dp[l][r];
        
        long long cnt = 0;
        cnt = (cnt + solve(str,l+1,r,dp))%mod;
        cnt = (cnt + solve(str,l,r-1,dp))%mod;
        if(str[l] == str[r]){
            cnt = (1+ cnt)%mod;
        }
        else{
            long long t = solve(str,l+1,r-1,dp);
            cnt = (cnt - t + mod)%mod;
        }
        
        
        return dp[l][r] = cnt;
    }
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       int n = str.length();
       vector<vector<int>> dp(n,vector<int>(n,-1));
       return solve(str,0,n-1,dp);
    }
     
};



/*
    fun(C1strC2) = fun(_fun(str)_) + fun(C1fun(str)_) + fun(_fun(str)C2) + fun(C1fun(str)C2);
    fun(Cstr) = fun(_fun(str)) + fun(Cfun(str));
    fun(strC) = fun(fun(str)_) + fun(fun(str)C);
*/
const int mod = 1e9 + 7;
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       int n =str.length();
       vector<vector<long long>> dp(n,vector<long long>(n,1));
       
       // diagonal filling the table
       for(int g=1;g<n;g++){
           for(int i=0,j=g;j<n;i++,j++){
               if(g==1) dp[i][j] = 2 + (str[i] == str[j]);
               else{
                   // prefix + suffix
                   dp[i][j] = dp[i][j-1] + dp[i+1][j] + (str[i] == str[j]);
                   if(str[i] != str[j]) dp[i][j] -= dp[i+1][j-1];
               }
               dp[i][j] = (dp[i][j] + mod)%mod;
           }
       }
       return dp[0][n-1];
    }
     
};