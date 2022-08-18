#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> visited(V,false);
                queue<int> q;
                visited[0]=1;
                q.push(0);
                while(!q.empty()){
                    int front = q.front();
                    ans.push_back(front);
                    q.pop();
                    for(auto x : adj[front]){
                        if(!visited[x]){
                            visited[x]=1;
                            q.push(x);
                        }
                    }
                }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends