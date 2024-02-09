#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<long long>> dp(n+1,vector<long long>(m+2));
    if(a[0]) dp[1][a[0]] = 1;
    else{
        for(int i=1;i<=m;i++) dp[1][i] = 1;
    }
    long long ans = 0;
    for(int i=1;i<n;i++){
        if(a[i]){
            dp[i+1][a[i]] = (dp[i][a[i]-1] + dp[i][a[i]] + dp[i][a[i]+1])%mod;
        }
        else{
            for(int j=1;j<=m;j++){
                dp[i+1][j] = (dp[i][j-1] + dp[i][j] + dp[i][j+1])%mod;
            }
        }
    }
    for(int i=1;i<=m;i++) (ans += dp[n][i]) %= mod;
    cout<<ans<<endl;
}