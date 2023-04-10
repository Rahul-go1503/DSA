#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
class Solution{
    public:
    //You need to complete this fucntion
    // pow(a,b) = a^b;
    // a^b/2 * a^b/2 if b is even 
    long long power(int a,int b)
    {
        if(b == 0) return 1;
        long long x = power(a,b/2)%mod;
        if(b%2) return a*x % mod *x % mod;
        return x*x%mod;
    }

};


int power(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
// leetcode
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long int _n = n;
        if(n==INT_MIN) _n = -(n+1) - 1;
        else if(n<0) _n = -n;
        while(_n>=1){
            if(_n&1==1) res *= x;
            x *= x;
            _n >>= 1;
        }
        if(n<0) return 1/res;
        return res;
    }
};

double myPow(double x, int n) { 
    if(n==0) return 1;
    if(n<0) {
        n = -n;
        x = 1/x;
    }
    double ans = 1;
    while(n>0){
        if(n&1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}