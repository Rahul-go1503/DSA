#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res;
        int k = 0;
        while(k++<32){
            if(n&1) res |= 1;
            if(k<32) res <<= 1;
            n >>= 1;
        }
        return res;
    }
};