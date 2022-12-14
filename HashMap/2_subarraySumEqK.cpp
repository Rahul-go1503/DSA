#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix[n];
        unordered_map<int,int> mp;
        prefix[0] = nums[0];
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + nums[i];

        mp[0] = 1;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(mp.count(prefix[i]-k)) cnt += mp[prefix[i]-k];
            mp[prefix[i]]++;
        }
        return cnt;
    }
};

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> map;
    
    int sum = 0, result = 0;
    map[sum] = 1;
    
    for (int n : nums) {
        sum += n;
        result += map[sum - k];
        map[sum]++;
    }
    
    return result;
}