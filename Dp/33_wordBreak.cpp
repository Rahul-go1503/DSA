#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[301];
    bool solve(int idx,string &s, unordered_set<string> &st){
        int l = s.length();
        if(idx==l) return true;
        if(dp[idx] != -1) return dp[idx];
        string temp;
        for(int i=idx;i<l;i++){
            temp.push_back(s[i]);
            if(st.count(temp) && solve(i+1,s,st)) return dp[idx] =  true;
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> st(dict.begin(),dict.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,s,st);
    }
};