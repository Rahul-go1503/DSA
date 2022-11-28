/*********************************************************************************************

Question : 322. Coin Change -- Standard problem
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Notes :
Love babbar adobe test , amazon me
1D dp 
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solveRec(vector<int>& coins, int amount){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        int ans = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int temp = solveRec(coins,amount-coins[i]);
            if(temp!=INT_MAX)
                ans=min(ans,1+temp);
        }
        return ans;
    }
    int solveMem(vector<int>& coins, int amount,vector<int> &dp){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int ans = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int temp = solveMem(coins,amount-coins[i],dp);
            if(temp!=INT_MAX)
                ans=min(ans,1+temp);
        }
        return dp[amount]=ans;

    }
    int solveTab(vector<int>& coins, int amount){
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0&&dp[i-coins[j]]!=INT_MAX)
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = solveMem(coins,amount,dp);
        return ans==INT_MAX? -1: ans;
    }
};

// self try wrong approach
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        int ans = 0;
        for(int i=n-1;i>=0 && amount>=0;i--){
            ans+=amount/coins[i];
            amount = amount%coins[i];
        }
        return amount>0?-1:ans;
    }
    // check this case
    //[186,419,83,408]
    // 6249
};