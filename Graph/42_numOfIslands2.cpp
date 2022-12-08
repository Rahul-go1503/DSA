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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &opr) {
        int k = opr.size();
        
        vector<vector<int>> vis(n,vector<int>(m));
        vector<int> ans(k);
        
        UnionFind uf(n*m);
        // cant solve by 2 dir 
        int dir[] = {0,1,0,-1,0};
        int count = 0;
        for(int q=0;q<k;q++){
            int i = opr[q][0];
            int j = opr[q][1];
            if(vis[i][j]){
                ans[q] = count - uf.count();
                continue;
            }
            vis[i][j] = 1;
            count++;
            
            for(int d=0;d<4;d++){
                int x = i + dir[d];
                int y = j + dir[d+1];
                
                if(x<0 || y<0 || x>=n || y>=m || vis[x][y]==0) continue;
                int id1 = i*m + j;
                int id2 = x*m + y;
                uf.unionSet(id1,id2);
            }
            
            ans[q] = count - uf.count();
        }
        return ans;
    }
};