#include <bits/stdc++.h>
using namespace std;

/*
TopoSort excludes not only those nodes that are in a cycle, but also those nodes that have an outgoing edge to the cycle, and this node must be 
removed as well because it leads to a non-terminal node (ie. a cycle).
*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 

    // kahn's algo
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> indeg(V,0);
	    
	    for(int i=0; i<V; i++)
	        for(auto &u : adj[i]) indeg[u]++;
	    
	    for(int i=0; i<V; i++)
            if(indeg[i]==0) q.push(i);
	    
	    vector<int> topo;
	    while(q.size())
        {
	        int u = q.front();
	        q.pop();
	        topo.push_back(u);
	        
	        for(auto &nbh : adj[u])
	            if(--indeg[nbh]==0) q.push(nbh);
	    }
	    return topo;
	}
};