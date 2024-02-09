#include<bits/stdc++.h>
using namespace std;
const int N = 21;
const int mod = 1e9 + 7;
vector<int> adj[N];
int dp[N][1<<21];

int dfs(int u, int n, int mask){
    if(dp[u][mask] != -1) return dp[u][mask];
    mask ^= (1<<u);
    if(u==n && mask==0) return 1;
    if(u==n) return 0;
    int ans = 0;
    for(auto &v :adj[u]){
        if(mask & (1<<v)){
            int res = dfs(v,n,mask);
            ans = (ans + 0LL + res)%mod;
        }
    }
    mask ^= (1<<u);
    return dp[u][mask] = ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int mask = 0;
    for(int i=1;i<=n;i++){
        mask |= (1<<i);
    }
    memset(dp,-1,sizeof(dp));
    cout<<dfs(1,n,mask);
}