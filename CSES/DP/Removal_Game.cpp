#include<bits/stdc++.h>
using namespace std;

long long dp[5001][5001][2];
int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(auto &x : v) cin>>x;
    for(int j=0;j<n;j++){
        for(int i=j;i>=0;i--){
            if(i==j){
                dp[i+1][j+1][0] = v[i];
                dp[i+1][j+1][1] = 0;
            }
            else{
                dp[i+1][j+1][0] = max(v[i] + dp[i+2][j+1][1], v[j] + dp[i+1][j][1]);
                dp[i+1][j+1][1] = min(dp[i+2][j+1][0], dp[i+1][j][0]);
            }
        }
    }
    cout<<dp[1][n][0]<<endl;
}