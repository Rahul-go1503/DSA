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
    void solve(vector<int>& nums,int i,int n,vector<int> per,vector<vector<int>> &ans,vector<bool> &vis){
        if(i==n) {
            //backtraacking
            ans.push_back(per);
            return;
        }
        for(int k=0;k<n;k++){
            if(vis[k]) continue;
            vis[k] = true;
            per.push_back(nums[k]);
            solve(nums,i+1,n,per,ans,vis);
            vis[k] = false;
            per.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> per;
        int n= nums.size();
        vector<bool> vis(n+1,false);
        solve(nums,0,n,per,ans,vis);
        return ans;
    }
};

/*
	Time Complexity: O(N! * N) 
	Space Complexity: O(1)

	Where 'N' is the total number of elements in the array.
*/
class Solution {
    void solve(vector<vector<int>>& res, vector<int>& nums, int pos){
        if(nums.size() == pos){
            res.push_back(nums);
            return ;
        }
        for(int i=pos; i < nums.size(); ++i){
            if(i==pos){
                solve(res, nums, pos + 1);
                continue;
            }
            swap(nums[i], nums[pos]);
            solve(res, nums, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(res, nums, 0);
        return res;
    }
};