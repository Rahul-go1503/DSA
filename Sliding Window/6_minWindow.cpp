#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool hasCover(unordered_map<char,int> &freqs, unordered_map<char,int> &freqt){
        for(auto &p : freqt) if(freqs.find(p.first) == freqs.end() || freqs[p.first] < p.second) return false;
        return true;
    }
public:
    string minWindow(string s, string t) {
        int ls = s.length(), lt = t.length();
        if(lt>ls) return "";

        unordered_map<char,int> freqs, freqt;
        for(int i=0;i<lt;i++) freqt[t[i]]++, freqs[s[i]]++;

        int l = 0, r = lt-1, st = 0, ed = lt-1, mn = INT_MAX;
        bool found  = false;
        string ans = "";
        while(r<ls){
            while(l<=r && hasCover(freqs,freqt)){
                found = true;
                if(mn>r-l){
                    mn = r-l;
                    st = l, ed = r;
                }
                freqs[s[l++]]--;
            }
            freqs[s[++r]]++;
        }
        if(!found) return ans;
        for(int i=st;i<=ed;i++) ans.push_back(s[i]);
        return ans;
    }
};

/*
Complexity Analysis
Time Complexity: O(|S| + |T|)where |S| and |T| represent the lengths of strings S and T. In the worst case we might end up visiting 
every element of string S twice, once by left pointer and once by right pointer.

Space Complexity: O(|S| + |T|).|S|when the window size is equal to the entire string S. |T| when T has all unique characters.

further optimization can be done by iterating over filtered s
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int ls = s.length(), lt = t.length();
        if(lt>ls) return "";

        unordered_map<char,int> freqt, win;
        for(int i=0;i<lt;i++) freqt[t[i]]++;
        int req = freqt.size();
        int found  = 0;

        int l = 0, r = 0, st = 0, ed = 0, mn = INT_MAX;
        string ans = "";
        while(r<ls){
            win[s[r]]++;
            if(freqt.find(s[r]) != freqt.end() && freqt[s[r]]==win[s[r]]) found++;
            while(l<=r && found == req){
                if(mn>r-l){
                    mn = r-l;
                    st = l, ed = r;
                }
                if(freqt.find(s[l]) != freqt.end() && freqt[s[l]]>win[s[l]]-1) found--;
                win[s[l++]]--;
            }
            r++;
        }
        return mn==INT_MAX ? "" : s.substr(st,ed-st+1);
    }
};