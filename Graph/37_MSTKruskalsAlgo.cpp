#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

class DisjointSet{
    vector<int> size, parent;
public:
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = findUPar(u) , pv = findUPar(v);
        if(pu==pv) return;

        if(size[pu]<size[pv]) parent[pu] = pv, size[pv] += size[pu];
        else parent[pv] = pu, size[pu] += size[pv];
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.

    // edges ko sort krke union kro agar u and v me union hua to wt add kro
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vi> edges;
        for(int i=0;i<V;i++){
            for(auto &p : adj[i]){
                edges.push_back({p[1],p[0],i});
            }
        }
        
        int mstWt = 0;
        int E = edges.size();
        
        sort(edges.begin(),edges.end());
        
        DisjointSet ds(V);
        for(int i=0;i<E;i++){
            int u = edges[i][1];
            int v = edges[i][2];
            int wt = edges[i][0];
            
            // although unionBySize fun similar par ke liye check krta hai lekin ye nhi btata ki vo sim the isliye return kra
            // can modify 
            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionBySize(u,v);
                mstWt += wt;
            }
        }
        return mstWt;
    }
};