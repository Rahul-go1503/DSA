#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1],b[n+1];
        for(int i=1;i<=n;i++) cin>>a[i], cin>>b[i];
        int tm[n+1];
        for(int i=1;i<=n;i++) cin>>tm[i];
        a[0] = b[0] = tm[0] = 0;
        int t = 0;
        for(int i=1;i<n;i++){
            t += a[i] - b[i-1] + tm[i];
            int mn = (b[i] - a[i])/2 + (b[i] - a[i])%2;
            if(t + mn <= b[i]) t = b[i];
            else t += mn;
        }
        cout<<t + a[n] - b[n-1] + tm[n]<<endl;
    }
}


