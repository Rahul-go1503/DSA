#include <bits/stdc++.h>
using namespace std;

//O(n)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        int sz = bed.size(), i=0;
        for(i=0;i<sz-1 && n>0;i += 2){
            if(!bed[i] && !bed[i+1]) n--;
            if(bed[i+1]) i++;
        }
        if(n> 0 && i==sz-1 && !bed[i]) n--;
        return n==0;
    }
};