#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<int>adj[], vector<int>& vis){
        if(vis[node]) return;
        vis[node] = 1;
        
        for(auto &nbh : adj[node]){
            dfs(nbh,adj,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0; j<n;j++){
                if(mat[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(i,adj,vis);
            cnt++;
        }
        return cnt;
    }
};