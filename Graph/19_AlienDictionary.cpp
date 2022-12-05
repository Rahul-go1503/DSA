#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findOrder(string dic[], int n, int k) {
        
        vector<unordered_set<int>> adj(k);
        vector<int> indeg(k);
        // creating adj
        for(int i=0;i<n-1;i++){
            for(int j=0;j<min(dic[i].length(),dic[i+1].length());j++){
                if(dic[i][j]!=dic[i+1][j]){
                    auto res = adj[dic[i][j]-'a'].insert(dic[i+1][j]-'a');
                    // check whether edge actually inderted or not
                    if(res.second) indeg[dic[i+1][j]-'a']++;
                    break;
                }
            }
        }
        queue<int> q;
        for(int i=0;i<k;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        string order;
        while(q.size()){
            int u = q.front();
            q.pop();
            order.push_back('a'+u);
            
            for(auto &nbh : adj[u]){
                if(--indeg[nbh]==0) q.push(nbh);
            }
            
        }
        return order;
    }
};