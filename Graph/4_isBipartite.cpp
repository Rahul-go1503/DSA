#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool bfs(int rootNode, vector<vector<int>> &graph,vector<int> &color){
        queue<int> q;
        q.push(rootNode);
        color[rootNode] = 0;
        
        while(q.size()){
            int node = q.front();
            q.pop();
            
            for(auto &nbh : graph[node]){
                if(color[nbh]!=-1 && color[nbh]==color[node]) return false;
                if(color[nbh]!=-1) continue;
                color[nbh] = !color[node];
                q.push(nbh);
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);
        for(int i = 0; i<v;i++){
            if(color[i]!=-1) continue;
            if(!bfs(i,graph,color)) return false;
        }
        return true;
    }
};
// DFS
class Solution {
    bool dfs(int node,int clr, vector<vector<int>> &graph,vector<int> &color){
        color[node] = clr;
        
        for(auto &nbh : graph[node]){
            if(color[nbh]!=-1 && color[nbh]==color[node]) return false;
            if(color[nbh]!=-1) continue;
            if(!dfs(nbh,!clr,graph,color)) return false;
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);
        for(int i = 0; i<v;i++){
            if(color[i]!=-1) continue;
            if(!dfs(i,0,graph,color)) return false;
        }
        return true;
    }
};