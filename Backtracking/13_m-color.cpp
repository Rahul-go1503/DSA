#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool solve(int u,int m,vector<int> adj [],vector<int> &color){
        for(int i=0;i<m;i++){
            bool fl = true;
            for(auto &v : adj[u]){
                if(color[v]==i){
                    fl = false;
                    break;
                }
            }
            if(fl){
                color[u] = i;
                bool fl2 = true;
                for(auto &v : adj[u]){
                    if(color[v] != -1) continue;
                    if(!solve(v,m,adj,color)){
                        color[u] = -1;
                        fl2 = false;
                        break;
                    }
                }
                if(fl2) return true;
            }
        }
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> adj[n];
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]==1) adj[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++){
            if(!solve(i,m,adj,color)) return false;
        }
        return true;
    }
};

class Solution{
public:
    bool isSafe(int v, bool graph[101][101], int color[101], int c, int V) {
        // checking if the connected nodes to v have same colour as c.
        for (int i = 0; i < V; i++)
            if (graph[v][i] && c == color[i]) return false;
    
        // returning true if no connected node has same colour.
        return true;
    }
    
    bool graphColoringUtil(bool graph[101][101], int m, int color[101], int v,
                           int V) {
        // if all vertices have been assigned colour then we return true.
        if (v == V) return true;
    
        for (int c = 1; c <= m; c++) {
            // checking if this colour can be given to a particular node.
            if (isSafe(v, graph, color, c, V)) {
                // assigning colour to the node.
                color[v] = c;
    
                // calling function recursively and checking if other nodes
                // can be assigned other colours.
                if (graphColoringUtil(graph, m, color, v + 1, V) == true)
                    // returning true if the current allocation was successful.
                    return true;
    
                // if not true, we backtrack and remove the colour for that node.
                color[v] = 0;
            }
        }
        // if no colour can be assigned, we return false.
        return false;
    }
    
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int *color = new int[n];
        for (int i = 0; i < n; i++) color[i] = 0;
    
        // checking if colours can be assigned.
        if (graphColoringUtil(graph, m, color, 0, n) == false) {
            return false;
        }
    
        return true;
    }
};