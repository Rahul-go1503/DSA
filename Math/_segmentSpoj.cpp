#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout<<#x<<" : "<<x<<endl;


// 1 10
void solve(){
    int m,n;
    cin>>m>>n;
    vector<int> primes;
    int sz = sqrt(n) + 1; // 4
    vector<int> mark(sz,1);
    for(int i=2;i*i<=n;i++){ // 2 3
        if(mark[i]){
            for(int j = i*i;j<=sz;j += i) mark[j] = 0;
        }
    }
    // 2 3
    // for(int i = 2;i<sz;i++) if(mark[i]) primes.push_back(i), cout<<i<<endl; // 2 3
    for(int i = 2;i<sz;i++){
        if(mark[i]){
            primes.push_back(i);
            if(i>=m) cout<<i<<endl; // 2 3
        }
    }


    // 4 8
    int lo = max(m,sz);
    int hi = n;


    // while(lo<n){
        // if(hi>=n) hi = n + 1;
        vector<int> res(hi-lo+1,1); // size = 4
        for(auto &p : primes){ // for 2 3
            // deb(p);
            int j = (lo + p- 1)/p * p; // 2 -> 4, 3 -> 6

            for(;j<=hi; j+= p){ // 4 5 6 7
                res[j-lo] = 0; // 4 6 ko mark
            }
        }
        // 4 5 6 7
        for(int i = lo;i<=hi;i++) if(res[i-lo]) cout<<i<<endl;
        // 8 12 , 12 16
        // lo += sz, hi += sz;
    // }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)
    solve();
}