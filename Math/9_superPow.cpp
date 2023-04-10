#include<bits/stdc++.h>
using namespace std;

const int mod = 1337;
int ETF(int n){
    vector<int> pf;
    int d = 2;
    while(n>1){
        if(n%d==0){
            if(pf.empty() || pf.back() != d) pf.push_back(d);
            n /= d;
        }else d++;
    }
    int etf = 1;
    for(auto &p : pf) etf *= p-1;
    return etf;
}
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int etf =  ETF(mod);
        // reverse(b.begin(),b.end());
        int n = b.size();
        int B = 0;
        for(int i = 0;i<n;i++){
            B = (B*10 + b[i])%etf;
        }
        int res = 1;
        while(B){
            if(B&1){
                res = res*1LL*a%mod;
            }
            a = a*1LL*a%mod;
            B >>=1;
        }
        return res;
    }
};