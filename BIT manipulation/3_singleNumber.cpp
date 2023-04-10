#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for(auto &x : nums) xr ^= x;

        int tz = __builtin_ctz(xr);
        int xr2 = 0;
        for(auto & x : nums){
            if(x>>tz & 1) xr2 ^= x; 
        }
        return {xr2,xr^xr2};
    }
};