#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> adjRev[N];
vector<int> vis(N);
vector<int> order;
void dfs(int u){
    vis[u] = 1;
    for(auto &v : adj[u]){
        if(!vis[v]) dfs(v);
    }
    order.push_back(u);
}

void dfs2(int u,vector<int> &component){
    vis[u] = 1;
    for(auto &v: adjRev[u]){
        if(!vis[v]) dfs2(v,component);
    }
    component.push_back(u);
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adjRev[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    reverse(order.begin(), order.end());
    int cnt = 0;
    vector<int> res(n+1);
    vis.assign(n+1,0);
    for(auto &u : order){
        if(!vis[u]){
            vector<int> component;
            dfs2(u,component);
            cnt++;
            for(auto &x : component) res[x] = cnt;
        }
    }

    cout<<cnt<<endl;
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}