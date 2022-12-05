#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        // distane, vertex
        q.push({0,s});
        
        vector<int> dis(v,INT_MAX);
        dis[s] = 0;
        while(q.size()){
            int d = q.top().first;
            int u = q.top().second;
            q.pop();
            
            for(auto &nbh : adj[u]){
                // push only if we found shorter path for that node;
                // here we dont have vis array
                if(d+nbh[1]<dis[nbh[0]]){
                    dis[nbh[0]] = d+nbh[1];
                    q.push({dis[nbh[0]],nbh[0]});
                }
            }
        }
        
        return dis;
    }
};