#include <bits/stdc++.h>
using namespace std;

/*
 Notes:
 1. Intuition - Greedy- push all the nodes and then get what is min wt edge simlple
 2. if you want comlete MST then have a mst array and a 3rd para of par in PQ.
 3. TC - O(ElogV + ElogV); 
*/

#define vi vector<int>
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // SC - O(V + E)
        vector<int> vis(V);
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        pq.push({0,0});
        
        int sum =0;
        // loop for max E times
        while(pq.size()){
            int d = pq.top()[0];
            int u = pq.top()[1];
            pq.pop();
            
            if(vis[u]) continue;
            vis[u] = 1;
            
            sum += d;
            
            for(auto &p : adj[u]){
                int v = p[0];
                int wt = p[1];
                if(vis[v]) continue;
                pq.push({wt,v});
            }
        }
        
        return sum;
    }
};