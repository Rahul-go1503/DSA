#include <bits/stdc++.h>
using namespace std;

/*
 - Spoj
 - wrong solution
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int w,h,n;
        cin>>w>>h>>n;
        int x[n+2], y[n+2];
        x[0] = y[0] = 0;
        for(int i=1;i<n+1;i++){
            cin>>x[i];
            cin>>y[i];
        }
        x[n+1] = w+1, y[n+1] = h+1;

        sort(x,x+n+2), sort(y,y+n+2);
        int rw = 0,rh = 0;
        for(int i=0;i<n+2;i++){
            // cout<<x[i]<<" "<<y[i]<<endl;
            rw = max(rw,x[i]-x[i-1]-1);
            rh = max(rh,y[i]-y[i-1]-1);
        }
        // cout<<rw<<" "<<rh<<endl;
        cout<<rw*rh<<endl;
    }
}