#include <bits/stdc++.h>
using namespace std;

/*
 - TC - 2nlog(2n) + n
 - SC - 2n
*/
class Solution {
    // can solve without cmp, reverse store -> price,day
    static bool cmp(vector<int> v1, vector<int> v2){
        return v1[1]<v2[1];
    }
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<vector<int>> stock;
        for(int i=0;i<n;i++) stock.push_back({i+1,price[i]});
        sort(stock.begin(),stock.end(),cmp);
        
        int stks = 0;
        for(int i = 0;k>=0 && i<n;i++){
            int mx = k/stock[i][1];
            if(mx > stock[i][0]){
                mx = stock[i][0];
            }
            stks += mx;
            k -= mx*stock[i][1];
        }
        return stks;
    }
};