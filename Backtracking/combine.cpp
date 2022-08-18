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
    //BackTracking
    void solve(int n , int k,int index, vector<int> & comb, vector<vector<int>>& ans){
        if(k==0){
            ans.push_back(comb);
        }
        for(int i=index; i<=n;i++){
            comb.push_back(i);
            solve(n,k-1,i+1,comb,ans);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(n,k,1,comb,ans);
        return ans;
    }
};