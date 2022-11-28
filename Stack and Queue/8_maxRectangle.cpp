#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(n(m+m)), SC - O(m + m)
class Solution {
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int res = 0, n = heights.size(), h, l;
        for(int i = 0; i <= n; ++i) {
            while(!stk.empty() && (i == n || heights[stk.top()] > heights[i])) {
                h = heights[stk.top()]; stk.pop();
                l =  stk.empty() ? -1 : stk.top();
                res = max(res, h * (i - 1 - l));
            }
            stk.push(i);
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size() , m = mat[0].size();
        int mx =0;
        vector<int> h(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                h[j] = mat[i][j]=='0' ? 0 : ++h[j];
            }
            mx = max(mx, largestRectangleArea(h));
        }
        return mx;
    }
};