#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    int count,V;
    vector<int> size, parent;
public:
    DisjointSet(int n){
        count = V = n;
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++) parent[i]=i;
    }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = findUPar(u) , pv = findUPar(v);
        if(pu==pv) return;

        if(size[pu]<size[pv]) parent[pu] = pv;
        else parent[pv] = pu;

        count--;
    }

    int countSet(){
        // int cnt = 0;
        // for(int i=0;i<V;i++){
        //     cout<<i<<endl;
        //     if(parent[i]==i) cnt++;
        // }
        // return cnt;
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();

        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0; j<n;j++){
                if(mat[i][j]){
                    ds.unionBySize(i,j);
                }
            }
        }
        return ds.countSet();
    }
};