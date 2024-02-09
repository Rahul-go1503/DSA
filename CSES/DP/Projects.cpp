#include<bits/stdc++.h>
using namespace std;

vector<long long> a;
void solve(long long i, vector<long long> &dp,vector<vector<long long>> &v){
    if(i<=0){
        // dp[i] = v[i][2];
        return;
    }
    if(dp[i] != -1) return;
    solve(i-1,dp,v);
    dp[i] = dp[i-1];
    long long j = lower_bound(a.begin(),a.end(),v[i-1][1]) - a.begin();
    if(j>0){
        solve(j-1,dp,v);
        dp[i] = max(dp[i], v[i-1][2] + dp[j-1]);
    }

}
int main(){
    long long n;
    cin>>n;
    vector<vector<long long>> v(n, vector<long long>(3));
    for(long long i=0;i<n;i++){
        cin>>v[i][1]>>v[i][0]>>v[i][2];
    }
    sort(v.begin(),v.end());
    a.push_back(0);
    for(long long i=0;i<n;i++) a.push_back(v[i][0]);
    vector<long long> dp(n+1,-1);
    dp[0] = 0;
    solve(n,dp,v);
    cout<<dp[n]<<endl;
}