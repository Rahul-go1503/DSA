#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<1<<endl;
        if(n==1) continue;
        cout<<1<<" "<<1<<endl;
        if(n==2) continue;
        for(int i=3;i<=n;i++){
            cout<<1<<" ";
            for(int j=2;j<i;j++){
                cout<<0<<" ";
            }
            cout<<1<<endl;
        }
    }
}


