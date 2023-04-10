#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************
 * 
 * for LdS multiply each element with -1;

**********************************************************************************************/

// TC - O(n2), SC - O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //Let dp[i] is the lis of nums[0..i] which has nums[i] as the end element of the subsequence.
        vector<int> dp(n,1);
        int res = 1;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i] && dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1;
                    res = max(res,dp[i]);
                }
            }
        }
        return res;
    }
};
// Greedy approach
//https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C++Python-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)

class Solution { // 8 ms, faster than 91.61%
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};
// https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326308/
// c-python-dp-binary-search-bit-segment-tree-solutions-picture-explain-o-nlogn/?orderBy=most_votes
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int len = 1;
        vector<int> tail;
        tail.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>tail.back()) tail.push_back(nums[i]),len++;
            else{
                int lo = lower_bound(tail.begin(),tail.end(),nums[i]) - tail.begin();
                tail[lo] = nums[i];
            }
        }
        return len;
    }
};