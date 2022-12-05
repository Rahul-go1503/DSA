#include <bits/stdc++.h>
using namespace std;


// O(n2*l) need to optimize
class Solution {
public:
    int ladderLength(string s, string e, vector<string>& words) {
        int n = words.size();
        int l = words[0].length();

        bool eFound = false;
        int src = -1;
        
        // check for starting and ending words
        for(int i =0;i<n;i++){
            if(words[i]==s) src = i;
            if(words[i]==e) eFound = true;
        }
        if(!eFound) return 0;
        if(src==-1){
            words.push_back(s);
            n++;
        }
        
        // creating adj list
        vector<int> adj[n];
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int diff = 0;
                for(int w=0;w<l;w++){
                    if(words[i][w]!=words[j][w]){
                        if(++diff>1) break;
                    }
                }
                if(diff==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        // BFS Traversal(searching in which level we found endword)
        vector<int> vis(n);
        queue<int> q;
                
        // we havve to give total words including starting word
        int lv = 0;
        if(src==-1) src = n-1;
        q.push(src);

        // to count level we need to loops
        while(q.size()){
            int sz = q.size();
            while(sz--){
                int u = q.front();
                q.pop();
                vis[u] = 1;

                for(auto &nbh : adj[u]){
                    if(vis[nbh]) continue;
                    if(words[nbh]==e){
                        if(src==n-1) words.pop_back();
                        // yha par return krenge to 2 level kam honge
                        // 1. par ka jo count nhi hua
                        //2. iska jo nxt time count hota
                        return lv+2;
                    }
                    q.push(nbh);
                }
            }
            lv++;
        }
        if(src==n-1) words.pop_back();
        return 0;
    }
};