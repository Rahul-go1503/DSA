#include <bits/stdc++.h>
using namespace std;
vector<int> Solve(int node,vector<int> &bfs,vector<bool> &visited,set<int> adj[])
{
    queue<int> q;
    q.push(node);
    visited[node]= true;
    while(!q.empty()){
        int ver = q.front();
        bfs.push_back(ver);
        q.pop();
        for(auto nbr : adj[ver]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]= true;
            }
        }
    }
    return bfs;
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    set<int> adj[vertex];  // arrray of sets sorted order me values insert hogi 1--> 3,4,5
    for(auto edge : edges){
        adj[edge.first].insert(edge.second);
        adj[edge.second].insert(edge.first);
    }
    vector<int> bfs;
    vector<bool> visited(vertex,false);
    for(int i=0;i<vertex;i++){
        if(!visited[i])
            Solve(i,bfs,visited,adj);
    }
    return bfs;
}