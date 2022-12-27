#include <bits/stdc++.h>
using namespace std;

// O(n),O(1) 
// can solve by dp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), farIdx = 0;
        for(int i = 0; i<=farIdx && i<n;i++){
            farIdx = max(farIdx,i+nums[i]);
            if(farIdx >= n-1) return true;
        }
        return false;
    }
};