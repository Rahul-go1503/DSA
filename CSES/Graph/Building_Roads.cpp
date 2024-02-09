#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N], vis(N);

void dfs(int u){
    vis[u] = 1;
    for(auto &v : adj[u]){
        if(!vis[v]) dfs(v);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i <m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>res;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            res.push_back(i);
            dfs(i);
        }
    }
    cout<<res.size() - 1<<endl;
    for(int i=1;i<(int)res.size();i++) cout<<res[i-1]<<" "<<res[i]<<endl;
}