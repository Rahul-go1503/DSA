#include <bits/stdc++.h>
using namespace std;

// Ques - For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> adj[num];
        vector<int> indeg(num,0);
        
        for(auto &e : pre){
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<num; i++) if(indeg[i]==0) q.push(i);
        
        vector<int> order;
        while(q.size()){
            int u = q.front();
            q.pop();
            order.push_back(u);
            num--;
            
            for(auto &nbh : adj[u])
                if(--indeg[nbh]==0) q.push(nbh);
        }
        if(num) order.clear();
        return order;
    }
};