#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N], vis(N),par(N), dist(N,INT_MAX);
class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int findPar(int u){
        if(parent[u] == u) return u;
        return parent[u] = findPar(parent[u]);
    }

    void Union(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;
        if(size[pu] <= size[pv]){
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        else{
            size[pu] += size[pv];
            parent[pv] = pu;
        }
    }
};

void dfs(int u, vector<int> &vis, vector<int>adj[]){
    vis[u] = 1;
    for(auto &v : adj[u]){
        if(!vis[v]) dfs(v,vis,adj);
    }
}


void bfs(int i){
    queue<int> q;
    q.push(i);
    par[i] = -1;
    vis[i] = 1;
    while(q.size()){
        int sz = q.size();
        while(sz--){
            int u = q.front();
            q.pop();
            for(auto &v : adj[u]){
                if(!vis[v]){
                    par[v] = u;
                    q.push(v);
                }
            }
        }
    }
}

void dijkstra(){
    dist[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});

    while(pq.size()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for(auto &p : adj[u]){
            // int v = p.first, wt = p.second;
            // if(d + wt<dist[v]){
            //     dist[v] = d + wt;
            //     pq.push({dist[v],v});
            // }
        }
    }
}