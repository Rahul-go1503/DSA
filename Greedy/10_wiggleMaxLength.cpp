#include <bits/stdc++.h>
using namespace std;

/*
We need to find the length of the longest wiggle subsequence. A wiggle subsequence consists of a subsequence with numbers which 
appears in alternating ascending / descending order.

-- Dp question , use greedy for optimization

https://leetcode.com/problems/wiggle-subsequence/solutions/127714/wiggle-subsequence/
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int old_slope = 0, cnt = 1, s = 0;
        for(int i = 1; i<n;i++){
            if(nums[i]==nums[s]) continue;
            int new_slope = nums[i] - nums[s] > 0 ? 1 : -1;
            if(old_slope != new_slope) cnt++;
            old_slope = new_slope;
            s = i;
        }
        return cnt;
    }
};