#include <bits/stdc++.h>
using namespace std;
/*
 SKIP if t is not updated  :
 lets say u1 -> {v1}; u2-> {v1};
 jab u1 se v1 par aaye to time[v1] ko update krke que me push kra or vo abhi tak process bhi nhi hua tha ki 
 hmne time[v1] ko fir se update ke diya u2 se ate vqt to baad me jab phele wala node process hoga to uski t ki value updated
 nhi hogi to use process krne ka koi sense nhi

 2. number count krne ke liye simply ek ways array bna lo isse hum src node se kisi bhi node tak shortest path se phunchne 
 ke ways track kr skte hai
 jab hum same prev des se kisi node par phunchte hai to ways[v] += ways[u];
 agar usse kam time me to update the ways[v]=ways[u]; 
*/

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

            if(t>time[u]) continue; // SKIP if t is not updated 
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