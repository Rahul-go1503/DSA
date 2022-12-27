#include <bits/stdc++.h>
using namespace std;

// more anagram question is in string section
int isPossible (string s)
{
    int freq[26] = {0};
    for(auto &ch : s) freq[ch-'a']++;
    
    int oddCnt = 0;
    for(int i = 0;i<26; i++)
        if(freq[i]&1 && ++oddCnt > 1) return false;
    
    return true;
}