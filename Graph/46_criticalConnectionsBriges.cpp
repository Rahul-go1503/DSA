#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
    int t = 1;
    void dfs(int u, int par, vi &vis, vi &dis, vi &low, vi adj[], vvi &bridges){
        vis[u] = 1;
        dis[u] = low[u] = t++;
        for(auto &v : adj[u]){
            if(!vis[v]){
                dfs(v,u,vis,dis,low,adj,bridges);

                low[u] = min(low[u],low[v]);
                if(low[v] > dis[u]) bridges.push_back({u,v});
            }
            else if(v!=par) low[u] = min(low[u],low[v]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vi vis(n), dis(n), low(n);
        vector<int> adj[n];

        for(auto &ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        vvi bridges;
        dfs(0,-1,vis,dis,low,adj,bridges);
        return bridges;
    }
};



class Solution {
    // TC - O(V+2E)
    void dfs(int u,int par,int step, vector<int> &vis, vector<int> adj[], vector<int> &steps, vector<int> &low,vector<vector<int>> & briges){
        vis[u] = 1;
        low[u] = steps[u] = step++;
        for(auto &v : adj[u]){
            if(vis[v]){
                // update if v is vis and v is not par
                if(v!=par && low[u]>low[v])low[u] = low[v];
            }else{
                dfs(v,u,step,vis,adj,steps,low,briges);

                // update low of u
                if(low[u]>low[v]) low[u] = low[v];

                // is u--v is a brige ? 
                if(low[v]>steps[u]){
                    briges.push_back({u,v});
                }
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        // SC - O(N + 2E + 3N)
        vector<int> adj[n];
        for(auto &con : connections){
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        vector<vector<int>> briges;
        vector<int> vis(n) , steps(n) , low(n);
        dfs(0,-1,1,vis,adj,steps,low,briges);
        return briges;
    }
};