/*********************************************************************************************

Question :


Notes :
Adjecncy List of weighted graph
array of vectors
vector<pair<int,int> adjList []
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool dfs(int ver, int par, vector<int> adj[], vector<int> & visited ){
    if(visited[ver]&& ver!= par) return true;
    if(visited[ver]) return false;
    visited[ver] = true;
    bool haveLoop = false;
    for(auto ngh : adj[ver]){
        haveLoop |= dfs(ngh,ver,adj,visited);
        if(haveLoop) return true;
    }
    return haveLoop;
}

bool isCycle(int v, int e, vector<pair<int,int>> edges){
    vector<int>adj[v];
    vector<int> visited;
    for(int i=0;i<e;i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    bool haveLoop = false;
    for(int i=0; i<v;i++){
        if(visited[i]) continue;
        haveLoop |= dfs(i,-1,adj,visited);
        if(haveLoop) return true;
    }
    return haveLoop;

}



/***********************************************************************************************/

bool solve(int node,int par,vector<vector<int>> &adj,vector<bool> &vis){
    vis[node]=true;
    for(auto nbr : adj[node]){
        if(vis[nbr]&&nbr!=par) return true;
        if(vis[nbr]) continue;
        bool isCycle = solve(nbr,node,adj,vis);
        if(isCycle) return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
   vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> vis(n+1,false);
    bool isCycle = false;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        bool isCycle = solve(i,-1,adj,vis);
        if(isCycle) return "Yes";
    }
    return "No";
}


/***********************************************************************************************
                                 In Directed Graph
***********************************************************************************************/


// just change condn from int par to isPresentInDfs vector
bool solve(int node,vector<bool> &isPresentInDfs,vector<vector<int>> &adj,vector<bool> &vis){
    vis[node]=true;
    isPresentInDfs[node]= true;
    for(auto nbr : adj[node]){
        if(vis[nbr]&&isPresentInDfs[nbr]) return true;
        if(vis[nbr]) continue;
        bool isCycle = solve(nbr,isPresentInDfs,adj,vis);
        if(isCycle) return true;
    }
    isPresentInDfs[node]= false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges)
{
   vector<vector<int>> adj(n+1);
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].push_back(edges[i].second);
    }
    vector<bool> vis(n+1,false);
    vector<bool> isPresentInDfs(n+1,false);
    bool isCycle = false;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        bool isCycle = solve(i,isPresentInDfs,adj,vis);
        if(isCycle) return 1;
    }
    return 0;
}