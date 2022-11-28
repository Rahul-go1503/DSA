#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n==1 || m==1){
            cout<<n<<" "<<m<<endl;
            continue;
        }
        if((n==2&&m<=3)||(m==2&&n<=3)||(n==3&&m==3)){
            cout<<2<<" "<<2<<endl;
            continue;
        }
        cout<<n<<" "<<m<<endl;
    }
}


