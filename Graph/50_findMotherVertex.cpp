#include <bits/stdc++.h>
using namespace std;
/*
Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
*/
class Solution 
{
    int dfs(int u, vector<int> &vis, vector<int> adj[], vector<int> &dp){
        if(vis[u]) return dp[u];
        vis[u] = 1;
        int cnt = 0;
        for(auto &v: adj[u]){
            if(vis[v]) continue;
            cnt += dfs(v,vis,adj,dp);
        }
        return dp[u] = cnt+1;
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> vis(V);
	    vector<int> dp(V,-1);
	    for(int i=0;i<V;i++){
	        if(!vis[i] && dfs(i,vis,adj,dp)==V) return i;
	    }
	    return -1;
	}

};