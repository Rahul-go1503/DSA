#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), cnt = n;
        vector<vector<int>> dp(n,vector<int>(n,1));
        for(int g=1;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else dp[i][j] = 0;
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};

// without dp
class Solution {
public:
    int countSubstrings(string s) {
        int counter = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                counter++;
            }
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                counter++;
            }
        }
        return counter;
    }
};