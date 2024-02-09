#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> indeg(n+1), outdeg(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        outdeg[u]++,indeg[v]++;
    }
    for(int i=2;i<n;i++){
        if(indeg[i] != outdeg[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    if(outdeg[1]-indeg[1] != 1 && indeg[n] - outdeg[n] != 1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> path;
    stack<int> st;
    st.push(1);
    while(st.size()){
        int u = st.top();
        if(outdeg[u]==0 && indeg[u]==0){
            path.push_back(u);
            st.pop();
        }
        else{
            int v = adj[u].back();
            adj[u].pop_back();
            st.push(v);
            outdeg[u]--, indeg[v]--;
        }
    }
    if((int)path.size() != m+1){
        cout <<"IMPOSSIBLE"<<endl;
    }
    else{
        reverse(path.begin(),path.end());
        for(int i=0;i<m+1;i++){
            cout<<path[i]<<" ";
        }
    }

}