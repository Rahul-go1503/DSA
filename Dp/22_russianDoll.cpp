#include<bits/stdc++.h>
using namespace std;

// width incre , length dec
bool cmp (vector<int> &a,vector<int>& b){
    if(a[0] == b[0]) return a[1]>b[1];
    return a[0] < b[0];
}

// standard lis in 2D
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end(),cmp);
        vector<int> sub;
        sub.push_back(arr[0][1]);
        for(int i = 1;i<n;i++){
            if(arr[i][1]>sub.back()) sub.push_back(arr[i][1]);
            else{
                int idx = lower_bound(sub.begin(),sub.end(),arr[i][1]) - sub.begin();
                sub[idx] = arr[i][1];
            }
        }
        return sub.size();
    }
};