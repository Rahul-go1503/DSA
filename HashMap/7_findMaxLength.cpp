#include <bits/stdc++.h>
using namespace std;

// idea -  count subarray with 0 and 1
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        // mapping of sum to index
        unordered_map<int,int> mp;
        int sum = 0;
        mp[sum] = -1;

        int mx = 0;
        for(int i=0;i<n; i++){
            sum += nums[i] == 1? 1 : -1;
            if(mp.find(sum) == mp.end()) mp[sum] = i; // only store first time
            else mx = max(mx,i-mp[sum]);
        }
        return mx;
    }
};