/*********************************************************************************************

Question : Coding Ninjas. Maximum sum of non-adjacent elements
 maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> & nums,int k){
    if(k<0) return 0;
    return max(nums[k] + solveRec(nums,k-2), solveRec(nums,k-1) );
}
int solveMem(vector<int> & nums,int k,vector<int>& dp){
    if(k<0) return 0;
    if(dp[k]!=-1) return dp[k];
    return dp[k] = max(nums[k] + solveMem(nums,k-2,dp), solveMem(nums,k-1,dp) );
}

int solveTab(vector<int> & nums){
    vector<int> dp (nums.size(),-1);
    dp[0]=nums[0];
    if(nums.size()>1)
        dp[1]= nums[1]>nums[0]? nums[1] : nums[0];
    for(int i=2;i<nums.size();i++){
        dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
    }
    return dp[nums.size()-1];
}
int solveTabSp(vector<int> & nums){
    int prev2=nums[0],prev1=nums[0];
    if(nums.size()>1)
        prev1= nums[1]>nums[0]? nums[1] : nums[0];
    for(int i=2;i<nums.size();i++){
        int curr = max(nums[i]+prev2,prev1);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}


int maximumNonAdjacentSum(vector<int> &nums){
 return solveRec(nums,nums.size()-1);
 vector<int> dp (nums.size(),-1);   
 return solveMem(nums,nums.size()-1,dp);   
 return solveTab(nums);   
 return solveTabSp(nums);   
}