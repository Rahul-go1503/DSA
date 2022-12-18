/*********************************************************************************************

Question :
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that
 nums[i] == nums[j] and abs(i - j) <= k.

Notes :
- kisi ke index ke k area me koi same val exist krti hai ki nhi and i!=j;

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // sliding window ques
    // TC - O(N);
    // SC - max can be n elem in set
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        if (k == 0) return false;
        if (k >= nums.size()) k = nums.size() - 1; // redundant code
        for(int i=0;i<n;i++){
            // out of window - erase prev elem
            if(i>k) s.erase(nums[i-k-1]);
            if(!s.empty() && s.find(nums[i])!=s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};