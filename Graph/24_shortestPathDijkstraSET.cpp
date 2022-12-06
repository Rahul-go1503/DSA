#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        set<pair<int,int>> s;
        // distane, vertex
        vector<int> dis(v,INT_MAX);
        dis[src] = 0;
        s.insert({0,src});
        
        while(s.size()){
            // set bhi min dis ke corespoding pair provide krega
            auto itr = *(s.begin());
            int d = itr.first;
            int u = itr.second;
            s.erase(itr);
            
            for(auto &p : adj[u]){
                int v = p[0];
                int wt = p[1];
                // yha par vertex se abhi nbh par jane ka try krenge lekin
                // push only if we found shorter path for that node;
                // here we dont have vis array
                if(d+wt<dis[v]){
                    // set use krne ka fayda - if we found some v whose value is already set it means we no longer need
                    // that pair in our set so we can erase by using set
                    if(dis[v]!=INT_MAX) s.erase({dis[v],v});
                    dis[v] = d+wt;
                    s.insert({dis[v],v});
                }
            }
        }
        
        return dis;
    }
};