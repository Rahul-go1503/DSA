#include <bits/stdc++.h>
using namespace std;
// for BFS soln we have to reverse the edges and just perfrom the topoSort
// not a good approach O(nlogn)
vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<vector<int>> adjR(V);
        
	    vector<int> indeg(V);
        // reverse and count indeg
        for(int u=0;u<V;u++){
            // u->v
            for(auto &v : adj[u]){
                // v->u
                adjR[v].push_back(u);
                indeg[u]++;
            }
        }
        queue<int> q;

        for(int i=0; i<V; i++)
            if(indeg[i]==0) q.push(i);
	    
        vector<int> safe;
	    while(q.size())
        {
	        int u = q.front();
	        q.pop();
	        safe.push_back(u);
	        
	        for(auto &nbh : adjR[u])
	            if(--indeg[nbh]==0) q.push(nbh);
	    }
        sort(safe.begin(),safe.end());
        return safe;
    }