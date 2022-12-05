#include <bits/stdc++.h>
using namespace std;
// GIVEN - graph is DAG
class Solution {
    void topoSort(int src , vector<pair<int,int>>adj[], stack<int> &s,vector<int> &vis){
        if(vis[src]) return;
        vis[src]=1;
        for(auto &nbh : adj[src]){
            topoSort(nbh.first,adj,s,vis);
        }
        s.push(src);
    }
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[n];
        for(auto &ed: edges){
            adj[ed[0]].push_back({ed[1],ed[2]});
        }
        stack<int> s;
        vector<int> vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]) topoSort(i,adj,s,vis);
        }
        
        vector<int> dis(n,INT_MAX);
        dis[0]=0;
        while(s.top()!=0) s.pop();
        while(s.size()){
            int u = s.top();
            s.pop();
            for(auto &nbh : adj[u]){
                dis[nbh.first] = min(dis[nbh.first],nbh.second+dis[u]);
            }
        }
        for(int i=1;i<n;i++) if(dis[i]==INT_MAX) dis[i]=-1;
        return dis;
    }
};