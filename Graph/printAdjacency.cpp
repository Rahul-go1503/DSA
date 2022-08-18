/*********************************************************************************************

Question :


Notes :

T.C - > O(N+E) where N -> time taken to visiting nodes, E -> for travelling through adj nodes
S.C -> O(N+E)
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++) adj[i].push_back(i);
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    for(int i=0;i<n;i++){
        cout<<i<<"-> ";
        for (auto nbr : adj[i]){
            cout<<nbr<<" ";
        }
        cout<<endl;
    }
    return adj;
}