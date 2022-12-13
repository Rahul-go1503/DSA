#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int i, int j, vector<vector<int>>& grid, int clr,vector<vector<int>> &vis){
        int m = grid.size();
        int n = grid[0].size();
        int ci = grid[i][j];

        // mark vis
        vis[i][j] = 1;
        int dir[] = {1,0,-1,0,1};
        for(int d=0;d<4;d++){
            int r = i + dir[d];
            int c = j + dir[d+1];
            // if out of boundary or (diff initial color and not vis) then color it
            if(r<0 || c<0 || r>=m || c>=n || (grid[r][c] != ci && vis[r][c]==0)){
                grid[i][j] = clr;
            } // else if cell is not vis and same color do dfs
            else if(!vis[r][c] && grid[r][c] == ci) dfs(r,c,grid,clr,vis);

            // if vis or diff color ignore
        }
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if(grid[row][col]==color) return grid;
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n));
        dfs(row,col,grid,color,vis);
        return grid;
    }
};