#include <bits/stdc++.h>
using namespace std;

// gfg
// TC - nlogn
#define vi vector<int>
class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        int len = str.length();
        
        // didn't work for unordered_map
        map<vi,int> mp; // storing diff - {zero - one , two- one};
        mp[{0,0}] = 1;
        long long cnt = 0;
        int zero = 0 , two = 0;
        
        for(int i=0;i<len;i++){
            if(str[i]=='0') zero++;
            else if(str[i]=='2') two++;
            else zero-- , two--;
            
            if(mp.find({zero,two}) == mp.end()) mp[{zero,two}]++;
            else cnt += mp[{zero,two}]++;
        }
        
        return cnt;
    }
};