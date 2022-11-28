#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O()
	Space Complexity: O()
*/


class Solution {
  public:
    string longestPalin (string s) {
        int n = s.length();
        vector<int> mx = {0,0};
        // for odd palin
        for(int i=1;i<n;i++){
            int l = i-1, r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){l--;r++;}
            if(r-l-2 > mx[1]-mx[0]) mx = {l+1,r-1};
        }
        // for even palin
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]) continue;
            int l = i-1, r = i+2;
            while(l>=0 && r<n && s[l]==s[r]){l--;r++;}
            if(r-l-2 > mx[1]-mx[0]) mx = {l+1,r-1};
        }
        return s.substr(mx[0],mx[1]-mx[0]+1);
    }
};