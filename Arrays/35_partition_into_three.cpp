#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &B) {
    if(n<3) return 0;
    long long sum = 0;
    // total sum
    for(int i = 0; i<n; i++){
        sum += B[i];
    }
    
    if(sum%3!=0) return 0;
    long long rsum = sum/3, sum_till = 0;
    int cnt[n] = {}; //upto ith idx how many rsum we encountered
    sum_till += B[0];
    if(sum_till==rsum) cnt[0] = 1;
    for(int i=1;i<n;i++){
        sum_till += B[i];
        cnt[i] = cnt[i-1];
        if(sum_till==rsum) cnt[i]++;
    }
    sum_till = 0;
    int res = 0;
    for(int i = n-1; i>=2; i--){
        sum_till += B[i];
        if(sum_till==rsum) res += cnt[i-2];
    }
    return res;
}

// Function to count the no of ways 
int countways(int n,vector<int>& a) 
{
    int pre[n];
    pre[0]=a[0];
    for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
    if(pre[n-1]%3) return 0;
    int req=pre[n-1]/3;
    int cnt=0;
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(pre[i]==2*req) ans+=cnt; // updating ans
        cnt+=(pre[i]==req); // updating cnt only
    }
    return ans;
} 
int solve(int A, vector<int> &B) {
    assert(A>=1 && A<=100000 && A==B.size());
    for(int a:B)assert(a>=-1000000000 && a<=1000000000);
    return countways(A,B);
}

