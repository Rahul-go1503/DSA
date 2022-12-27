#include<bits/stdc++.h>
using namespace std;
// bool cmp(string s1,string s2){
//     return s1.length()<s2.length();
// }

// TC- nlogn + ln

// look again into the discussion tab
string longestCommonPrefix(vector<string>& strs) {
    string ans ="";
    bool hasChar= true;
    sort(strs.begin(),strs.end());
    for(int i=0;i<strs[0].length();i++){
        for(int j=0;j<strs.size();j++){
            if(strs[0][i]!=strs[j][i]){
                hasChar=false;
            }
        }
        if(hasChar) ans.push_back(strs[0][i]);
    }
    return ans;
}

// O(n*l) where l is the maximum length of a character
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ln = strs[0].length(), n = strs.size();

        for(int i=1;i<n;i++){
            if(ln == 0) return "";
            int li = strs[i].length();
            for(int j=0;j<li && j<ln;j++){
                if(strs[i][j] != strs[i-1][j]){
                    ln = j;
                    break;
                }
            }
            if(li<ln) ln = li;
        }
        string ans;
        for(int i=0;i<ln;i++) ans.push_back(strs[0][i]);
        return ans;
    }
};