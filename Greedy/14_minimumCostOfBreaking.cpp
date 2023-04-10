#include <bits/stdc++.h>
using namespace std;

/*
 - failed at 3rd case while working fine in custom input
 - Test case :
 5 9
5 18 6 3 6 1 2 2
6 11 18 15

- TC - nlogn + mlogm
- sc -1
*/

class Solution {
public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n){
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
        int hc = 1, vc = 1, i = 0, j = 0, cost = 0;
        
        while(i<m && j<n){
            if(x[i]>y[j]){
                cost += vc*x[i++];
                hc++;
            }else{
                cost += hc*y[j++];
                vc++;
            }
        }
        // cout<<i<<" "<<j<<" "<<hc<<" "<<vc<<endl;
        while(i<m){
            cost += vc*x[i++];
        }
        while(j<n){
            cost += hc*y[j++];
        }
        return cost;
    }
};