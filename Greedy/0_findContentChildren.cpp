#include <bits/stdc++.h>
using namespace std;

// greedy + two pointer
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int res  = 0, nc = s.size(), ng = g.size();
        for(int i=0,j=0;i<nc && j<ng;i++){
            if(s[i]>=g[j]) j++, res++;
        }
        return res;
    }
};