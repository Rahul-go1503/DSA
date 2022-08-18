//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int i, int n, int *arr,int sum,int total){
        if(i==n && sum==total){
            return 1;
        }
        for(int k=i;k<n&&sum<total;k++){
            sum+=arr[k];
            int temp = solve(k+1,n,arr,sum,total);
            sum-=arr[k];
            if(temp) return 1;
        }
        return 0;
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum =0;
        for(int i=0;i<N;i++) sum+=arr[i];
        if(sum%2!=0) return 0;
        return solve(0,N,arr,0,sum/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends