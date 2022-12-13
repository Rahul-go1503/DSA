#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    int node,cnt,cntUn;
    vector<int> rank, size, parent;
public:
    DisjointSet(int n){
        cnt = node = n;
        cntUn = 0;
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++) parent[i]=i;
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
        cnt--;
        cntUn++;
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

    int countSet() {return cnt;}
    int countUnion() {return cntUn;}
    int sizeofSet(int u) {return size[findPar(u)];}
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        for(auto &eq : equations){
            int u = eq[0]-'a' , v = eq[3]-'a';
            int pu = ds.findPar(u);
            int pv = ds.findPar(v);
            if(pu==pv && eq[1]=='!') return false;
            if(eq[1]=='=') ds.unionBySize(u,v);
        }
        for(auto &eq : equations){
            if(eq[1]=='=') continue;
            int u = eq[0]-'a' , v = eq[3]-'a';
            int pu = ds.findPar(u);
            int pv = ds.findPar(v);
            if(pu==pv) return false;
        }
        return true;
    }
};