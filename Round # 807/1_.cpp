/*********************************************************************************************

Question :


Notes :
3
3 6
1 3 9 10 12 16
3 1
2 5 2 2 2 5
1 2
8 6

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define  nitro() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    nitro();
    int t;
    cin>>t;
    while(t--){
        int n,x,h;
        cin>>n>>x;
        string ans="YES";
        vector<int> v(2*n);
        for(int i=0;i<2*n;i++){
            cin>>h;
            v[i]=h;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(v[i+n]-v[i]<x){
                ans="NO";
                break;
            }
        }
        if(ans!="NO") cout<<ans<<endl;
        else cout<<ans<<endl;
    }
}