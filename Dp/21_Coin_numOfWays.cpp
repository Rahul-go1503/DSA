#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    ll solve(int coins[],int n,int val, vvi &memo)
    {
        if(val==0) return 1;
        if(n==0) return 0;
        if(memo[val][n] != -1) return memo[val][n];
        
        ll cnt = 0;
        if(coins[n-1] <= val){
            cnt += solve(coins,n,val-coins[n-1],memo);
        }
        cnt += solve(coins,n-1,val,memo);
        
        return memo[val][n] = cnt;
    }
    
    ll numberOfWays(int coins[],int n,int val){
        vvi memo(val+1,vi(n+1,-1));
        // for(int i=0;i<=val;i++) memo[i][0] = 0;
        // for(int i=0;i<=n;i++) memo[0][i] = 1;
        return solve(coins,n,val,memo);
    }
};