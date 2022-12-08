#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    int cnt;
    vector<int> size, par;
public:
    DisjointSet(int n){
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

    int sizeofSet(int u){return size[find(u)];}

    int count() {return cnt;}
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        int dir[] = {1,0,-1,0,1};
        int mx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;

                for(int d=0;d<2;d++){
                    int x = i + dir[d];
                    int y = j + dir[d+1];
                    if(x<0 || y<0 || x>=n || y>=n || grid[x][y]==0) continue;
                    int id1 = i*n + j;
                    int id2 = x*n + y;
                    ds.unionSet(id1,id2);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) continue;

                int sz = 0;
                unordered_set<int> s;
                for(int d=0;d<4;d++){
                    int x = i + dir[d];
                    int y = j + dir[d+1];
                    if(x<0 || y<0 || x>=n || y>=n || grid[x][y]==0) continue;
                    int id = x*n + y;
                    s.insert(ds.find(id));
                }
                for(auto &id : s) sz += ds.sizeofSet(id);
                mx = max(mx,sz+1);
            }
        }
        return mx==0 ? n*n : mx;
    }
};