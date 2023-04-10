#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        int mark[26];
        for(int i=0;i<26;i++) mark[i] = -1;

        for(int i=0;i<n;i++) mark[s[i]-'a'] = i;

        vector<int> res;

        int i = 0;
        while(i < n){
            int len = 0, j = mark[s[i] - 'a'];
            // i++;
            while(i<=j){
                j = max(j,mark[s[i] - 'a']);
                i++;
                len++;
            }
            res.push_back(len);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        // filling impact of character's
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            mp[ch] = i;
        }
        // making of result
        vector<int> res;
        int prev = -1;
        int maxi = 0;
        
        for(int i = 0; i < s.size(); i++){
            maxi = max(maxi, mp[s[i]]);
            if(maxi == i){
                // partition time
                res.push_back(maxi - prev);
                prev = maxi;
            }
        }
        return res;
    }
};