//#######################################################################//
//TRY TO FEEL THE LOGIC
//HAR EK CONTEST DENA HAI
//agar logic galat bana toh koi na
//ego se connect krne ki jarurat ni hai
//try to overcome tedious observation using brute force
//Read Editorial
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
void     prime() { isprime[0] = isprime[1] = false; for(int i = 2; i*i <= maxn; i++) {if(isprime[i]){for(int j = i*i;j<=maxn;j+=i){ isprime[j] = false;}}}}
vll      primeFactors(ll n){ vector<ll> factors;while (n % 2 == 0) {factors.push_back(2);n = n / 2;    }for (int i = 3; i <= sqrt(n); i = i + 2){while (n % i == 0){factors.push_back(i);n = n / i;}}if (n > 2)   factors.push_back(n);  return factors;}
vll      allFactors(ll n)/*unsorted*/{vector<ll> factors;for(int i=1;i<=sqrt(n);i++){if(n%i==0){factors.push_back(i);if(n/i!=i)factors.push_back(n/i);    }}return factors;}
ll       divCount (ll n) { ll t = 1; for(int i=2;i<=sqrt(n);i++) { ll c=0; while(n%i==0) { n/=i; c++;} t *= (c+1); } if(n>1) t*=2; return t;}
ll       gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
ll       firstSetBit(ll n) { return log2(n & -n) + 1; }
ll       lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
//#######################################################################//
 
 
void solve() {
    int n; 
    cin >> n;
    string s; 
    cin >> s;
    if(s[0] != '9'){
        string res = "";
        fori(0, s.size()) {
            res += '9' - s[i]+'0';
        }
        cout << res << endl;
    }
    else{
        string t;
        string res = "";
        ll carry = 0;
        for(int i = n-1; i >= 0; i--) {
            ll a = s[i] - '0';
            if(a + carry == 0) {
                res += '1';
                carry = 0;
            }
            else if(a + carry == 1) {
                res += '0';
                carry = 0;
            }
            else {
                ll a = s[i] - '0';
                ll b = 11 - a - carry;
                res += (b + '0');
                carry = 1;
            }
        }
        reverse(res.begin(),res.end());
        cout << res << '\n';
         
        
    }
}
 
 
 
//#######################################################################//
int main() 
{
    nitro();
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}
//#######################################################################//
//1. Try to do atleast three ques 1300 - 1600
//2. Solve some more problems
//3. a few more