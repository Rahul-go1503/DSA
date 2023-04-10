#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0, curr = 0;
        // curr index tak kitna profit hua
        for(auto x : nums){
            curr = max(x + prev2,prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};