#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct rotFr{
        int i;
        int j;
        int t;
        
        rotFr(int x, int y , int z){
            i = x;
            j = y;
            t = z;
        }
    };
    
    bool checkAdj(int i,int j,int n ,int m,vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1) return false;
        grid[i][j] = 0;
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<rotFr> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push(rotFr(i,j,0));
                    grid[i][j] = 0;
                }
            }
        }
        
        int mx = 0;
        while(q.size()){
            rotFr org = q.front();
            
            int i = org.i;
            int j = org.j;
            int t = org.t;
            
            q.pop();
            int s = q.size();
            
            // grid[i][j]=0;
            
            if(checkAdj(i+1,j,n,m,grid)) q.push(rotFr(i+1,j,t+1));
            if(checkAdj(i,j+1,n,m,grid)) q.push(rotFr(i,j+1,t+1));
            if(checkAdj(i-1,j,n,m,grid)) q.push(rotFr(i-1,j,t+1));
            if(checkAdj(i,j-1,n,m,grid)) q.push(rotFr(i,j-1,t+1));
            
            if(q.size()>s) mx = max(mx,t+1);
        }
        

        // we can optimize this
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]) return -1;
            }
        }
        return mx;
    }
};


/************----------------HAVE A LOOK ----------------***********/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        
        vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0; //To keep track of all fresh oranges left
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        int ans=-1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                    if(r>=0 && r<m && c>=0 && c<n &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                    
                }
            }
            ans++; //incremented after each minute passes
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
        
    }
};