#include <bits/stdc++.h>
using namespace std;

int dfs(int node,int A, vector< vector<int> >& adj,vector<bool> & vis){
    if(node==A) return 1;
    vis[node]= 1;
    for(auto nbr : adj[node]){
        if(vis[nbr]) continue;
        int isExist = dfs(nbr,A,adj,vis);
        if(isExist) return 1;
    }
    cout<<"enter here"<<endl;
    return 0;
    
}

int solve(int A, vector<vector<int> > &B) {
    vector< vector<int> > adj (A+1);
    vector<bool> vis(A+1,false);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
    }
    for(int i=1;i<=A;i++){
        cout<<i<<"-> ";
        for (auto nbr : adj[i]){
            cout<<nbr<<" ";
        }
        cout<<endl;
    }
    return dfs(1,A,adj,vis);
}

int main(){
    int A =5;
    vector<vector<int> > B = {{1, 4},{2, 1},{4, 3},{4, 5},{2, 3},{2, 4},{1, 5},{5, 3},{2, 5},{5, 1},{4, 2},{3, 1},{5, 4},{3, 4},{1, 3},{4, 1},{3, 5},{3, 2},{5, 2}
};
    solve(A,B);
    return 0;
}
