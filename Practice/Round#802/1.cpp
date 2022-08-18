/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        long long int cost=0;
        for(int i=1;i<=m;i++){
            cost+=i;
        }
        for(int j=2;j<=n;j++){
            cost+=(j-1)*m+m;
        }
        cout<<cost<<endl;
    }
}