#include <bits/stdc++.h>
using namespace std;

/*
 NOTES : 
 1. TC - O(v * E);
 2. SC - O(V);
 3. Can Detect neg cycles
*/

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n,INT_MAX);
	    dist[0] = 0;
	    
    // Step 1: Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other vertex can have
    // at-most |V| - 1 edges
	    for(int i=0;i<n-1;i++){
	        for(auto &it:edges){
	            int u = it[0];
	            int v = it[1];
	            int wt = it[2];
	            
	            if(dist[u]!=INT_MAX && dist[u]+wt < dist[v]){
	                dist[v] = dist[u] + wt;
	            }
	        }
	    }
	    
     // Step 2: check for negative-weight cycles.  The above
    // step guarantees shortest distances if graph doesn't
    // contain negative weight cycle.  If we get a shorter
    // path, then there is a cycle.
	    for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u]!=INT_MAX && dist[u]+wt < dist[v]){
                return 1;
            }
	    }
	    
	    return 0;
	}
};