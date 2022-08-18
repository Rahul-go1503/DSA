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
    void solve(vector<int>& can, int tar,int j,vector<int> &temp,vector<vector<int>> &ans){
        if(tar==0){
            ans.push_back(temp);
            return;
        }
        if(tar<0) return;
        // for(int k=j;k>=0;k--){
        for(int k=j;k<can.size();k++){
            temp.push_back(can[k]);
            solve(can,tar-can[k],k,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        // sort(can.begin(),can.end());
        // int j = lower_bound(can.begin(),can.end(),tar)- can.begin();
        // if(j==can.size())j--;
        int j=0;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(can,tar,j,temp,ans);
        return ans;
    }
};
