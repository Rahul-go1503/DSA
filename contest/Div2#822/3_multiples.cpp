#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string t;
        cin>>t;
        long long cost=0;
        for(int i=0;i<n;i++){
            if(t[i]=='1') continue;
            int k=i,m=2;
            while(k<n && (t[k]=='0'||t[k]=='2')){
                while(k<n && t[k]=='2') k = (i+1)*m++ -1;
                if(k>=n || t[k]=='1') break;
                cost+=i+1;
                t[k]='2'; 
                k = (i+1)*m++ -1;
            }
        }
        cout<<cost<<endl;
    }
}


