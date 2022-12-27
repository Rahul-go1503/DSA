#include <bits/stdc++.h>
using namespace std;

/*
 - solve by hint , O(n2 + nlogn),O(n+n)
 - It might be a little simpler if you order [5,2] before [5,0], because then insertion of [5,2] will not be affected by [5,0].

 - nlogn soln by BITree check later
*/
class Solution {
    static bool cmp(vector<int>& p1, vector<int> &p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        return p1[1] > p2[1];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& ppl) {
        int n = ppl.size();
        vector<vector<int>> order(n);
        for(int i=0;i<n;i++) order[i] = ppl[i];
        sort(order.begin(),order.end());

        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            int k = order[i][1];
            for(int j=0;j<n;j++){
                if(ans[j].size() && ans[j][0] != order[i][0]) continue; // no need to check equality, exp above
                if(k==0){
                    ans[j] = order[i];
                    break;
                }
                k--;
            }
        }
        return ans;
    }
};