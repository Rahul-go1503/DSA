#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
vector<pair<int,int>> adj[N];
vector<int> inMST(N);
ll MST(int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    ll cost = 0, cnt = 0;
    while(pq.size()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(inMST[u]) continue;
        inMST[u] = 1;
        cnt++;
        cost += d;
        for(auto &p : adj[u]){
            int v = p.first, wt = p.second;
            if(inMST[v]) continue;
            pq.push({wt,v});
        }
    }
    return cnt==n ? cost : -1;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    ll res = MST(n);
    if(res==-1) cout<<"IMPOSSIBLE"<<endl;
    else cout<<res<<endl;
}