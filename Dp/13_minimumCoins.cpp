#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O()
	Space Complexity: O()
*/

#include<bits/stdc++.h>
int solve(vector<int> &days,vector<int> &cost, int idx = 0){
    if(idx>=days.size()) return 0;
    int mn = INT_MAX;
    int pass[3] = {1,7,30};
    for(int i=0;i<cost.size();i++){
        int k = upper_bound(days.begin()+idx+1,days.end(),days[idx]+pass[i]-1)-days.begin();
        mn = min(mn ,cost[i]+ solve(days,cost,k));
    }
    return mn;
}
int solve2(vector<int> &days,vector<int> &cost, int idx = 0){
    if(idx>=days.size()) return 0;

    // 1day pass
    int op1 = cost[0] + solve2(days,cost,idx+1);

    int i = idx;
    // 7- days
    for(i=idx;i< days.size() && days[i]<days[idx]+7;i++);
    int op2 = cost[1] + solve2(days,cost,i);

    // 30- days pass
    for(i=idx;i< days.size() && days[i]<days[idx]+30;i++);
    int op3 = cost[2] + solve2(days,cost,i);

    return min(op1,min(op2,op3));
}
int solveMem(vector<int> &days,vector<int> &cost,vector<int> &dp, int idx = 0){
    if(idx>=days.size()) return 0;
    if(dp[idx]!=INT_MAX) return dp[idx];
    int pass[3] = {1,7,30};
    for(int i=0;i<cost.size();i++){
        int k = upper_bound(days.begin()+idx+1,days.end(),days[idx]+pass[i]-1)-days.begin();
        dp[idx] = min(dp[idx] ,cost[i]+ solve(days,cost,k));
    }
    return dp[idx];
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n,INT_MAX);
    return solve(days,cost);
    return solveMem(days, cost,dp);
}