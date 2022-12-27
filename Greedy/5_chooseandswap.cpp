#include <bits/stdc++.h>
using namespace std;

// O(26*n), (26)
class Solution{
public:
    string chooseandswap(string a){
        int seen[26] = {0};
        for(auto &ch : a) seen[ch-'a'] = 1;
        
        char f = '0' , s;
        for(auto &ch : a){
            seen[ch-'a'] = 0;
            // see if there is any smaller char exist
            for(int i=0;i<ch-'a';i++){
                if(seen[i]){
                    f = ch, s = i + 'a';
                    break;
                }
            }
            if(f != '0') break;
        }
        
        for(auto &ch : a){
            if(ch == f) ch = s;
            else if(ch == s) ch = f;
        }
        
        return a;
    }  
};