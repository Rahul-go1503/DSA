/*********************************************************************************************

Question :
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Notes :
The idea is that we go through the array and gather all zeros on our road.
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        int i=0;
        int j=0;
        while(j<n){
            if(nums[j]){
                nums[i++]=nums[j++];
            }else j++;
        }
        while(i<n){
            nums[i++]=0;
        }
    }
class Solution {
     public: void moveZeroes(vector<int>& nums) {
        int snowBallSize = 0; 
        for (int i=0;i<nums.size();i++){
	        if (nums[i]==0){
                snowBallSize++; 
            }
            else if (snowBallSize > 0) {
	            // int t = nums[i];
	            nums[i-snowBallSize]=nums[i];
	            nums[i]=0;
            }
        }
    }
};
int main()
{
}