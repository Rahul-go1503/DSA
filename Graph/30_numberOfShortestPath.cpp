#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
int add(int a,int b){
    return (a%mod + b%mod)%mod;
}
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,long long>> adj[n];
        for(auto &ed : roads){
            adj[ed[0]].push_back({ed[1],ed[2]});
            adj[ed[1]].push_back({ed[0],ed[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});

        vector<long long> time(n,1e18);
        vector<int> ways(n);
        time[0] = 0;
        ways[0] = 1;
  
        while(pq.size()){
            long long t = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(t>time[u]) continue;
            if(u==n-1) return ways[n-1];

            for(auto &p : adj[u]){
                int v = p.first;
                long long wt = p.second;
                
                // int tv = add(t,wt);
                if(t+wt== time[v]){
                    ways[v] = add(ways[v],ways[u]);
                    continue;
                }
                if(t+wt<time[v]){
                    time[v] = t+wt;
                    ways[v] = ways[u];
                    pq.push({time[v],v});
                }
            }
        }
        return -1; // Not reachable code
    }
};