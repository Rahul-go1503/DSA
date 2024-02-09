#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 5;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
vector<pair<ll,ll>> adj[N];

vector<ll> dist(N, INF), mn(N,INT_MAX), mx(N,INT_MIN), ways(N,0);
void dijksta(){
    dist[1] = 0, mn[1] = 0, mx[1] = 0, ways[1] = 1;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});

    while(pq.size()){
        auto p = pq.top();
        ll u = p.second;
        ll d = p.first;
        pq.pop();
        if(dist[u] < d) continue;
        for(auto &p : adj[u]){
            ll v = p.first, wt = p.second;
            if(d + wt < dist[v]){
                dist[v] = d + wt;
                mn[v] = 1 + mn[u], mx[v] = 1 + mx[u];
                ways[v] = ways[u];
                pq.push({dist[v],v});
            }
            else if(d+wt == dist[v]){
                mn[v] = min(mn[v],1 + mn[u]);
                mx[v] = max(mx[v],1 + mx[u]);
                ways[v] += ways[u];
                ways[v] %= mod;
            }
        }
    }
}
int main(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    dijksta();
    cout<<dist[n]<<" "<<ways[n]<<" "<<mn[n]<<" "<<mx[n]<<endl;
}