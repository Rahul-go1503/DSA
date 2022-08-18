/********************************************************************************************* 
 
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums

**********************************************************************************************/

#include <bits/stdc++.h>
using namespace std;
vector<int> runningSum(vector<int>& nums) {
    vector<int>ans;
    int temp=0;
        for (auto v: nums){
            temp+=v;
            ans.push_back(temp);
        }
        return ans;
}