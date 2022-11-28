/*********************************************************************************************

Question : House Robber II


Notes :
1. circular problem
2. None of the selected n elements could be neighbor to each others.
3. dp[i] indicates dp[no of houses robbed] ??

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

long long int solveRec(vector<int>& nums, int i,int j){
    if(i>j) return 0;
    return max(nums[j] + solveRec(nums,i,j-2), solveRec(nums,i,j-1) );
}
long long int solveMem(vector<int>& nums, int i,int j,vector<long long int>&dp){
    if(i>j) return 0;
    if(dp[j]!=-1) return dp[j];
    return dp[j] = max(nums[j] + solveMem(nums,i,j-2,dp), solveMem(nums,i,j-1,dp));
}

long long int solveTab(vector<int> & nums,int s, int e){
    vector<long long int> dp (nums.size(),-1);
    dp[s]=nums[s];
    if(e-s>0)
        dp[s+1]= nums[s+1]>nums[s]? nums[s+1] : nums[s];
    for(int i=s+2;i<=e;i++){
        dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
    }
    return dp[e];
}

long long int houseRobber(vector<int>& nums)
{
    int n= nums.size()-1;
    if(n>0){
//         return max(solveRec(nums,0,n-1),solveRec(nums,1,n));
        vector<long long int> dp1(n+1,-1);
        vector<long long int> dp2(n+1,-1);
        return max(solveMem(nums,0,n-1,dp1),solveMem(nums,1,n,dp2));
        return max(solveTab(nums,0,n-1),solveTab(nums,1,n));
    }
    return nums[0];
}