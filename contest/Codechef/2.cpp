#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int d[n],a[n];
        bool f = false;
        for(int i=0;i<n;i++)cin>>d[i];
        int temp =a[0] = d[0];
        for(int i=1;i<n;i++){
            if(d[i]>temp||d[i]==0){
                temp+=d[i];
                a[i]=temp;
            }else{
                f = true;
                break;
            }
        }
        if(f) cout<<-1<<endl;
        else{
            for(int i=0;i<n;i++) cout<<a[i]<<" ";
            cout<<endl;
        }
    }
}


