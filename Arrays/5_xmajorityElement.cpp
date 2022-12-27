#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/majority-element/solutions/127412/majority-element/?orderBy=most_votes
methods - 
1 - nested loops - n2,1
2 - mapping - n,n
3 - sorting nlogn,1
4 - Bit manipulation - 
    Time complexity : O(nlog⁡C)
    C is the max absolute value in nums, i.e., 10^5
    in this problem. We enumerate all logC bits for each number in nums.
    Space complexity: O(1)
5 - randomization
6 - divide and conquer - nlogn,logn->stack
7 - boyer-moore majority vote algo - n,1
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int k=n/2+1;
        int ans=nums[0];
        for(int i=0;i<n&&i+k-1<n;i++){
            if(nums[i]==nums[i+k-1]){
                ans=nums[i];
            }
        }
        return ans;
    }

    /******************not understand ~ understood now
     * Boyer-Moore Majority Voting Algorithm
    int majorityElement(int[] num) {

        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;
            
        }
        return major;
    }
    ********************************/
};