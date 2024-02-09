#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2 * 1e5 + 5;
vector<int> vis(N), dp(N,-1), next_node(N,-1);
vector<int> adj[N];

// dp[i] = max distance of node i from node n
// it works because of DAG
void dfs(int u){
    vis[u] = 1;
    for(auto &v: adj[u]){
        if(!vis[v]) dfs(v);
        if(dp[v]!=-1 && dp[v]+1>dp[u]){
            dp[u] = dp[v] + 1;
            next_node[u] = v;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i <m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    dp[n] = 1;
    dfs(1);
    if(vis[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        int i = 1;
        cout<<dp[1]<<endl;
        while(i != -1){
            cout<<i<<" ";
            i = next_node[i];
        }
    }
}