#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[1000001][101];
int main(){
    int n, x;
    cin>>n>>x;
    vector<int> c(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    dp[0][0] = 1;
    for(int i=0;i<=x;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = dp[i][j-1];
            if(c[j] <= i) dp[i][j] = (dp[i][j] + 0LL +  dp[i-c[j]][j])%mod;
        }
    }
    cout<<dp[x][n];
}