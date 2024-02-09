#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dijkstra(vector<pair<ll,ll>> adj[], vector<ll> &dist){
    dist[1] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});

    while(pq.size()){
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if(dist[u]<d) continue;
        for(auto &p : adj[u]){
            ll v = p.first, wt = p.second;
            if(d + wt<dist[v]){
                dist[v] = d + wt;
                pq.push({dist[v],v});
            }
        }
    }
}
int main(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> adj[n+1];
    for(ll i = 0;i <m;i++){
        ll u,v,l;
        cin>>u>>v>>l;
        adj[u].push_back({v,l});
    }
    vector<ll>dist(n+1,LLONG_MAX);
    dijkstra(adj,dist);
    for(ll i=1;i<=n;i++) cout<<dist[i]<<" ";
}