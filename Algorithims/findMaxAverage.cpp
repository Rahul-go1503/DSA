/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double mx = 0;
        double sum = 0;
        int n = nums.size(); int i =0;

        // reach to window
        while(i<k) sum+= nums[i++];

        mx = sum;
        // slide window
        while(i<n){
            sum-= nums[i-k]-nums[i++];
            if(sum>mx) mx = sum;
        }
        return mx/k;
    }
};