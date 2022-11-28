#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],res[n]={};
        for(int i=0;i<n;i++) cin>>a[i];
        int mn = n;
        for(int i=n-1;i>=0;i--){
            mn =  min(mn,i-a[i]);
            if(i>mn) res[i]=1;
        }
        for(int i=0;i<n;i++) cout<<res[i]<<" ";
        cout<<endl;
    }
}


