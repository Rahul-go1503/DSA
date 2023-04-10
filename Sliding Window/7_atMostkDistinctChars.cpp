#include <bits/stdc++.h>
using namespace std;

/*
 - coding ninja
 Given a string, find the length of the longest substring T that contains at most k distinct characters.
*/

int kDistinctChars(int k, string &str)
{
    int mp[26] = {0}, win[26] = {0};
    for(auto &ch: str) mp[ch-'a']++;
    int l = 0, r = 0, d = 0;
    int ls = str.length();
    
    while(r<ls){
        if(win[str[r]-'a']==0) k--;
        win[str[r]-'a']++;
        
        while(l<=r && k<0){
            if(win[str[l]-'a']==1) k++;
            win[str[l++]-'a']--;
        }
        d = max(d,r-l+1);
        r++;
    }
    return d;
}