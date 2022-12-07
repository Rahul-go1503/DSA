#include <bits/stdc++.h>
using namespace std;
/*
 Notes:
 1. Shortest path array nikalna hai to return nhi krenge 
 2. If we have to find shortest path value for only one dest node then return as soon as we find that node
 3. if(d>dis[u]) continue; this additional line can save alot iterations
 4. If we have to find path also - use additional par array
 5. If we have to calculate no of shortest path - use ways array
 6. we can also solve by queue only but pq have advantage over q;
 7. total dis covered any time is always increasing, agar koi node tak phunchne ki distace jyada hai
    to vo baad me hi process hoga
 8. work for both UG and DG but not work for neg weights
 
*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // distane, vertex
        pq.push({0,src});
        
        vector<int> dis(v,INT_MAX);
        dis[src] = 0;
        while(pq.size()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            for(auto &p : adj[u]){
                int v = p[0];
                int wt = p[1];
                // yha parent vertex se sbhi childs par jane ka try krenge lekin
                // push only if we found shorter path for that child;
                // here we dont have vis array
                if(d+wt<dis[v]){
                    dis[v] = d+wt;
                    pq.push({dis[v],v});
                }
            }
        }
        
        return dis;
    }
};