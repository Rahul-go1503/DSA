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
        if(i>n){
            return;
        }
        ans.push_back(sub);
        for(int k=i;k<n;k++){
            sub.push_back(nums[k]);
            solve(nums,k+1,n,sub,ans);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> sub;
        solve(nums,0,n,sub,ans);
        return ans;
    }
};