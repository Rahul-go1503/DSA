#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];

    sort(c.begin(),c.end());
    vector<long long> dp(x+1,x+2);
    dp[0] = 0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-c[j]>=0){
                dp[i] = min(dp[i],1+dp[i-c[j]]);
            }
            else break;
        }
    }
    if(dp[x]!=x+2) cout<<dp[x]<<endl;
    else cout<<-1<<endl;
}