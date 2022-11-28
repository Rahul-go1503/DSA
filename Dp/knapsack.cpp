/*********************************************************************************************

Question : 


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 
int solveRec(vector<int> weight, vector<int> value, int n, int maxWeight){
    if(n<0 || maxWeight<0) return 0;
    int include =0;
    if(weight[n-1]<=maxWeight)
        include = value[n-1]+solveRec(weight,value,n-1,maxWeight-weight[n-1]);
    
    int exclude = solveRec(weight,value,n-1,maxWeight);
    return max(include,exclude);
}
int solveMem(vector<int> weight, vector<int> value, int n, int maxWeight,vector<vector<int>> & dp){
    if(n<0 || maxWeight<=0) return 0;
    if(dp[n][maxWeight]!=-1) return dp[n][maxWeight];
    int include =0;
    if(weight[n-1]<=maxWeight)
        include = value[n-1]+solveMem(weight,value,n-1,maxWeight-weight[n-1],dp);
    
    int exclude = solveMem(weight,value,n-1,maxWeight,dp);
    return dp[n][maxWeight] = max(include,exclude);
}

int solveTab(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,0));
    for(int i=1;i<n;i++){

    }
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n+1,vector<int>(maxWeight+1,-1));
    return solveMem(weight,value,n,maxWeight,dp);
}