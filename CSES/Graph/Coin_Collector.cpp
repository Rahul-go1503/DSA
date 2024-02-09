#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> adjRev[N];
vector<int> vis(N), order, coins(N);
vector<ll> coinsDAG, dp(N,-1);

void dfs(int u){
    vis[u] = 1;
    for(auto &v : adj[u]){
        if(!vis[v]) dfs(v);
    }
    order.push_back(u);
}

void dfs2(int u, int p, ll &sum, vector<int> &parDAG){
    vis[u] = 1;
    sum += coins[u];
    parDAG[u] = p;
    for(auto &v: adjRev[u]){
        if(!vis[v]) dfs2(v,p,sum,parDAG);
    }
}

ll solve(int u, vector<int> adjDAG[]){
    if(dp[u] != -1) return dp[u];
    ll res = 0;
    for(auto &v : adjDAG[u]){
        res = max(res, solve(v,adjDAG));
    }
    return dp[u] = res + coinsDAG[u];
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>coins[i];
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
    vector<int> parDAG(n+1);
    vis.assign(n+1,0);
    for(auto &u : order){
        if(!vis[u]){
            ll sum = 0;
            dfs2(u, cnt, sum, parDAG);
            coinsDAG.push_back(sum);
            cnt++;
        }
    }
    vector<int> adjDAG[cnt];
    for(int i=1;i<=n;i++){
        for(auto &v : adj[i]){
            if(parDAG[i] != parDAG[v]){
                adjDAG[parDAG[i]].push_back(parDAG[v]);
            }
        }
    }
    ll res = 0;
    for(int i=0;i<cnt;i++){
        res = max(res, solve(i,adjDAG));
    }   
    cout<<res<<endl;
}