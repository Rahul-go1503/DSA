#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), curr = 0, mx = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) continue;
            curr = 1;
            while(i<n-1 && nums[i]==nums[i+1]) curr++,i++;
            mx = max(mx,curr);
        }
        return mx;
    }
};