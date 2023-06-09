#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O()
	Space Complexity: O()
*/

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