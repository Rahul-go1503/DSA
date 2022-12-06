#include <bits/stdc++.h>
using namespace std;

// total dis covered any time is always increasing, agar koi node tak phunchne ki distace jyada hai to vo baad me hi process hoga

// we can also solve by queue only but pq have advantage over q;
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