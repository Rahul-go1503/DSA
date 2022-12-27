#include <bits/stdc++.h>
using namespace std;
/*
- we have to find ai, aj such that i<j and (ai + aj)%k ==0
- it means ai+aj == nk; and if it is guaranteed ai and aj are not multiple of k then we have to just find whether we have seen k- a[i]
  previously or not
- we are storing freq of a%k
- Edge case : what if one number is completely divided by k or ai == 0 ?
*/
class Solution
{
    public:
    long long countKdivPairs(int a[], int n, int k)
    {
        unordered_map<int,int> freq;
        long long cnt = 0;
        for(int i=0;i<n;i++){
            if(a[i]%k==0) cnt += freq[0];
            else if(freq.count(k-a[i]%k)) cnt += freq[k-a[i]%k];
            freq[a[i]%k]++;
        }
        return cnt;
    }
};

// O(n),O(k) single pass
class Solution
{
    public:
    long long countKdivPairs(int a[], int n, int k)
    {
        int freq[k] = {0};
        long long cnt = 0;
        for(int i=0;i<n;i++){
            if(a[i]%k==0) cnt += freq[0];
            else cnt += freq[k-a[i]%k];
            freq[a[i]%k]++;
        }
        return cnt;
    }
};