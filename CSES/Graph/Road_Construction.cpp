#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> SIZE(N,1), par(N);
int n;
int findPar(int u){
    if(par[u] == u) return u;
    return par[u] = findPar(par[u]);
}

void Union(int u, int v){
    int pu = findPar(u);
    int pv = findPar(v);
    if(pu==pv) return;
    n--;
    if(SIZE[pu]<=SIZE[pv]){
        SIZE[pv] += SIZE[pu];
        par[pu] = pv;
    }
    else{
        SIZE[pu] += SIZE[pv];
        par[pv] = pu;
    }
}
int main(){
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) par[i] = i;
    vector<int> res1(m);
    vector<int> res(m);
    int mx = 0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        Union(u,v);
        int t = SIZE[findPar(u)];
        mx = max(mx,t);
        res[i] = mx;
        res1[i] = n;
    }
    for(int i=0;i<m;i++) cout<<res1[i]<<" "<<res[i]<<endl;
}