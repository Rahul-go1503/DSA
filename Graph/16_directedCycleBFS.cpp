#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 

    // kahn's algo
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> indeg(V,0);
	    
	    for(int i=0; i<V; i++)
	        for(auto &u : adj[i]) indeg[u]++;
	    
	    for(int i=0; i<V; i++)
            if(indeg[i]==0) q.push(i);
	    
	    int cnt = 0;
	    while(q.size())
        {
	        int u = q.front();
	        q.pop();
	        cnt++;
	        

            // agar kisi bhi nbh ki indeg zero nhi hai to que ke last elem ke liye to means vo kisi ese par
            // depended hai jiski khud ki indeg kbhi zero nhi hogi
	        for(auto &nbh : adj[u])
	            if(--indeg[nbh]==0) q.push(nbh);
	    }
	    return cnt!=V;
	}
};