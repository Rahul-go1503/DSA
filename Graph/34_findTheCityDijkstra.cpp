#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++) dis[i][i] = 0;

        vector<pair<int,int>> adj[n];
        for(auto &itr : edges){
            adj[itr[0]].push_back({itr[1],itr[2]});
            adj[itr[1]].push_back({itr[0],itr[2]});
        }

        for(int i=0;i<n;i++){
            priority_queue<vi,vector<vi>,greater<vi>> pq;
            pq.push({0,i});

            while(pq.size()){
                int d = pq.top()[0];
                int u = pq.top()[1];
                pq.pop();
                
                if(d>dis[i][u]) continue;
                for(auto &p : adj[u]){
                    int v = p.first;
                    int wt = p.second;

                    if(d+wt<dis[i][v]){
                        dis[i][v] = d+wt;
                        pq.push({dis[i][v],v});
                    }
                }
            }
        }

        int ans = 0 , mn = n;
        for(int i=0;i<n;i++){
            int cnt = 0;

            for(int j=0;j<n;j++){
                if(dis[i][j]<=th) cnt++;
            }

            if(cnt<=mn){
                mn = cnt;
                ans = i;
            }
        }

        return ans;
    }
};