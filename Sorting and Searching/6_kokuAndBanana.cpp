#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(nlogn), SC - O(1)


class Solution {
    bool solve(vector<int>p, int h, int k){
        int n = p.size();
        int i = 0;
        // i = upper_bound(p.begin(),p.end(),k)-p.begin();
        // h-= i;
        while(i<n && h){
            h -= p[i]/k + (p[i++]%k==0? 0 : 1);
            if(h<0) return 0;
        }
        if(i==n) return true;
        else return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(),piles.end());
        int s =1, e = mx;
        // sort(piles.begin(),piles.end());
        while(s<e){
            int mid = s + (e-s)/2;
            bool possible = solve(piles,h,mid);
            if(possible) e = mid;
            else s = mid+1;
        }
        return s;
    }
};