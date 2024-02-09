#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6;
int main(){
    vector<vector<long long>> dp(N + 1,vector<long long>(2));
    dp[1][1] = 1, dp[1][0] = 1;
    for(int i=2;i<=N;i++){
        long long x = dp[i-1][0];
        (dp[i][0] = x*4 + dp[i-1][1]) %= mod;
        (dp[i][1] = dp[i-1][1]*2 + x) %= mod;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n][0] + dp[n][1])%mod<<endl;
    }
}