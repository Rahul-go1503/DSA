#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const ll INF = LLONG_MAX;
vector<vector<ll>> dist(N,vector<ll>(10,INF));
vector<pair<ll,ll>> adj[N+1];

void dijkstra(int k, int n){
    dist[1][0] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});

    while(pq.size()){
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if(dist[u][k-1] < d) continue;
        for(auto &p : adj[u]){
            ll v = p.first, wt = p.second;
            if(d + wt < dist[v][k-1]){
                dist[v][k-1] = d + wt;
                pq.push({dist[v][k-1],v});
                sort(dist[v].begin(),dist[v].end());
            }
        }
    }
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(ll i = 0;i <m;i++){
        ll u,v,l;
        cin>>u>>v>>l;
        adj[u].push_back({v,l});
    }
    dijkstra(k,n);
    for(int i=0;i<k;i++){
        cout<<dist[n][i]<<" ";
    }
}