#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        l--;
        while(l<r){
            int mask = 1 << l;
            if(y & mask) x |= mask;
            l++;
        }
        return x;
    }
};
//  O(1)
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        l--;
        int mask = (1LL << (r-l)) - 1;
        mask = y & mask << l;
        return x |= mask;
    }
};