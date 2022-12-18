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
            // int temp;
            cin>>arr[i];
        }
        unordered_map<int,int> mp;
        long long cnt = 0;
        for(int i=0;i<n;i++){
            auto itr = mp.find(arr[i]-i);
            if(itr != mp.end()){
                cnt += itr->second++;
            }else mp[arr[i]-i]++;
        }
        cout<<cnt<<endl;
    }
}