#include <bits/stdc++.h>
using namespace std;

/*
 Notes:
 1. Intuition - Greedy- push all the nodes and then get what is min wt edge simlple
 2. if you want comlete MST then have a mst array and a 3rd para of par in PQ.
 3. TC - O(ElogV + ElogV); 


 In the Prim's algorithm, we are building a tree starting from some initial point. We track all connected points in visited. For the current 
 point, we add its edges to the min heap. Then, we pick a smallest edge that connects to a point that is not visited. Repeat till all points are 
 visited.
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
            
            // ek hi node 2 baar pq me ho skti hai diff diff wt ke sath to baad me jo rep nodes aayegi unhe ignore krna hai
            if(vis[u]) continue;
            vis[u] = 1;
            
            sum += d;
            
            for(auto &p : adj[u]){
                int v = p[0];
                int wt = p[1];
                // jo final ho gyi hai unhe ignore
                if(vis[v]) continue;
                pq.push({wt,v});
            }
        }
        
        return sum;
    }
};