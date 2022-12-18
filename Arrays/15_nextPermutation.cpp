/*********************************************************************************************

Question :


Notes :
Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
Find the largest index l > k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array nums[k + 1:].
**********************************************************************************************/

/*
	Time Complexity: O(n+n+n))
	Space Complexity: O(1)

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
                        // sort(nums.begin()+i+1,nums.end());
                        // reverse rem elem
                        reverse(nums.begin()+i+1, nums.end());
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

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find from the smallest k such that nums[k - 1] < nums[k].
        int k;
        for (k = nums.size() - 1; k > 0 && nums[k - 1] >= nums[k]; k--);
        
        // k == 0 means the sequence itself is non-increasing. Reverse it.
        if (k > 0) {
            // Find the index i such that nums[i] > nums[k-1], i in [k, n-1].
            int i;
            for (i = nums.size() - 1; nums[i] <= nums[k - 1]; i--);
            
            swap(nums[k - 1], nums[i]);
        }
        reverse(nums.begin() + k, nums.end());
    }
};