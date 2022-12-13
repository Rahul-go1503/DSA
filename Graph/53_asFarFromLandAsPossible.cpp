#include <bits/stdc++.h>
using namespace std;

class Solution {
    // multi- source bfs, you have to identify what will be sources in this case
    // Manhattan distance - when you can only go 4 directions, the (minimum) number of cells you travel from
    // point A to point B is the Manhattan distance.
    // O(N2) , O(N2);
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                }
            }
        }

        int md = -1;

        while(q.size()){
            int sz = q.size();
            md++;
            while(sz--){
                int i = q.front()[0];
                int j = q.front()[1];
                q.pop();

                int dir [] = {1,0,-1,0,1};
                for(int d=0;d<4;d++){
                    int r = i + dir[d];
                    int c = j + dir[d+1];
                    if(r<0 || c<0 || r>=n || c>=n || grid[r][c]) continue;
                    grid[r][c] = 1;
                    q.push({r,c});
                }
            }
        }
        // If all water then md==-1 , if all land md==0
        return md==0 ? -1 : md;
    }
};