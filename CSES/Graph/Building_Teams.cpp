#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> adj[N], vis(N), ans(N), par(N);

bool bfs(int st){
    queue<int> q;
    q.push(st);
    par[st] = -1;
    ans[st] = 1;
    bool gr = 1;
    while(q.size()){
        int sz = q.size();
        while(sz--){
            int u = q.front();
            q.pop();
            for(auto &v : adj[u]){
                if(v != par[u]){
                    if(ans[v] == ans[u]){
                        return false;
                    }
                    else if(ans[v]==0){
                        ans[v] = gr + 1;
                        par[v] = u;
                        q.push(v);
                    }
                }
            }
        }
        gr = !gr;
    }
    return true;
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
    
    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            if(bfs(i)==false){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<n+1;i++) cout<<ans[i]<<" ";
}