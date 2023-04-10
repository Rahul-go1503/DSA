#include <bits/stdc++.h>
using namespace std;

/*
 - TC - nlogn, SC- 1
*/
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        int candy = n/(k+1) + (n%(k+1) ? 1 : 0);

        sort(candies,candies + n);
        int mn = 0, mx = 0;
        for(int i=0;i<candy;i++){
            mn += candies[i];
            mx += candies[n-1-i];
        }
        return {mn,mx};
    }
};