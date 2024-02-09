#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    int dp[n+1][30];
    for(int i=1;i<=n;i++) cin>>dp[i][0];

    for(int k = 1;k<30;k++){
        for(int i=1;i<=n;i++){
            dp[i][k] = dp[dp[i][k-1]][k-1];
        }
    }
    while(q--){
        int x,k;
        cin>>x>>k;
        int i = 0;
        while(k){
            if(k&1) x = dp[x][i];
            k >>= 1;
            i++; 
        }
        cout<<x<<endl;
    }
}