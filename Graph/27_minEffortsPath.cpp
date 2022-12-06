#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        if(n==1 && m==1) return 0;
        // can be solved by queue but pq se phele hi return ho jaega and TC - ELOGV < V2
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;

        vector<vector<int>> efforts(n,vector<int>(m,INT_MAX));
        efforts[0][0] = 0;
        
        q.push({0,0,0});

        while(q.size()){
            int i = q.top()[1];
            int j = q.top()[2];
            q.pop();
            if(i==n-1 && j==m-1) return efforts[i][j];
            vector<int> dir = {0,1,0,-1,0};
            for(int d=0;d<4;d++){
                int r = i + dir[d];
                int c = j + dir[d+1];

                if(r<0 || r>=n || c<0 || c>=m) continue;
                int eff = abs(heights[r][c] - heights[i][j]);

                if(max(eff,efforts[i][j]) < efforts[r][c] ){
                    efforts[r][c] = max(eff,efforts[i][j]);
                    q.push({efforts[r][c],r,c});
                }
            }
        }

        return efforts[n-1][m-1]; // Not reachable code
    }
};