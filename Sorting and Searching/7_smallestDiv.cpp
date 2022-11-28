#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(), SC - O()


class Solution {
    bool solve(vector<int>p, int th, int div){
        int n = p.size();
        int sum = 0;
        for(auto &num : p){
            sum += (num+div-1)/div;
        }
        return sum<=th;
    }
public:
    int smallestDivisor(vector<int>& nums, int th) {
        int mx = *max_element(nums.begin(),nums.end());
        int s =1, e = mx;
        while(s<e){
            int mid = s + (e-s)/2;
            bool possible = solve(nums,th,mid);
            if(possible) e = mid;
            else s = mid+1;
        }
        return s;
    }
};