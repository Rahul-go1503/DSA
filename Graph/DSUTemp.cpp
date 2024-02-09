#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    int n, set;
    vector<int> par, size;
    public:

    DisjointSet(int n){
        this->n = n;
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) par[i] = i;
    }

    int find(int u){
        if(par[u] == u) return u;
        return par[u] = find(par[u]); // path compression
    }

    void unionBySize(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu != pv){
            if(size[pu] < size[pv]) par[pu] = pv, size[pv] += size[pu];
            else par[pv] = pu, size[pu] += size[pv];
        }
    }

};