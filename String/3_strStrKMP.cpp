#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string h, string n, int i){
        int index =i;
        for(int j=0;j<n.length();j++){
            if(i>=h.length()) return -1;
            if(n[j]!=h[i]){
                return -1;
            }
            i++;
        }
        return index;
    }
    int strStr(string h, string n) {
        for(int i=0;i<h.length();i++){
            if(h[i]==n[0]){
                int index = solve(h,n,i);
                if(index!=-1) return index;
            }
        }
        return -1;
    }
};
//jianchao-li 
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) { // optimized here 
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};

// KMP Algorithim 
//https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};