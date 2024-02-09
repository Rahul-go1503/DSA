#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1));
    for(int i=0;i<=m;i++) dp[0][i] = i;
    for(int i=0;i<=n;i++) dp[i][0] = i;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s1[i]==s2[j]){
                dp[i+1][j+1] = dp[i][j];
            }
            else{
                dp[i+1][j+1] = 1 + min(dp[i][j+1],min(dp[i+1][j],dp[i][j]));
            }
        }
    }
    cout<<dp[n][m]<<endl;
}