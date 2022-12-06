#include <bits/stdc++.h>
using namespace std;

/*
PQ(1st para price) se solve nhi kr skte kyuki vo price ke base par calculate krega eq. agar baad me kisi node par hum jate hai jiski value phele
ab wale se jyada hai to vo que me push nhi krega but vo soln ho skta hai(k value kam hai to)

PQ(1st para k) esa krne ka koi fayda nhi hai kyuki k +1 se increase ho rhe hai so simple BFS traversal kr skte hai

Note : agar ku==k means hme isse aage nhi ja skte hai ye max stop hai
des mil jay tab bhi rukna nhi hai kyuki future me usse best path mil skta hai
des milti hai to iska matlab sirf yhi hua ki hmne ek possible path search kr liya na ki best
Dijkstra me jab dest milti hai to iska matlab vo best hi hai
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto &ed : flights){
            adj[ed[0]].push_back({ed[1],ed[2]});
        }

        queue<vector<int>> q;
        q.push({-1,0,src});

        vector<int> price(n,INT_MAX);
        price[src] = 0;

        while(q.size()){
            auto itr = q.front();
            q.pop();
            int ku = itr[0];
            int pu = itr[1];
            int u = itr[2];

            if(ku==k) continue;

            for(auto &p : adj[u]){
                int v = p.first;
                int pv = p.second;

                if(pu + pv < price[v] && ku+1<=k){
                    price[v] = pu + pv;
                    q.push({ku+1,price[v],v});
                }
            }
        }

        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};