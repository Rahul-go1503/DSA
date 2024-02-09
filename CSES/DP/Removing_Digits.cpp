#include<bits/stdc++.h>
using namespace std;

int getMaxDigit(int i){
    int mx = -1;
    while(i){
        int d = i%10;
        mx = max(mx,d);
        i /= 10;
    }
    return mx;
}

int solve(int n){
    if(n<=9) return 1;
    int d = getMaxDigit(n);
    return 1 + solve(n-d);
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    // vector<int> dp(n+1);
    // for(int i=1;i<=n;i++){
    //     int d = getMaxDigit(i);
    //     dp[i] = 1 + dp[i-d];
    // }
    // cout<<dp[n]<<endl;
}