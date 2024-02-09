#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<set<int>> adj(n+1);
    vector<int> deg(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]&1){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    vector<int> path;
    stack<int> st;
    st.push(1);
    while(st.size()){
        int u = st.top();
        if(deg[u]==0){
            path.push_back(u);
            st.pop();
        }
        else{
            int v = *(adj[u].begin());
            adj[u].erase(v);
            adj[v].erase(u);
            st.push(v);
            deg[u]--;
            deg[v]--;
        }
    }
    if((int)path.size() != m+1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(auto &x : path) cout<<x<<" ";
    }

}