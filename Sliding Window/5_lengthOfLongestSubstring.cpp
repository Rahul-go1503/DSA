#include <bits/stdc++.h>
using namespace std;


/*
n,n
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        int mx = 0, cnt = 0,j=0;
        for(int i=0;i<n;i++){
            auto itr = mp.find(s[i]);
            if(itr != mp.end() && itr->second >= j){
                cnt = i-j;
                j = itr->second + 1;
                // cout<<cnt<<endl;
                mx = max(mx,cnt);
            }
            mp[s[i]] = i;
            // cout<<s[i]<<endl;
        }
        mx = max(mx,n-j);
        return mx;
    }
};

/*
 - by sliding window
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> win;
        int n = s.length();
        int l = 0, r = 0, d = 0;

        // at a given we can only have one rep elem in the window, it can be track by flag
        bool flag = false;
        while(r<n){
            if(++win[s[r]] > 1) flag = true;

            // ek baar flag true hue to vo false bhi hoga hi to loop to terminate ho jaega
            while(flag){
                if(--win[s[l]] == 1) flag = false;
                l++;
            }

            d = max(d,r-l+1);
            r++;
        }
        return d;
    }
};