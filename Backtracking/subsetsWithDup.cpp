/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O(N)
	Space Complexity: O(N)

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
    void solve(vector<int>& nums,int i , int n, vector<int>& sub, vector<vector<int>> & ans){
        ans.push_back(sub);
        for(int k=i;k<n;k++){
            if(k != i && nums[k] == nums[k - 1]) continue;
            sub.push_back(nums[k]);
            solve(nums,k+1,n,sub,ans);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        solve(nums,0,n,sub,ans);
        return ans;
    }
};