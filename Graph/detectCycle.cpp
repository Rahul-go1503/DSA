// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int ver,int par,vector<int> adj[],vector<int>&visited){
        if(visited[ver]&&ver!=par) return true;
        visited[ver]=1;
        bool hasCycle = false;
        for(auto ngh : adj[ver]){
            if(ngh==par) continue;
            hasCycle |= dfs(ngh,ver,adj,visited);
        }
        return hasCycle;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        bool hasCycle = false;
        for(int i=0;i<V;i++){
        if(!visited[i]) hasCycle |=dfs(i,-1,adj,visited);
        }
        return hasCycle;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends