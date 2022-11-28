#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int i = k-2;
        int j = k;
        if(i<0 || j==n){
            cout<<"YES"<<endl;
            continue;
        }
        while(i>=0 && j<n){
            if(a[k-1]+a[j]<0 && a[k-1]+a[i]<0){
                cout<<"NO"<<endl;
                break;
            }else if(a[k-1]+a[j]>a[k-1]+a[i]){
                a[k-1]+=a[j++];
            }else if(a[k-1]+a[j]<a[k-1]+a[i]){
                a[k-1]+=a[i--];
            }else{
                while(i>=0 && j<n && a[i]==a[j] && a[k-1]+a[i]>=0){
                    a[k-1]+=a[i];
                    i--;
                    j++;
                };
            }
        }
        if(i<0 || j==n){
            cout<<"YES"<<endl;
        }
    }
}

// 5 2
// -2 2 -2 -3 -3
