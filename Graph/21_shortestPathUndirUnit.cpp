#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        vector<int> adj[n];
        for(auto &ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        
        queue<int> q;
        vector<int> vis(n); // no need of vis can use dis array itself
        q.push(src);
        
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        while(q.size()){
            int u = q.front();
            q.pop();
            vis[u]=1;
            
            for(auto &nbh: adj[u]){
                if(vis[nbh]) continue;
                dis[nbh] = min(dis[nbh],1+dis[u]);
                q.push(nbh);
            }
        }
        
        for(int i=0;i<n;i++) if(dis[i]==INT_MAX) dis[i]=-1;
        return dis;
    }
};