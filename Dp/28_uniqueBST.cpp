#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
typedef long long ll;

/*
 - dp[i] = count of uniquebst if node is i;
 - j = no of nodes in the left sides;
*/
class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        ll dp[N+1] = {};
        dp[0] = 1, dp[1] = 1;
        for(int i = 2;i<=N;i++){
            // think j as root node
            for(int j = 0;j<i;j++){
                dp[i] = (dp[i] + dp[j]*dp[i-1-j]%mod)%mod;
            }
        }
        return dp[N];
    }
};


const int mod = 1000000007;
typedef long long ll;
class Solution
{
    ll recur(int i,ll memo[]){
        if(i<=1) return 1;
        if(memo[i] != -1) return memo[i];
        memo[i] = 0;
        for(int j=0;j<i;j++){
            memo[i] = (memo[i] + recur(j,memo) * recur(i-1-j,memo)%mod)%mod;
        }
        return memo[i];
    }
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        ll memo[N+1];
        memset(memo,-1,sizeof(memo));
        return recur(N,memo);
    }
};