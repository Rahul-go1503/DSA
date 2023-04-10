#include <bits/stdc++.h>
using namespace std;
#define  ll long long
#define  ull unsigned long long
#define  ld long double
#define  pb push_back
#define  mp make_pair
#define  PI 3.14159265358979323846
#define  llmin LONG_LONG_MIN
#define  llmax LONG_LONG_MAX
#define  fori(a,b) for(ll i=a;i<b;i++)
#define  forj(a,b) for(ll j=a;j<b;j++)
#define  print(x) for(auto it: x) cout<<it<<" "; cout<<endl;
#define  f first
#define  s second
#define  MOD 1000000007
#define  nitro() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const    int maxn = 2800001;
typedef  vector<long long> vll;
typedef  vector<int> vi;
typedef  vector<vector<ll>> vvll;
typedef  vector<bool> vb;
typedef  pair<ll,ll> pll;
typedef  multiset<ll> ms;
typedef  vector<pair<long,long>> vpll;
typedef  priority_queue<ll> maxpq;
typedef  priority_queue<ll, vector<ll>, greater<ll>> minpq;
vll      isprime(maxn, true);
vvll     edges;
vb       vis;

void prime(){
    isprime[0] = isprime[1] = false;
    for(int i = 2; i*i <= maxn; i++){
        if(isprime[i]){
            for(int j = i*i;j<=maxn;j+=i){
                isprime[j] = false;
            }
        }
    }
}

vll primeFactors(ll n){
    vector<ll> factors;
    while (n % 2 == 0){
        factors.push_back(2);
        n = n / 2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0){
            factors.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)   factors.push_back(n);  return factors;
}

vll allFactors(ll n)/*unsorted*/
{
    vector<ll> factors;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            factors.push_back(i);
            if(n/i!=i) factors.push_back(n/i);
        }
    }
    return factors;
}

ll divCount (ll n) {
    ll t = 1;
    for(int i=2;i<=sqrt(n);i++){
        ll c=0;
        while(n%i==0) {
            n/=i; c++;
        }
        t *= (c+1);
    }
    if(n>1) t*=2; return t;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

ll firstSetBit(ll n) {
    return log2(n & -n) + 1;
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        
    }
}


