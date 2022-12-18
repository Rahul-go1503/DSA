#include <bits/stdc++.h>
using namespace std;
// we cans solve by backtrack onlt is n is small else it is a dp question( 0/1 knapsack)
class Solution{
    int solve(int i, int n, int *arr,int sum,int total){
        if(i==n && sum==total){
            return 1;
        }
        for(int k=i;k<n&&sum<total;k++){
            sum+=arr[k];
            int temp = solve(k+1,n,arr,sum,total);
            sum-=arr[k];
            if(temp) return 1;
        }
        return 0;
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum =0;
        for(int i=0;i<N;i++) sum+=arr[i];
        if(sum%2!=0) return 0;
        return solve(0,N,arr,0,sum/2);
    }
};
// getting tle on leetcode .. excepeted on gfg (:
class Solution {
    bool solve(int i, int tar, vector<int> &nums){
        if(tar == 0) return true;
        int n = nums.size();
        if(i>=n || tar < 0) return false;
        return solve(i+1, tar, nums) || solve(i+1, tar - nums[i], nums);
    }
public:
    bool canPartition(vector<int>& nums) {
        int totSum = accumulate(nums.begin(),nums.end(),0);
        if(totSum%2) return false;
        // sort(nums.begin(),nums.end());
        return solve(0,totSum/2,nums);
    }
};
// read dp solution
// https://leetcode.com/problems/partition-equal-subset-sum/solutions/1624939/c-python-5-simple-solutions-w-explanation-optimization-from-brute-force-to-dp-to-bitmask/