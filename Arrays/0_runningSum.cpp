#include <bits/stdc++.h>
using namespace std;
/*
- calculating prefix sum basically
*/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int temp=0;
        for(auto &v: nums){
            temp += v;
            ans.push_back(temp);
        }
        return ans;
    }
};