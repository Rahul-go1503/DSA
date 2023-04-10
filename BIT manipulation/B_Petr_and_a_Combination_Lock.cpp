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

bool recur(int a[],int i,int n,int sum){
    if(i==n && sum == 0 || i==n && sum>=360 && sum%360 == 0) return 1;
    if(i==n) return 0;

    // deb(sum);
    if(recur(a,i+1,n,sum + a[i])) return 1;
    return recur(a,i+1,n,sum - a[i]);
}

string solve(){
    int n;
    cin>>n;
    int a[n];
    fo(i,0,n) cin>>a[i];
    // deb(a[0]);
    if(recur(a,0,n,0)) return "YES";
    else return "NO";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<solve()<<endl;

    return 0;
}