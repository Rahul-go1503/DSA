#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i]) continue;
            // ver, par
            queue<pair<int,int>> q;
            q.push({i,-1});
            vis[i] = 1;
            
            while(q.size()){
                int v = q.front().first;
                int p = q.front().second;
                q.pop();
                
                for(auto &nbh : adj[v]){
                    if(nbh==p) continue; // agar par hai to jana hi nhi hai
                    // yha par agar vis hai or hum bfs kr rhe hai means level order... means isse phele kisi ne 
                    // isko touch kr diya jo kisi or dir se aaya or iseke level ka tha 
                    if(vis[nbh]) return true;
                    q.push({nbh,v});
                    vis[nbh] = 1;
                }
            }
        }
        return false;
    }
};