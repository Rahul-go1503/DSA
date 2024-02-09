#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N+1], indeg(N+1);
vector<int> res;
void topo(int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0) q.push(i);
    }

    while(q.size()){
        int u = q.front();
        q.pop();
        res.push_back(u);

        for(auto &v : adj[u]){
            if(--indeg[v]==0) q.push(v);
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    topo(n);
    if(res.size()==n){
        for(auto &x : res) cout<<x<<" ";
    }
    else cout<<"IMPOSSIBLE"<<endl;
}