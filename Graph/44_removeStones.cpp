#include <bits/stdc++.h>
using namespace std;

// Very good question 
class DisjointSet{
    int cnt = 0;
    vector<int> rank, size, parent;
public:
    DisjointSet(int n){
        rank.resize(n,0);
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int pu = findPar(u) , pv = findPar(v);
        if(pu==pv) return;

        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pu] > rank[pv]) parent[pv] = pu;
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(); // no of stones

        // we dont know what will be dimension of plane
        int mxR = 0;
        int mxC = 0;
        for(auto &loc : stones){
            mxR = max(mxR,loc[0]);
            mxC = max(mxC,loc[1]);
        }

        // we dont know which nodes will be actually ocuiped
        DisjointSet ds(mxR + mxC + 2);

        unordered_map<int,int> dsNodes;
        for(auto &loc : stones){
            int x = loc[0], y = mxR + 1 + loc[1];
            dsNodes[x] = y;
            ds.unionBySize(x,y);
        }

        int cnt = 0;
        for(auto &p : dsNodes){
            if(ds.findPar(p.first)==p.first) cnt++;
            if(ds.findPar(p.second)==p.second) cnt++;
        }
        return n - cnt;
    }
};