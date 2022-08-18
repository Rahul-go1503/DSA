#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        string ans;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(strs[j].length()<i+1 || strs[0][i]!=strs[j][i]){
                    return ans;
                }
            }
                ans.push_back(strs[0][i]);
        }
        return ans;
    }
};