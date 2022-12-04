#include <bits/stdc++.h>
using namespace std;

// DOUBT - from which node we should start dfs
class Solution
{
    void dfs(int u, vector<int> adj[], vector<int> &vis, stack<int> &s)
    {
        if(vis[u]) return;
        vis[u]=1;
        
        for(auto &nbh : adj[u]){
            dfs(nbh,adj,vis,s);
        }
        s.push(u);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    stack<int> s;
	    
	    for(int i=0; i<V; i++){
	        if(vis[i]) continue;
	        dfs(i,adj,vis,s);
	    }
	    
	    vector<int> topo;
	    while(s.size()){
	        int u = s.top();
	        s.pop();
	        topo.push_back(u);
	    }
	    return topo;
	}
};