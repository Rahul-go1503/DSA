#include <bits/stdc++.h>
using namespace std;

// if cycle exist means not a safe node
class Solution {
    bool dfs(int v,vector<vector<int>> &adj,vector<int>&vis,vector<int>&dfsVis,vector<int> &safe){
        if(vis[v] && dfsVis[v]) return true;
        if(vis[v]) return false;

        vis[v]=1;
        dfsVis[v]=1;

        for(auto nbh : adj[v]){
            if(dfs(nbh,adj,vis,dfsVis,safe)) return true;
        }
        // just add this extra line in directedCycleDFS

        safe.push_back(v);
        dfsVis[v]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int>vis(V,0);
        vector<int>dfsVis(V,0);
        
        vector<int> safe;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj,vis,dfsVis,safe);
            // if(dfs(i,adj,vis)) safe.push_back(i);
        }
        // can opt
        sort(safe.begin(),safe.end());
        return safe;
    }
};

// if safe then return true else false
bool dfs(int v,vector<vector<int>> &adj,vector<int>&vis){
        if(vis[v]) return vis[v]==1;
        vis[v]=2;

        for(auto nbh : adj[v]){
            if(!dfs(nbh,adj,vis)) return false;
        }
        // just add this extra line in directedCycleDFS
        vis[v]=1;
        return true;
    }