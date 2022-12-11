#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int i, int j, vector<vector<int>> &grid,queue<pair<int,int>> &q){
        int n = grid.size();
        grid[i][j] = 2;

        int dir[] = {1,0,-1,0,1};
        for(int d=0;d<4;d++){
            int r = i + dir[d];
            int c = j + dir[d+1];
            
            if(r<0 || c<0 || r>=n || c>=n || grid[r][c] == 2) continue;
            if(grid[r][c]==0){
                q.push({r,c});
                grid[r][c] = 2;
                continue;
            }
            dfs(r,c,grid,q);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dfs(i,j,grid,q);
                    cnt++;
                    break;
                }
            }
            if(cnt) break;
        }
        int lv = 0;
        while(q.size()){
            int sz = q.size();
            lv++;
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                int dir[] = {1,0,-1,0,1};
                for(int d=0;d<4;d++){
                    int r = i + dir[d];
                    int c = j + dir[d+1];

                    if(r<0 || c<0 || r>=n || c>=n || grid[r][c]==2) continue;
                    if(grid[r][c] == 1) return lv;
                    grid[r][c] = 2;
                    q.push({r,c});
                }
            }
        }
        return -1;
    }
};