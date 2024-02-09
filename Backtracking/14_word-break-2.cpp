#include<bits/stdc++.h>
using namespace std;

class Solution{
    void solve(int idx,unordered_set<string> &st, string &s,vector<string> &res, string sentence){
        int n = s.length();
        if(idx==n){
            sentence.pop_back();
            res.push_back(sentence);
            return;
        }
        string word;
        for(int i = idx;i<n;i++){
            word.push_back(s[i]);
            if(st.count(word)){
                solve(i+1,st,s,res,sentence + word + " ");
            }
        }
    }
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> res;
        string sentence = "";
        unordered_set<string> st;
        for(auto &word : dict) st.insert(word);
        solve(0,st,s,res,sentence);
        return res;
    }
};