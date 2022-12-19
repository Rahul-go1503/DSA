#include <bits/stdc++.h>
using namespace std;

/*
 - Idea : we have to calculate Length of segment already in increasing order
*/
class Solution{
public:
    int sortingCost(int n, int arr[]){
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]] = i;
        }
        
        int mxStreak = 0, i = 1;
        while(i<=n){
            int curr = 1;
            i++;
            while(mp[i]>mp[i-1]){
                i++;
                curr++;
            }
            mxStreak = max(mxStreak,curr);
        }
        return n - mxStreak;
    }
};

class Solution{
public:
    int sortingCost(int N, int arr[]){
        int hash[N+1] = {0}; // counting the increasing length on each index... initially all have 0
        for(int i = 0;i < N;i++){
            int k = arr[i];
            hash[k] = hash[k-1] + 1; // if value - 1 not seen before means hash[k-1] ==0 else add prev calculate value plus 1
        }
        int maxi = 0;
        for(int i = 0;i <= N;i++)
            maxi = max(maxi, hash[i]);
        return (N - maxi);
    }
};