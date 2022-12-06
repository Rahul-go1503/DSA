#include <bits/stdc++.h>
using namespace std;

#define mod 100000
int mul(int a, int b){
    return ((a%mod) * (b%mod))%mod;
}

// simple BFS Serach operation

// O(N=100000)
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int> q;
        vector<int> vis(mod+1);
        q.push(start);
        vis[start] = 1;
        int lv = -1;
        while(q.size()){
            int sz = q.size();
            lv++;
            while(sz--){
                int u = q.front();
                q.pop();
                
                if(u==end) return lv;
                
                for(auto &num : arr){
                    int v = mul(u,num);
                    if(vis[v]) continue;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        
        return -1;
    }
};