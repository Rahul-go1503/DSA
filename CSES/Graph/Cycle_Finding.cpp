#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges[i] = {u,v,wt};
    }
    vector<ll> dist(n+1),par(n+1,-1);
    int x = -1;
    for(int i=0;i<n;i++){
        x = -1;
        for(auto &ed: edges){
            int u = ed[0], v = ed[1], wt = ed[2];

            if(dist[v]> dist[u] + wt){
                dist[v] = dist[u] + wt; // relax
                x = v;
                par[v] = u;
            }
        }
    }
    if(x==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        x = par[x];
    }
    vector<int> res;
    int v = x;
    while(res.empty() || v !=x){
        res.push_back(v);
        v = par[v];
    }
    res.push_back(v);
    reverse(res.begin(),res.end());
    cout<<"YES"<<endl;
    for(auto &x : res) cout<<x<<" ";
}