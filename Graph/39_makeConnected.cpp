#include <bits/stdc++.h>
using namespace std;

/*
Goal: We need to connect all the computers (directly or indirectly). We have to return the minimum number of operations that are
required to connect the computers. An operation consists of removing a cable between two directly connected computers and put it
between two disconnected computers.

Link - https://leetcode.com/problems/number-of-operations-to-make-network-connected/solutions/477660/java-count-number-of-connected-components-clean-code/?orderBy=most_votes
*/


class UnionFind{
    int count;
    vector<int> size, par;
public:
    UnionFind(int n){
        count = n;
        size.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++) par[i] = i;
    }

    int find(int u){
        if(u==par[u]) return u;
        return par[u] = find(par[u]);
    }
    void unionBySize(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;

        if(size[pu]<size[pv]){
            par[pu] = pv;
            size[pv] += size[pu];
        }else{
            par[pv] = pu;
            size[pu] += size[pv];
        }
        count--;
    }

    int countSet() {return count;}
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int c = connections.size();

        UnionFind ds(n);
        if(c<n-1) return -1;
        for(auto &com : connections){
            ds.unionBySize(com[0],com[1]);
        }
        return ds.countSet() - 1;
    }
};