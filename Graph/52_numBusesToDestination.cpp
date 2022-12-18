#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isSrc = false , isTar = false;
    void dfs(int u,int src,int tar, unordered_set<int> &vis,unordered_map<int,vector<int>> &adj, stack<int> &s){
        vis.insert(u);
        if(u==src) isSrc = true;
        if(u==tar) isTar = true;
        for(auto &v : adj[u]){
            if(!vis.count(v)) dfs(v,src,tar,vis,adj,s);
        }
        s.push(u);
    }

    void scc(int u,unordered_set<int> &vis,unordered_map<int,vector<int>> &adj){
        vis.insert(u);

        for(auto &v : adj[u]){
            if(!vis.count(v)) scc(v,vis,adj);
        }
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int tar) {
        unordered_map<int,vector<int>> adj;
        for(auto &r : routes){
            int n = r.size();
            if(n==1){
                adj[r[0]];
                continue;
            }
            for(int i = 0;i<n-1;i++){
                adj[r[i]].push_back(r[i+1]);
            }
            adj[r[n-1]].push_back(r[0]);
        }
        if(!adj.count(src) || !adj.count(tar)) return -1;
        unordered_set<int> vis;
        stack<int> s;
        bool canReach = false;
        for(auto &m : adj){
            isSrc = isTar = false;
            if(!vis.count(m.first)){
                dfs(m.first,src,tar,vis,adj,s);
                if(isSrc && isTar) canReach = true;
            }
        }
        
        if(!canReach) return -1;
        unordered_map<int,vector<int>> adjRev;
        for(auto &r : routes){
            int n = r.size();
            if(n==1){
                adjRev[r[0]];
                continue;
            }
            for(int i = 1;i<n;i++){
                adjRev[r[i]].push_back(r[i-1]);
            }
            adjRev[r[0]].push_back(r[n-1]);
        }
        vis.clear();
        int cnt = 0;
        while(s.size()){
            int u = s.top();
            s.pop();
            if(!vis.count(u)){
                scc(u,vis,adjRev);
                if(vis.count(src) && vis.count(tar)) return ++cnt;
                if(vis.count(src) || vis.count(tar)) cnt++;
            }
        }
        return -1;
    }
};



    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T)
            return 0;
        // For some reason leetcode decided that putting a testcase where
        // they concatenate several cycles together like 1->2->1->2->1->2
        // and also call it a bus route even though it doesn't really make sense.
        // So, use unordered_set as protection against this bs.
        unordered_map<int, unordered_set<int>> graph;
        for(int r = 0; r < routes.size(); r++){
            for(auto bs : routes[r]){
                graph[bs].insert(r);
            }
        }
        
        // visited has all the routes we have been to.
        unordered_set<int> visited;
        
        // queue contains integers that represent the index of the route.
        queue<int> q;
        
        // retrieve routes for the starting bus stop.
        for(auto route : graph[S]){
            q.push(route);
            visited.insert(route);
        }
        
        // all of them require you to take one bus.
        int dist = 1;
        
        while(q.size()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int route = q.front(); q.pop();
                int start = -1;
				
                // visit each bus stop on this route
                for(auto bs: routes[route]){
                    // this is just to avoid cycle iteration as 
                    // in the example above.
                    if(start == -1)
                        start = bs;
                    else if(start == bs)
                        break;
                    
                    // happens to be your destination
                    if(bs == T)
                        return dist;
                    
                    // to which routes can i transit from this bus stop or bullshit :)
                    for(auto access_routes : graph[bs]){
                        if(!visited.count(access_routes)){
                            visited.insert(access_routes);
                            q.push(access_routes);
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }