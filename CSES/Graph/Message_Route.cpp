#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N], vis(N),par(N);

int bfs(int i, int n){
    queue<int> q;
    q.push(i);
    par[i] = -1;
    vis[i] = 1;

    int lv = 0;
    while(q.size()){
        int sz = q.size();
        lv++;
        while(sz--){
            int u = q.front();
            q.pop();
            for(auto &v : adj[u]){
                if(!vis[v]){
                    par[v] = u;
                    if(v==n) return lv + 1;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return -1;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i <m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dis = bfs(1,n);
    if(dis==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int i = n;
    stack<int> res;
    while(par[i] != -1){
        res.push(i);
        i = par[i];
    }
    res.push(i);
    cout<<dis<<endl;
    while(res.size()) cout<<res.top()<<" ", res.pop();
}