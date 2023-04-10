#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int u, vector<int> &vis, vector<int> adj[], stack<int> &st){
        vis[u] = 1;

        for(auto &v : adj[u]){
            if(!vis[v]) dfs(v,vis,adj,st);
        }
        st.push(u); // storing vertex in decreasing order of their finishing time
    }
    
    void sccCount(int u, vector<int> &vis, vector<int> adj[]){
        vis[u] = 1;
        
        for(auto &v : adj[u]){
            if(!vis[v]) sccCount(v,vis,adj);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(vis[i]) continue;
            dfs(i,vis,adj,st);
        }
        
        vector<int> adjRev[V];
        for(int u=0;u<V;u++){
            vis[u] = 0;
            for(auto &v : adj[u]){
                adjRev[v].push_back(u);
            }
        }
        
        int scc = 0;
        while(st.size()){
            int u = st.top(); st.pop();
            if(vis[u]) continue;
            sccCount(u,vis,adjRev);
            scc++;
        }
        return scc;
    }
};