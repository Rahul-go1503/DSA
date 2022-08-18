/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O()
	Space Complexity: O()

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Array Kadane's Algorithm
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum = max(sum+nums[i],nums[i]);
            mx = max(mx,sum);
        }
        return mx;
    }
};