#include <bits/stdc++.h>
using namespace std;
void DFS (int node,vector<set<int>> &adj,vector<bool> &vis,vector<int> & ans){
    
    ans.push_back(node);
    vis[node]=true;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            DFS(nbr,adj,vis,ans);
        }
    }
    return;
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // vector of sets
    vector<set<int>> adj(V);
    for(int i=0;i<E;i++){
        int u = edges[i][0];
        int v= edges[i][1];
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<bool> vis (V,false);
    vector<vector<int>> res;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int> dfsForSingleComponent;
            DFS(i,adj,vis,dfsForSingleComponent);
            res.push_back(dfsForSingleComponent);
        }
    }
    return res;
}