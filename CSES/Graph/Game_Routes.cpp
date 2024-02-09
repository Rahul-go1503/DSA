#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
vector<int> vis(N), dp(N);
vector<int> adj[N];

// dp[i] = no of ways from node i to node n
// it works because of DAG
void dfs(int u){
    vis[u] = 1;
    for(auto &v: adj[u]){
        if(!vis[v]) dfs(v);
        dp[u] = (dp[u] + 0LL + dp[v])%mod;
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
    cout<<dp[1]<<endl;
}