#include <bits/stdc++.h>
using namespace std;
 
#define PI 3.1415926535897932384626
#define mod 1000000007
#define fo(i, st, end) for (int i = st; i < end; i++)
#define foeq(i, st, end) for (int i = st; i <= end; i++)
#define revfo(i, st, end) for (int i = st; i > end; i--)
#define revfoeq(i, st, end) for (int i = st; i >= end; i--)
#define foit(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define revfoit(it, a) for (auto it = a.rbegin(); it != a.rend(); it++)
#define clr(x) memset(x, false, sizeof(x))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define sortrall(x) sort(rall(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define nl "\n"
#define deb(x) cout << #x << " = " << x << endl
 

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pllll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pllll> vpllll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

int till = 0;
bool dfs(int u, int p, vi adj[], vi &vis, stack<int> &res){
    if(vis[u]==1) return false;
    if(vis[u]==2){
        res.push(u);
        till = u;
        return true;
    };
    vis[u] = 2;
    bool fl = false;
    for(auto &v : adj[u]){
        if(v!=p) fl = dfs(v,u,adj,vis,res);
        if(fl){
            break;
        }
    }
    vis[u] = 1;
    if(till && till != u){
        res.push(u);

    }
    else if(till==u) res.push(u), till = 0;
    return fl;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vi adj[n+1], vis(n+1);
    vpii edges(m);
    fo(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        // edges[i] = {u,v};
    }
    stack<int> res;
    bool fl = false;
    fo(i,1,n+1){
        fl = dfs(i,-1,adj,vis,res);
        if(fl) break;
    }
    if(fl==false){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<res.size()<<endl;
    while(res.size()){
        cout<<res.top()<<" ";
        res.pop();
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    // int t; cin>>t;
    // while(t--)
    solve();
    // cout<<solve()<<nl;

    return 0;
}