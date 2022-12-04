#include <bits/stdc++.h>
using namespace std;

//shortest paths-unweighted graph---->bfs(very standard)
//but usually 1 source node---minimum distance from that particular node
//but here multiple source nodes
//so push all of them first
//WHY???
//WHEN WE POP AND EXPLORE WE ARE DOING SO IN INCREASING ORDER OF THEIR LEVELS
//SO WHEN WE DISCOVER A NODE FIRST WE ARE EXPLORING IT FROM MINI POSSIBLE LEVEL NODE THAT IT IS CONNECTED TO
//first the source..then level 1 nodes..then level 2 and so on
//here the case is there are many level 0 nodes
//so push all of them first!!!

class Solution
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> ans(n,vector<int>(m));
	    vector<int> dir = {-1,0,1,0,-1};
	    
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]){
	                q.push({i,j});
	                ans[i][j] = 0;
	            }
	        }
	    }
	    while(q.size()){
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            
            for(int d=0;d<4;d++){
                int i = r + dir[d];
                int j = c + dir[d+1];
                
                if(i<0 || i>=n || j<0 ||j>=m || grid[i][j]==1) continue;
                grid[i][j] = 1;
                ans[i][j] = ans[r][c] + 1;
                q.push({i,j});
            }
	    }
	    return ans;
	}
};