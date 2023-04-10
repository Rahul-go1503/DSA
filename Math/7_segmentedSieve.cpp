#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sieve(ll S, vector<ll> &primes){
    vector<bool> is_Prime(S,true);

    for(ll i=2;i*i<S;i++){
        if(is_Prime[i]){
            // primes.push_back(i);
            for(ll j = i*i;j<S;j+=i) is_Prime[j] = false;
        }
    }
    for(ll i=2;i<S;i++) if(is_Prime[i]) primes.push_back(i);
}
void segmentedSieve(ll n, ll S, vector<ll> &primes,vector<ll> &primes1){
    ll lo = S, hi = 2*S;
    while(lo<n){
        if(hi>n) hi = n;
        vector<bool> is_Prime(S,true);

        for(auto &p : primes){
            ll j = (lo+p-1)/p*p;
            for(;j<hi;j+=p){
                is_Prime[j-lo] = false;
            }
        }
        for(int i=lo;i<hi;i++){
            if(is_Prime[i-lo]) primes1.push_back(i);
        }
        lo += S;
        hi += S;
    }
}
int main(){
    ll n;
    cin>>n;
    ll S = sqrt(n)+1; // we decide 
    vector<ll> primes;
    sieve(S,primes);
    vector<ll> primes1;
    segmentedSieve(n,S,primes,primes1);
    for(auto &p : primes1) cout<<p<<" ";
}