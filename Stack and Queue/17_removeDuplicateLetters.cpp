#include <bits/stdc++.h>
using namespace std;

/* 
 monotonic stack
 O(n) we processs one ch at most 2 times, space - O(n)
 we use string itself as a stack
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> seen(26,0);
        int n = s.length();
        vector<int> lastIdx(26,0);
        for(int i=0;i<n;i++) lastIdx[s[i]-'a'] = i;

        string ans;
        for(int i=0;i<n;i++){
            int chIdx = s[i] - 'a';
            if(seen[chIdx]) continue;

            while(ans.length() && ans.back() > s[i]  && i < lastIdx[ans.back() - 'a']){
                seen[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            seen[chIdx] = 1;
        }
        return ans;
    }
};