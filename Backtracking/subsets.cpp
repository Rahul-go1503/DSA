#include <bits/stdc++.h>
using namespace std;
/*
 - TC - N*2^N;
 - SC - N ?
 - Backtracking, recursive, dfs
*/
class Solution {
    void solve(vector<int>& nums,int i , int n, vector<int>& sub, vector<vector<int>> & ans){
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

/*
 - TC - N*2^N;
 - SC - N*2^N;
 - Beats - 44.81% , 87.59%
 - iterative, dp, bfs
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powset;
        powset.push_back({});
        for(auto &num : nums){
            auto temp = powset; // copied all subsets in the powerset
            for(auto &sub : temp){
                sub.push_back(num);
                powset.push_back(sub);
            }
        }
        return powset;
    }
};

/*
 - Beats - 100%, 71.8%
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powset;
        powset.push_back({});
        for(auto &num : nums){
            vector<vector<int>> temp; // only for new subsets
            for(auto sub : powset){
                sub.push_back(num);
                temp.push_back(sub);
            }
            for(auto &sub : temp){
                powset.push_back(sub);
            }
        }
        return powset;
    }
};

/*
 - Beats - 100%, 87.59%
*/
// jianchao-li
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
}; 


/*
 - BIT manipulation
 - jianchao-li
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n; // no of subsets = 2^n;
        vector<vector<int>> subs(p);
        // iterate for every number 0,1,2...2^n;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                // check for set bits
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};