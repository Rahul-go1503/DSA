#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        // cout<<"enter\n";
        int n, m;
        cin>>n;
        int *a =new int[n];
        // int a[n], b[m];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>m;
        int *b =new int[m];

        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        int k=0;
        for(int i=0;i<m;i++){
            k=(k+b[i])%n;

        }
        cout<<a[k]<<endl;
        delete []a;
        delete []b;
    }

}