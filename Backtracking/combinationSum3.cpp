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
    void solve(int k ,int n,int val, vector<vector<int>> & ans, vector<int> & temp){
        if(k==0 && n==0){
            ans.push_back(temp);
            return;
        }
        if(k==0 || n==0) return;
        for(int i=val;i<=9 && i<=n;i++){
            temp.push_back(i);
            solve(k-1,n-i,i+1,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> ans;
        vector<int> temp;
        solve(k,n,1,ans,temp);
        return ans;
    }
};