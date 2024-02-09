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

void dfs2(int u){
    vis[u] = 1;
    for(auto &v: adjRev[u]){
        if(!vis[v]) dfs2(v);
    }
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
    vector<int> roots;
    vis.assign(n+1,0);
    for(auto &u : order){
        if(!vis[u]){
            dfs2(u);
            cnt++;
            roots.push_back(u);
        }
    }

    if(cnt==1) cout<<"YES"<<endl;
    else{
        cout<<"NO"<<endl;
        cout<<roots[1]<<" "<<roots[0]<<endl;
    }
}