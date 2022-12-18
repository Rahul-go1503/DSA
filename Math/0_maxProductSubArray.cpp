#include <bits/stdc++.h>
using namespace std;

// TLE - 187/188 cases pass on Lc, GFGs Accepted
// solved plzz max min approach
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN, prod = 1 , n= nums.size();
        for(int i = 0;i<n;i++){
            prod = 1;
            for(int j = i ;j<n;j++){
                prod *= nums[j];
                mx = max(mx, prod);
                if(prod == 0) break;
            }
        }
        return mx;
    }
};