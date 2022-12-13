#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, size, parent;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++) parent[i]=i;
    }

    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = findPar(u) , pv = findPar(v);
        if(pu==pv) return;

        if(size[pu]<size[pv]){
             parent[pu] = pv;
             size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] +=size[pv];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> redEdge(2);
        int n = edges.size();
        DisjointSet ds(n);
        for(auto &ed : edges){
            int pu = ds.findPar(ed[0]);
            int pv = ds.findPar(ed[1]);
            if(pu==pv) redEdge = {ed[0],ed[1]};
            else ds.unionBySize(ed[0],ed[1]);
        }
        return redEdge;
    }
};