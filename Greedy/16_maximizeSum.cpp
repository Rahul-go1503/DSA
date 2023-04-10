#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        long long sum = 0;
        int i = 0;
        while(i<n && k && a[i]<0) sum -= a[i++],k--;
        k = k%2 ? 1 : 0;
        if(k){
            if(i==n) sum += 2*a[n-1];
            else sum -= a[i++];
            k--;
        }
        while(i<n) sum += a[i++];
        return sum;
    }
};