#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(m),curr(m);
        prev[0] = grid[0][0];
        for(int i=1;i<m;i++) prev[i] = grid[0][i] + prev[i-1];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                curr[j] = prev[j];
                if(j-1>=0) curr[j] = min(prev[j],curr[j-1]);
                curr[j] += grid[i][j];
            }
            prev = curr;
        }
        return prev[m-1];
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0]; 

        
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};