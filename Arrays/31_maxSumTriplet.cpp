#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    
    for(int i=0;i<n;i++) cin>>a[i];
    long long res = 0;
    for(int i=0;i<n;i++){
        int f = a[i];
        int si = upper_bound(a.begin()+i,a.end(),f)-a.begin();
        cout<<i+1<<" : "<<si<<endl;
        if(si==n) continue;
        int s = a[si];
        int ti = upper_bound(a.begin()+si+1,a.end(),s) - a.begin();
        if(ti==n) continue;
        // cout<<res<<endl;
        // cout<<i+1<<" "<<si+1<<" "<<ti+1<<endl;
        res = max(res,f+s + 0LL + a[ti]);
    }
    return res;
}
