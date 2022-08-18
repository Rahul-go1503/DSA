/*********************************************************************************************

Question :


Notes :
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
void topoSort(int node,vector<vector<int>> &adj,vector<bool> &vis,stack<int>&s){
    vis[node] = true;
    for(auto nbr : adj[node]){
        if(vis[nbr]) continue;
        topoSort(nbr,adj,vis,s);
    }
    s.push(node);
    return;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++) adj[edges[i][0]].push_back(edges[i][1]);
    stack<int> s;
    vector<bool>vis(v,false);
    for(int i=0;i<v;i++){
        if(vis[i]) continue;
        topoSort(i,adj,vis,s);   
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

/***********************************************************************************************
                              using vector instead stack
***********************************************************************************************/
void topoSort(int node,vector<vector<int>> &adj,vector<bool> &vis,vector<int>&ans){
    vis[node] = true;
    for(auto nbr : adj[node]){
        if(vis[nbr]) continue;
        topoSort(nbr,adj,vis,ans);
    }
    ans.push_back(node);
    return;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++) adj[edges[i][0]].push_back(edges[i][1]);
    vector<int> ans;
    vector<bool>vis(v,false);
    for(int i=0;i<v;i++){
        if(vis[i]) continue;
        topoSort(i,adj,vis,ans);   
    }
    reverse(ans.begin(),ans.end());
    return ans;
}