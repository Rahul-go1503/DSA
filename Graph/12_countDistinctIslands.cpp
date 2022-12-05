#include <bits/stdc++.h>
using namespace std;


// cannot solve by storing path (wasted 1hr to solve (-|) ;
class Solution {
    void dfs(int i, int j, vector<vector<int>>& grid,vector<pair<int,int>> &shape,int x, int y){
        int n = grid.size();
        int m = grid[0].size();
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return;
        grid[i][j]=0;
        shape.push_back({i-x,j-y});
        dfs(i-1,j,grid,shape,x,y);
        dfs(i,j+1,grid,shape,x,y);
        dfs(i+1,j,grid,shape,x,y);
        dfs(i,j-1,grid,shape,x,y);
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // unordered_set se error throw hua
        set<vector<pair<int,int>>> s;
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    vector<pair<int,int>> shape;
                    dfs(i,j,grid,shape,i,j);
                    s.insert(shape);
                }
            }
        }
        return s.size();
    }
};