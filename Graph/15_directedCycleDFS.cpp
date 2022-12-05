#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    // Function to detect cycle in a directed graph.
    // no need of dfsVis array
    bool dfs(int v,vector<int> adj[],vector<int>&vis,vector<int>&dfsVis){
        // vis hai or dfs call me bhi hai
        // Back edge
        if(vis[v] && dfsVis[v]) return true;
        // only vis hai to false
        if(vis[v]) return false;

        vis[v]=1;
        dfsVis[v]=1;

        for(auto nbh : adj[v]){
            //IMP :  agar par ko ja rha hai to means cycle hai, means p ki need nhi hai yha par
            if(dfs(nbh,adj,vis,dfsVis)) return true;
        }

        // remove vertex from dfsVis -> BackTrack
        dfsVis[v]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>dfsVis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i] && dfs(i,adj,vis,dfsVis)) return true;
        }
        return false;
    }
};

// more efficient

/*
value of vis/color represents three states:
0:have not been visited
1:not cycle/safe
2:cycle/first check whether in dfs call then tell prev this node is safe or not/unsafe
For DFS,we need to do some optimization.When we travel a path,we mark the node with 2 which represents having been visited,and when we encounter a node which results in a cycle,we return false,all node in the path stays 2 and it represents unsafe.And in the following traveling,whenever we encounter a node which points to a node marked with 2,we know it will results in a cycle,so we can stop traveling.On the contrary,when a node is safe,we can mark it with 1 and whenever we encounter a safe node,we know it will not results in a cycle.
*/
class Solution {
    bool dfs(int v,vector<int> adj[],vector<int>&vis){
        // vis hai or dfs call me bhi hai
        // Back edge
        if(vis[v]==2) return true;
        // only vis hai to false
        if(vis[v]) return false;

        // if(vis[v]) return vis[v]==2;

        vis[v]=2;

        for(auto nbh : adj[v]){
            //IMP :  agar par ko ja rha hai to means cycle hai, means p ki need nhi hai yha par
            if(dfs(nbh,adj,vis)) return true;
        }

        // remove vertex from dfsVis -> BackTrack
        vis[v]=1;
        return false;
    }
   public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i] && dfs(i,adj,vis)) return true;
        }
        return false;
    }
};