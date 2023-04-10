#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// void solve()
ll solve(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll tot_sum = 0, curr_pre = 0, curr_suff = 0, pref_sum = LLONG_MIN, suff_sum = LLONG_MIN;
    for(int i=0;i<n;i++){
        tot_sum += a[i];
        curr_pre += a[i];
        curr_suff += a[n-1-i];
        pref_sum = max(pref_sum,curr_pre);
        suff_sum = max(suff_sum,curr_suff);
    }
    ll sum = 0;
    ll ksum = LLONG_MIN;
    for(int i=0;i<n;i++){
        sum += a[i];
        ksum = max(ksum,sum);
        if(sum<0) sum = 0;
    }
    if(k==1) return ksum;
    if(tot_sum<0) return max(pref_sum + suff_sum,ksum);
    return pref_sum + suff_sum + (k-2)*tot_sum;
}
int main(){
    int t;
    cin>>t;
    while(t--)
    // solve();
    cout<<solve()<<endl;
}