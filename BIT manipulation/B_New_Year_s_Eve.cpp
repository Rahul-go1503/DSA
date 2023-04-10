#include <bits/stdc++.h>
using namespace std;
 
#define PI 3.1415926535897932384626
#define mod 1000000007
#define fo(i, st, end) for (int i = st; i < end; i++)
#define foeq(i, st, end) for (int i = st; i <= end; i++)
#define revfo(i, st, end) for (int i = st; i > end; i--)
#define revfoeq(i, st, end) for (int i = st; i >= end; i--)
#define foit(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define clr(x) memset(x, false, sizeof(x))
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define deb(x) cout << #x << "=" << x << endl
 
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pllll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pllll> vpllll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

ll solve(){
    ll n,k;
    cin>>n>>k;
    if(k==1) return n;
    // int msb = log2(n);
    int msb = 0;
    // deb(log2(0));
    // deb(log2(1));
    // deb(log2(2));
    // deb(log2(288230376151711743));
    while(n>0) n >>=1 ,msb++;
    deb(msb);
    return (ll)pow(2,msb) - 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cout<<solve()<<endl;

    return 0;
}