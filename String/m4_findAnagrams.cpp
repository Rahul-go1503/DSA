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
    bool allZero(int arr[]){
        for(int i=0;i<26;i++){
            if(arr[i]!=0) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int len1= s.length(), len2 = p.length();
        if(len2>len1) return {};
        int count[26] = {0};
        for(int i =0; i<len2;i++){
            count[p[i]-'a']++;
            count[s[i]-'a']--;
        }
        
        vector<int> ans;        
        if(allZero(count)) ans.push_back(0);
        for(int i = len2;i<len1;i++){
            count[s[i]-'a']--;
            count[s[i-len2]-'a']++;
            if(allZero(count)) ans.push_back(i-len2+1);
        }
        return ans;
    }
};