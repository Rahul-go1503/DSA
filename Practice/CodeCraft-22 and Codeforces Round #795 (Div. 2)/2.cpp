#include <iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            arr.push_back(temp);
        }
        int i=0,j=0;
        int sameCnt=1;
        if(n==1){
            cout<<-1;
            // break;
        }
        else if(arr[n-1]!=arr[n-2]){
        cout<<-1;
        // return 0;
        }else{
        while(i<n){
            for(j=i+1;j<n;j++){
            if(arr[j]==arr[i]) sameCnt++;
            else break;
        }
            if(sameCnt==1){
            cout<<-1;
            // break;
            // return 0;
        }else{
             int k=i;
            while(sameCnt>1){
                cout<<k+2<<" ";
                k++;
                sameCnt--;
            }
            cout<<i+1<<" ";
            i=j;
        }
        }

        }
        cout<<endl;
    }
    return 0;
}

// check later if it is working or not
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1;
            continue;
        }
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        if(arr[n-1]!=arr[n-2]){
            cout<<-1;
            continue;
        }

        int i=0, j=0, sameCnt=1;
        while(i<n){
            for(j=i+1;j<n;j++){
                if(arr[j]==arr[i]) sameCnt++;
                else break;
            }
            if(sameCnt==1) cout<<-1;
            else{
                int k=i;
                while(sameCnt>1){
                    cout<<k+2<<" ";
                    k++;
                    sameCnt--;
                }
            cout<<i+1<<" ";
            i=j;
            }
        }
        cout<<endl;
    }
    return 0;
}