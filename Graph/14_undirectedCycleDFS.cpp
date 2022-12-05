#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int v, int p, vector<int> adj[], vector<int> &vis){
        // phele se hi vis hai means cycle bn gya 
        if(vis[v]) return true;
        vis[v]=1;
        
        for(auto &nbh : adj[v]){
            // par hai to jana hi nhi hai
            if(nbh!=p && dfs(nbh,v,adj,vis)) return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i]==0 && dfs(i,-1,adj,vis)) return true;
        }
        return false;
    }
};