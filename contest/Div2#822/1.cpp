#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int mn = INT_MAX;
        for(int i=2;i<n;i++){
            mn = min(mn, arr[i]-arr[i-2]);
        }
        cout<<mn<<endl;
    }
}