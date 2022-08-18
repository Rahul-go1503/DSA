/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O()
	Space Complexity: O()

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<vector<int>>& res, vector<int> nums, int pos){
        if(pos==nums.size()){
            res.push_back(nums);
            return ;
        }
        for(int i=pos; i < nums.size(); ++i){
            if(i!=pos && nums[i]==nums[pos]) continue;
            if(i==pos){
                solve(res, nums, pos + 1);
                continue;
            }
            swap(nums[i], nums[pos]);
            solve(res, nums, pos + 1);
            // swap(nums[i], nums[pos]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums),end(nums));
        solve(res, nums, 0);
        return res;
    }
};