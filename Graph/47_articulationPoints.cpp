#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int u, int par, int timer, int vis[],vector<int> adj[], int tin[], int low[], set<int> &st){
        vis[u] = 1;
        tin[u] = low[u] = timer++;
        
        int child = 0;
        for(auto &v : adj[u]){
            // par par jana hi nhi hai
            if(v==par) continue;
            // agar vis hai to uske low ko mat lo tin ko lo... agar vo hi art point hai to uske iska low uska tin ho skta hai
            // and low hmesa ese path se consider krna hai jo phele visit nhi hua
            if(vis[v]){
                if(low[u]>tin[v]) low[u] = tin[v];
            }else{
                dfs(v,u,timer,vis,adj,tin,low,st);
                child++;
                if(low[u]>low[v]) low[u] = low[v];

                // u to v => v agar u se phele kisi node tak phunch skta hai to u art point nhi ho skta
                if(par!=-1 && tin[u] <= low[v]){
                    st.insert(u);
                }
            }
        }
        // handling parent==-1 case
        if(par==-1 && child>1) st.insert(u);
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        int vis[V] = {} , tin[V],low[V];
        
        vector<int> points;

        // we may find a node art node more than one so we use set(order me return krna hai)
        // if we use mark array than O(N) better than set
        set<int> st;
        dfs(0,-1,1,vis,adj,tin,low,st);
        
        if(st.empty()) return {-1};
        for(auto &u : st){
            points.push_back(u);
        }
        return points;
    }
};