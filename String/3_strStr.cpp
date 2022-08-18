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