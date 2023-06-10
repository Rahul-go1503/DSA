#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(string &s){
        int i = 0, j = s.length() - 1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    vector<vector<string>> solve(int i,string &s){
        int n = s.length();
        vector<vector<string>> res;
        if(i==n) return res;
        
        string temp;
        for(int k = i;k<n;k++){
            temp += s[k];
            if(!isPalindrome(temp)) continue;
            auto ans = solve(k+1,s);
            if(ans.size()==0){
                res.push_back({temp});
            }
            for(auto &v : ans){
                v.insert(v.begin(),temp);
                res.push_back(v);
            }
        }
        return res;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        return solve(0,s);
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        
        vector<string> path;
        dfs(0, s, path, ret);
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};