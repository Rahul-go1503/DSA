#include <bits/stdc++.h>
using namespace std;

class UnionFind{
    int cnt;
    vector<int> size, par;
public:
    UnionFind(int n){
        cnt = 0;
        size.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++) par[i] = i;
    }
    
    int find(int u){
        if(u==par[u]) return u;
        return par[u] = find(par[u]);
    }

    void unionSet(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        if(size[pu]<size[pv]){
            par[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            par[pv] = pu;
            size[pu] +=size[pv];
        }
        cnt++;
    }

    int count() {return cnt;}
};

class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // can solve by 4 dir only
        int dir[] = {1,0,-1,0,1,1,-1,-1,1};
        
        UnionFind ds(n*m);
        
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0') continue;
                count++;
                
                for(int d=0;d<8;d++){
                    int x = i + dir[d];
                    int y = j + dir[d+1];
                    
                    if(x<0 || y<0 || x>=n || y>=m || grid[x][y]=='0') continue;
                    int id1 = i*m + j;
                    int id2 = x*m + y;
                    ds.unionSet(id1,id2);
                }
            }
        }
        return count - ds.count();
    }
};