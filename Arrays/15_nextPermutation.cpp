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
    void nextPermutation(vector<int>& nums) {
        int j= nums.size()-1;
        for(int i =j-1;i>=0;i--){
            // find first smaller element from back
            if(nums[i]<nums[i+1]){
                for(int k=j;k>i;k--){
                    // swap with min of largest elem
                    if(nums[k]>nums[i]){
                        swap(nums[i],nums[k]);
                        // sort rem elem
                        sort(nums.begin()+i+1,nums.end());
                        return;
                    }
                }
                return;
            }
        }
        // if here means no smaller elem so reverse
        reverse(nums.begin(),nums.end());
        return;
    }
};