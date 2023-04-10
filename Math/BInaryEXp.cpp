#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int binExpRec(int a,int b){
    if(b==0) return 1;
    int res = binExpRec(a,b/2);
    if(b&1) return a*1LL*(res*1LL*res%mod)%mod;
    return res*1LL*res%mod;
}

int binExpIter(ll a,ll b){
    int ans = 1;
    a %= mod;
    b %= mod;
    while(b){
        if(b&1) ans = ans*a%mod;
        a =a*a%mod;
        b >>= 1;
    }
    return ans;
}

const ll llmod = 1e18;
ll binMul(ll a,ll b);
ll larBinExpIter(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = binMul(ans,a);
        a = binMul(a,a);
        b >>= 1;
    }
    return ans;
}

ll binMul(ll a, ll b){
    ll ans = 0;
    while(b){
        if(b&1) ans = (ans + a)%llmod;
        a = (a + a)%llmod;
        b >>= 1;
    }
    return ans;
} 
int main(){
    int a,b;
    cin>>a>>b;
    cout<<binExpRec(a,b)<<endl;
    cout<<binExpIter(a,b)<<endl;
}