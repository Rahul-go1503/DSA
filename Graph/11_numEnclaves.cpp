#include <bits/stdc++.h>
using namespace std;

// boundary dfs
class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        
        if(i<0 || i>=n || j<0 ||j>=m || grid[i][j]!=1) return;
        grid[i][j] = '#';
        vector<int> dir = {-1,0,1,0,-1};
        for(int d=0;d<4;d++){
            int r = i + dir[d];
            int c = j + dir[d+1];
            dfs(grid,r,c);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // check first and last row
        for(int j=0;j<m;j++){
            if(grid[0][j]) dfs(grid,0,j);
            if(grid[n-1][j]) dfs(grid,n-1,j);
        }
        
        // check first and last column
        for(int i=0;i<n;i++){
            if(grid[i][0]) dfs(grid,i,0);
            if(grid[i][m-1]) dfs(grid,i,m-1);
        }
        
        int one = 0;
        
        for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1) one++;
                if(grid[i][j]=='#') grid[i][j]=1;
	        }
	    }
        return one;
    }
};