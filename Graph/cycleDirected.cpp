// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
   public:
    // Function to detect cycle in a directed graph.
    bool dfs(int ver,vector<int> adj[],vector<int>&visited,vector<int>&dfsVisited){
        if(visited[ver]&&dfsVisited[ver]) return true;
        if(visited[ver]) return false;
        visited[ver]=1;
        dfsVisited[ver]=true;
        bool hasCycle = false;
        for(auto ngh : adj[ver]){
            // cout<<"enter here: "<<ngh<<endl;
            // if(ngh==par) continue;
            if(ngh==ver){
                hasCycle=true;
            }
            hasCycle |= dfs(ngh,adj,visited,dfsVisited);
        }
        dfsVisited[ver]=false;
        return hasCycle;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        vector<int>dfsVisited(V,0);
        bool hasCycle = false;
        for(int i=0;i<V;i++){
        if(!visited[i]) hasCycle |=dfs(i,adj,visited,dfsVisited);
        }
        return hasCycle;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends