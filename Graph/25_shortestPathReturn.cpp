#include <bits/stdc++.h>
using namespace std;

// to track path we need a extra vector of parent
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        
        for(auto &ed : edges){
            adj[ed[0]].push_back({ed[1],ed[2]});
            adj[ed[1]].push_back({ed[0],ed[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // distane, vertex
        pq.push({0,1});
        
        vector<int> dis(n+1,INT_MAX);
        vector<int> par(n+1,-1);
        dis[1]=0;
        while(pq.size()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            for(auto &p : adj[u]){
                int v = p.first;
                int wt = p.second;
                
                if(d+wt<dis[v]){
                    dis[v] = d+wt;
                    pq.push({dis[v],v});
                    par[v] = u;
                }
            }
        }
        if(dis[n]==INT_MAX) return {-1};
        
        vector<int> path;
        int i = n;
        while(par[i]!=-1){
            path.push_back(i);
            i = par[i];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};