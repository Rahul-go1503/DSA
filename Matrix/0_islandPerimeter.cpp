#include <bits/stdc++.h>
using namespace std;

// TC - 4mn
// SC - 1
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int peri = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int dir[] = {1,0,-1,0,1};
                    for(int d=0;d<4;d++){
                        int r = i + dir[d];
                        int c = j + dir[d+1];
                        if(r<0 || c<0 || r>=n || c>=m || grid[r][c]==0) peri++;
                    }
                }
            }
        }
        return peri;
    }
};
// TC - 2mn
//islands * 4 - neighbours * 2, since every adjacent islands made two sides disappeared
class Solution {
public: int islandPerimeter(vector<vector<int>> &grid) {
        int islands = 0, neighbours = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    islands++; // count islands
                    if (i < grid.size() - 1 && grid[i + 1][j] == 1) neighbours++; // count down neighbours
                    if (j < grid[i].size() - 1 && grid[i][j + 1] == 1) neighbours++; // count right neighbours
                }
            }
        }

        return islands * 4 - neighbours * 2;
    }
};