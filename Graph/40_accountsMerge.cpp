#include <bits/stdc++.h>
using namespace std;

// IMP - Ques
// https://leetcode.com/problems/accounts-merge/solutions/1539477/accounts-merge/?orderBy=most_votes
class UnionFind{
    int cnt;
    vector<int> size, par;
public:
    UnionFind(int n){
        cnt = n;
        size.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++) par[i] = i;
    }
    
    int find(int u){
        if(u==par[u]) return u;
        return par[u] = find(par[u]);
    }

    void unionSet(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        if(size[pu]<size[pv]){
            par[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            par[pv] = pu;
            size[pu] +=size[pv];
        }
        cnt--;
    }

    int count() {return cnt;}
};

// TC - O(Nlog(N)) , SC - O(N);
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int a = acc.size();
        // SC - O(a * 9)
        unordered_map<string,int> mp;
        // SC - O(a * 2)
        UnionFind ds(a);

        // TC - O(a*9*4*alpha )
        for(int i=0;i<a;i++){
            for(int j=1;j<acc[i].size();j++){
                auto itr = mp.find(acc[i][j]);
                if(itr!=mp.end()) ds.unionSet(itr->second,i);
                else mp[acc[i][j]] = i;
            }
        }
        // SC - O(a*9), TC - O(a*9*4*alpha )
        vector<vector<string>> merged(a);
        for(auto &p : mp){
            int u = ds.find(p.second);
            merged[u].push_back(p.first);
        }

        // SC - O(a*9 + a*9), TC - O(a*9*log(a*9) )
        vector<vector<string>> ans;
        for(int i=0;i<a;i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(acc[i][0]);
            for(auto &mail : merged[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};