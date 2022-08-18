/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        long long int ans=0;
        priority_queue<long long, vector<long long>,greater<long long>> pq;
        for(int i=0;i<n;i++) pq.push(arr[i]);
        while(pq.size()>1){
            long long int a = pq.top();
            pq.pop();
            long long int b = pq.top();
            pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        return ans;
        
    }
};