#include <bits/stdc++.h>
using namespace std;

#define pi pair<int,int>
// direct mst question 
int getMinimumCost(int n, int m, vector<vector<int>> &con)
{
	vector<pi> adj[n+1];
    int vis[n+1] = {};
    for(auto &itr : con){
        adj[itr[0]].push_back({itr[1],itr[2]});
        adj[itr[1]].push_back({itr[0],itr[2]});
    }
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({0,1});
    
    int cost = 0;
    while(pq.size()){
        int u = pq.top().second;
        int c = pq.top().first;
        pq.pop();
        
        if(vis[u]) continue;
        vis[u] = 1;
        cost += c;
        
        for(auto &p : adj[u]){
            int v = p.first;
            int wt = p.second;
            if(vis[v]) continue;
            pq.push({wt,v});
        }
    }
    for(int i=1;i<=n;i++) if(vis[i]==0) return -1;
    return cost;
}