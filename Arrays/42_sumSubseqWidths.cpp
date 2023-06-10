#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
typedef long long ll;
class Solution {
public:
    int sumSubseqWidths(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        ll sum = 0;
        ll c = 1;
        for(int i=0;i<n;i++){
            sum = (sum + (a[i]*c + mod)%mod)%mod;
            c = c*2%mod;
        }
        c = 1;
        for(int i = n-1;i>=0;i--){
            sum = (sum - (a[i]*c + mod)%mod + mod)%mod;
            c = c*2%mod;
        }
        return sum;
    }
};