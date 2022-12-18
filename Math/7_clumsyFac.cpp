#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int n) {
        if(n == 1) return -1;
        int res = 0;
        if(n>=2) res -= n*(n-1);
        if(n>=3) res = res/(n-2);
        if(n>=4) res += n-3;
        if(n<=4) return res;
        return res + solve(n-4);
    }
public:
    int clumsy(int n) {
        if(n == 1) return 1;
        int res = 0;
        if(n>=2) res += n*(n-1);
        if(n>=3) res = res/(n-2);
        if(n>=4) res += n-3;
        if(n<=4) return res;
        return res + solve(n-4);
    }
};
//i * (i-1) / (i-2) = i+1 when i >= 5
class Solution {
public:
    int clumsy(int n) {
        if(n <= 2) return n;
        if(n <= 4) return n+3;
        if(n%4 == 0) return n+1;
        if(n%4 <= 2) return n+2;
        else return n-1;
    }
};